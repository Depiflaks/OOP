cmake_minimum_required(VERSION 3.10)
project(lab5_rational)

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
add_executable(rational_app
        main.cpp
        ${SOURCES}
        tests/TestCRational.cpp
)

target_include_directories(rational_app PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Tests

find_package(GTest REQUIRED)
include(GoogleTest)


file(GLOB TEST_SOURCES "tests/*.cpp")
if (TEST_SOURCES)
    add_executable(rational_tests ${TEST_SOURCES})
    target_include_directories(rational_tests PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

    target_link_libraries(rational_tests PRIVATE GTest::GTest GTest::Main)
    enable_testing()
    gtest_discover_tests(rational_tests)

    target_link_libraries(rational_tests PRIVATE
            gtest_main
    )

    enable_testing()
    gtest_discover_tests(rational_tests)
    #    target_link_libraries(rational_tests PRIVATE rational_app)
endif ()