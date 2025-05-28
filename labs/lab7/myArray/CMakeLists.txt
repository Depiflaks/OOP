cmake_minimum_required(VERSION 3.10)
project(lab7_my_array)

set(CMAKE_CXX_STANDARD 20)

if (POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif ()
set(OpenGL_GL_PREFERENCE GLVND)

find_package(glfw3 3.3 REQUIRED)
find_package(GTest REQUIRED)

# ==== SOURCES ====

file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
        "src/*.cpp"
        "src/*/*.cpp"
        "src/*/*/*.cpp"
        "src/*/*/*/*.cpp"
)

list(FILTER ALL_SOURCES EXCLUDE REGEX ".*tests/.*")

# ==== APP ====

add_executable(my_array_app
        main.cpp
        ${ALL_SOURCES}
        src/myArray/MyArray.cpp
        src/myArray/MyArray.h
)

target_link_libraries(my_array_app
        PRIVATE
)

target_include_directories(my_array_app PRIVATE
        src
)

# ==== TESTS ====

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp")

if (TEST_SOURCES)
    add_executable(my_array_tests
            #            ${TEST_SOURCES}
            tests/baseTests.cpp
            tests/copyMoveConstructorsTests.cpp
            ${ALL_SOURCES}
    )

    target_include_directories(my_array_tests PRIVATE
            src
    )

    target_link_libraries(my_array_tests
            PRIVATE
            GTest::gtest
            GTest::gmock
            GTest::gtest_main
    )

    enable_testing()
    include(GoogleTest)
    gtest_discover_tests(my_array_tests)
endif ()
