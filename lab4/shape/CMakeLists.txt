cmake_minimum_required(VERSION 3.10)
project(lab4_shape)

set(CMAKE_CXX_STANDARD 20)


if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

file(GLOB_RECURSE SOURCES
        "src/*.cpp"
        "src/*/*.cpp"
        "src/*/*/*.cpp"
        "src/*/*/*/*.cpp"
)

list(REMOVE_ITEM SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
)

add_executable(shape_app
        main.cpp
        ${SOURCES}
        src/openGl/OpenGlController.cpp
        src/openGl/OpenGlController.h
)

target_link_libraries(shape_app
        PRIVATE
        OpenGL::GL
        glfw
)

target_include_directories(shape_app PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Tests

find_package(GTest REQUIRED)
include(GoogleTest)

file(GLOB TEST_SOURCES "tests/*.cpp")
if (TEST_SOURCES)
    add_executable(shape_tests ${TEST_SOURCES} ${SOURCES})
    target_include_directories(shape_tests PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*/*
    )

    target_link_libraries(shape_tests PRIVATE GTest::GTest GTest::Main)
    enable_testing()
    gtest_discover_tests(shape_tests)

    target_link_libraries(shape_tests PRIVATE
            gtest_main
    )

    enable_testing()
    gtest_discover_tests(shape_tests)
endif ()
