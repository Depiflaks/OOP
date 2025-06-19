cmake_minimum_required(VERSION 3.10)
project(exam)

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
add_executable(exam_app
        main.cpp
        ${SOURCES}
)

target_include_directories(exam_app PRIVATE
        src
)

# Tests

find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TEST_SOURCES "tests/*.cpp")
if (TEST_SOURCES)
    add_executable(exam_tests ${TEST_SOURCES} ${SOURCES})
    target_include_directories(exam_tests PRIVATE
            src
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*/*
    )

    target_link_libraries(exam_tests PRIVATE GTest::GTest GTest::Main)
    enable_testing()
    gtest_discover_tests(exam_tests)

    target_link_libraries(exam_tests PRIVATE
            gtest_main
    )

    enable_testing()
    gtest_discover_tests(exam_tests)
endif ()
