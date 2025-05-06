cmake_minimum_required(VERSION 3.10)
project(lab4_shape)

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
add_executable(shape_app
        main.cpp
        ${SOURCES}
        src/point/Point.cpp
        src/point/Point.h
        src/shape/IShape.cpp
        src/shape/IShape.h
        src/Canvas/ICanvas.cpp
        src/Canvas/ICanvas.h
        src/shape/drawable/ICanvasDrawable.cpp
        src/shape/drawable/ICanvasDrawable.h
        src/shape/lineSegment/LineSegment.cpp
        src/shape/lineSegment/LineSegment.h
        src/shape/solidShape/ISolidShape.cpp
        src/shape/solidShape/ISolidShape.h
        src/shape/solidShape/rectangle/Rectangle.cpp
        src/shape/solidShape/rectangle/Rectangle.h
        src/shape/solidShape/triangle/Triangle.cpp
        src/shape/solidShape/triangle/Triangle.h
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
    #    target_link_libraries(shape_tests PRIVATE shape_app)
endif ()
