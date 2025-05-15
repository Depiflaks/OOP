cmake_minimum_required(VERSION 3.10)
project(lab3_tv_set)

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
add_executable(tv_set_app
        main.cpp
#        ${SOURCES}
        src/TVSet.cpp
        src/TVSet.h
        src/exception/TVSetError.cpp
        src/exception/TVSetError.h
)

target_include_directories(tv_set_app PRIVATE
        src
)

# Tests

find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TEST_SOURCES "tests/*.cpp")
if (TEST_SOURCES)
    add_executable(tv_set_tests ${TEST_SOURCES} ${SOURCES})
    target_include_directories(tv_set_tests PRIVATE
            src
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*/*
    )

    target_link_libraries(tv_set_tests PRIVATE GTest::GTest GTest::Main)
    enable_testing()
    gtest_discover_tests(tv_set_tests)

    target_link_libraries(tv_set_tests PRIVATE
            gtest_main
    )

    enable_testing()
    gtest_discover_tests(tv_set_tests)
endif ()
