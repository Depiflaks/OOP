//
// Created by smmm on 14.05.2025.
//
// test_HttpUrl.cpp

#include "httpUrl/HttpUrl.h"
#include "exception/UrlParsingError.h"

#include <gtest/gtest.h>

using namespace std;

// --- Проверки корректных URL строковых конструктором ---

TEST(HttpUrl_StringConstructor, ParsesSimpleHttpUrl) {
    HttpUrl url("http://example.com/index.html");
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTP);
    EXPECT_EQ(url.GetDomain(), "example.com");
    EXPECT_EQ(url.GetDocument(), "/index.html");
    EXPECT_EQ(url.GetPort(), 80u);
    EXPECT_EQ(url.GetURL(), "http://example.com/index.html");
}

TEST(HttpUrl_StringConstructor, ParsesHttpsUrlWithDefaultPort) {
    HttpUrl url("https://Example.COM/path");
    // протокол и домен в нижнем регистре
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(url.GetDomain(), "example.com");
    EXPECT_EQ(url.GetDocument(), "/path");
    EXPECT_EQ(url.GetPort(), 443u);
    EXPECT_EQ(url.GetURL(), "https://example.com/path");
}

TEST(HttpUrl_StringConstructor, ParsesUrlWithCustomPort) {
    HttpUrl url("https://example.com:8443/secure");
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(url.GetDomain(), "example.com");
    EXPECT_EQ(url.GetDocument(), "/secure");
    EXPECT_EQ(url.GetPort(), 8443u);
    EXPECT_EQ(url.GetURL(), "https://example.com:8443/secure");
}

// --- Проверки конструкторов по параметрам ---

TEST(HttpUrl_ParamsConstructor, DefaultHttpPortInserted) {
    HttpUrl url("myhost.local", "/doc/page.html", Protocol::HTTP);
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTP);
    EXPECT_EQ(url.GetDomain(), "myhost.local");
    EXPECT_EQ(url.GetDocument(), "/doc/page.html");
    EXPECT_EQ(url.GetPort(), 80u);
    EXPECT_EQ(url.GetURL(), "http://myhost.local/doc/page.html");
}

TEST(HttpUrl_ParamsConstructor, AddsLeadingSlashToDocument) {
    HttpUrl url("host", "resource", Protocol::HTTPS);
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(url.GetDomain(), "host");
    EXPECT_EQ(url.GetDocument(), "/resource");
    EXPECT_EQ(url.GetPort(), 443u);
    EXPECT_EQ(url.GetURL(), "https://host/resource");
}

TEST(HttpUrl_ParamsWithPortConstructor, UsesGivenPort) {
    HttpUrl url("host", "/path", Protocol::HTTP, 8080);
    EXPECT_EQ(url.GetProtocol(), Protocol::HTTP);
    EXPECT_EQ(url.GetDomain(), "host");
    EXPECT_EQ(url.GetDocument(), "/path");
    EXPECT_EQ(url.GetPort(), 8080u);
    EXPECT_EQ(url.GetURL(), "http://host:8080/path");
}

// --- Проверка выбрасывания исключений ---

TEST(HttpUrl_StringConstructor, ThrowsOnBadPattern) {
    EXPECT_THROW({
        HttpUrl url("not-a-valid-url");
    }, HttpPatternMissmatchError);
}

TEST(HttpUrl_StringConstructor, ThrowsOnUnknownProtocol) {
    EXPECT_THROW({
        HttpUrl url("ftp://example.com/");
    }, UnknownProtocolError);
}

TEST(HttpUrl_StringConstructor, ThrowsOnPortOutOfRange) {
    EXPECT_THROW({
        HttpUrl url("http://example.com:99999/");
    }, PortOutOfRangeError);
}

TEST(HttpUrl_ParamsConstructor, ThrowsOnEmptyDomain) {
    EXPECT_THROW({
        HttpUrl url("", "/doc", Protocol::HTTP);
    }, std::invalid_argument);
}

TEST(HttpUrl_ParamsWithPortConstructor, ThrowsOnZeroPort) {
    EXPECT_THROW({
        HttpUrl url("example.com", "/doc", Protocol::HTTP, 0);
    }, std::invalid_argument);
}

TEST(HttpUrl_ParamsWithPortConstructor, ThrowsOnPortTooLarge) {
    EXPECT_THROW({
        HttpUrl url("example.com", "/doc", Protocol::HTTP, 70000);
    }, std::invalid_argument);
}

// --- Граничные случаи ---

TEST(HttpUrl_StringConstructor, RootDocumentDefault) {
    HttpUrl url("http://example.com");
    EXPECT_EQ(url.GetDocument(), "/");
    EXPECT_EQ(url.GetURL(), "http://example.com/");
}

