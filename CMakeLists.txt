cmake_minimum_required(VERSION 3.30)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

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

add_executable(OOP
        labs/lab1/replace/main.cpp
        labs/lab2/html_decode/main.cpp
        labs/lab2/html_decode/src/HtmlDecode.cpp
        labs/lab2/html_decode/tests/TestHtmlDecode.cpp
        labs/lab2/dictionary/main.cpp
        labs/lab2/dictionary/src/dictionaryReader/DictionaryReader.cpp
        labs/lab2/dictionary/src/dictionaryReader/DictionaryReader.h
        labs/lab2/dictionary/src/dialogHandler/DialogHandler.cpp
        labs/lab2/dictionary/src/dialogHandler/DialogHandler.h
        labs/lab2/dictionary/src/dictionary/Dictionary.cpp
        labs/lab2/dictionary/src/dictionary/Dictionary.h
        labs/lab2/dictionary/src/translationSet/TranslationSet.cpp
        labs/lab2/dictionary/src/translationSet/TranslationSet.h
        labs/lab2/dictionary/tests/TestDictionary.cpp)
