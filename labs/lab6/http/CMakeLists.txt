cmake_minimum_required(VERSION 3.10)
project(lab6_http)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
        "src/*.cpp"
        "src/*/*.cpp"
        "src/*/*/*.cpp"
        "src/*/*/*/*.cpp"
)

list(REMOVE_ITEM SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
)

# Основное приложение
add_executable(http_app
        main.cpp
        ${SOURCES}
        src/httpUrl/HttpUrl.cpp
        src/httpUrl/HttpUrl.h
        src/exception/UrlParsingError.cpp
        src/exception/UrlParsingError.h
        tests/TestHttp.cpp
)

target_include_directories(http_app PRIVATE
        src
)

# Tests

find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TEST_SOURCES "tests/*.cpp")
if (TEST_SOURCES)
    add_executable(http_tests ${TEST_SOURCES} ${SOURCES})
    target_include_directories(http_tests PRIVATE
            src
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*/*
    )

    target_link_libraries(http_tests PRIVATE GTest::GTest GTest::Main)
    enable_testing()
    gtest_discover_tests(http_tests)

    target_link_libraries(http_tests PRIVATE
            gtest_main
    )

    enable_testing()
    gtest_discover_tests(http_tests)
endif ()
