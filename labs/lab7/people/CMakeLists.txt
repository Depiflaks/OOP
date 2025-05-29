cmake_minimum_required(VERSION 3.10)
project(lab7_people)

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

add_executable(people_app
        main.cpp
        ${ALL_SOURCES}
        src/interface/person/IPerson.cpp
        src/interface/person/IPerson.h
        src/interface/student/IStudent.cpp
        src/interface/student/IStudent.h
)

target_link_libraries(people_app
        PRIVATE
)

target_include_directories(people_app PRIVATE
        src
)

# ==== TESTS ====

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp")

if (TEST_SOURCES)
    add_executable(people_tests
            ${TEST_SOURCES}
            ${ALL_SOURCES}
    )

    target_include_directories(people_tests PRIVATE
            src
    )

    target_link_libraries(people_tests
            PRIVATE
            GTest::gtest
            GTest::gmock
            GTest::gtest_main
    )

    enable_testing()
    include(GoogleTest)
    gtest_discover_tests(people_tests)
endif ()
