cmake_minimum_required(VERSION 3.10)
project(lab5_my_string)

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
add_executable(my_string_app
        main.cpp
        ${SOURCES}
        src/MyString.cpp
        src/MyString.h
        src/exception/MyStringException.h
        src/iterator/MyStringIterator.cpp
        src/iterator/MyStringIterator.h
)

target_include_directories(my_string_app PRIVATE
        src
)

# Tests

find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TEST_SOURCES "tests/*.cpp")
if (TEST_SOURCES)
    add_executable(my_string_tests ${TEST_SOURCES} ${SOURCES}
            tests/OperatorOverloadingTests.cpp
            tests/IteratorTests.cpp)
    target_include_directories(my_string_tests PRIVATE
            src
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*/*
    )

    target_link_libraries(my_string_tests PRIVATE GTest::GTest GTest::Main)
    enable_testing()
    gtest_discover_tests(my_string_tests)

    target_link_libraries(my_string_tests PRIVATE
            gtest_main
    )

    enable_testing()
    gtest_discover_tests(my_string_tests)
endif ()
