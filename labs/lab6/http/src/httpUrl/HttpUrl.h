//
// Created by smmm on 13.05.2025.
//

#ifndef HTTP_URL_H
#define HTTP_URL_H

#include "exception/UrlParsingError.h"

#include <regex>
#include <string>

enum class Protocol
{
	HTTP,
	HTTPS
};

constexpr std::string k_http = "http";
constexpr std::string k_https = "https";

inline std::string ProtocolToString(const Protocol protocol)
{
	switch (protocol)
	{
	case Protocol::HTTP:
		return k_http;
	case Protocol::HTTPS:
	default:
		return k_https;
	}
}

inline Protocol StringToProtocol(const std::string& protocol)
{
	if (protocol == k_http)
		return Protocol::HTTP;
	if (protocol == k_https)
		return Protocol::HTTPS;
	throw UnknownProtocolError(protocol);
}

class HttpUrl
{
public:
	// выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
	// выбрасывает исключение CUrlParsingError, содержащее текстовое описание ошибки
	explicit HttpUrl(std::string const& url);

	/* инициализирует URL на основе переданных параметров.
		При недопустимости входных параметров выбрасывает исключение
		std::invalid_argument
		Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	HttpUrl(
		std::string domain,
		std::string document,
		Protocol protocol = Protocol::HTTP);

	/* инициализирует URL на основе переданных параметров.
		При недопустимости входных параметров выбрасывает исключение
		std::invalid_argument
		Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	HttpUrl(
		std::string domain,
		std::string document,
		Protocol protocol,
		int port);

	// возвращает строковое представление URL-а. Порт, являющийся стандартным для
	// выбранного протокола (80 для http и 443 для https) в эту строку
	// не должен включаться
	[[nodiscard]] std::string GetURL() const;

	// возвращает доменное имя
	[[nodiscard]] std::string GetDomain() const;

	/*
		Возвращает имя документа. Примеры:
			/
			/index.html
			/images/photo.jpg
	*/
	[[nodiscard]] std::string GetDocument() const;

	// возвращает тип протокола
	[[nodiscard]] Protocol GetProtocol() const;

	// возвращает номер порта
	[[nodiscard]] unsigned short GetPort() const;

private:
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;

	const unsigned short k_httpPort{ 80 };
	const unsigned short k_httpsPort{ 443 };

	const char* k_schemeSeparator = "://";

	const unsigned short k_minPort{ 1 };
	const unsigned short k_maxPort{ 65535 };

	const std::regex k_urlRegex{ R"(^(\w+)://([^/:?#]+)(?::(\d+))?([^?#]*)$)",
		std::regex::icase };

	void SetStandardPort();
	static std::string FormatDocument(std::string document);

	void CollectUrl();
	void CheckPort(int port) const;

	static std::string ToLower(std::string str);
};

#endif // HTTP_URL_H
