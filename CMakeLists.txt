cmake_minimum_required(VERSION 3.30)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(labs/lab1/replace)
add_subdirectory(labs/lab2/primes)
add_subdirectory(labs/lab2/html_decode)
add_subdirectory(labs/lab2/dictionary)
add_subdirectory(labs/lab3/bank)
add_subdirectory(labs/lab5/rational)
add_subdirectory(labs/lab4/shape)
add_subdirectory(labs/lab6/http)
add_subdirectory(labs/lab3/tvset)
add_subdirectory(labs/lab5/myString)
add_subdirectory(labs/lab6/myStringList)
add_subdirectory(labs/lab7/myArray)
add_subdirectory(labs/lab7/maxEx)
add_subdirectory(labs/lab7/people)
