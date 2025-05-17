cmake_minimum_required(VERSION 3.30)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(lab3/bank)
add_subdirectory(lab5/rational)
add_subdirectory(lab4/shape)
add_subdirectory(labs/lab7/myArray)

add_executable(OOP
        lab1/replace/main.cpp
        lab1/replace/main.cpp
        lab2/html_decode/main.cpp
        lab2/html_decode/src/HtmlDecode.cpp
        lab2/html_decode/tests/TestHtmlDecode.cpp
        lab2/dictionary/main.cpp
        lab2/dictionary/src/dictionaryReader/DictionaryReader.cpp
        lab2/dictionary/src/dictionaryReader/DictionaryReader.h
        lab2/dictionary/src/dialogHandler/DialogHandler.cpp
        lab2/dictionary/src/dialogHandler/DialogHandler.h
        lab2/dictionary/src/dictionary/Dictionary.cpp
        lab2/dictionary/src/dictionary/Dictionary.h
        lab2/dictionary/src/translationSet/TranslationSet.cpp
        lab2/dictionary/src/translationSet/TranslationSet.h
        lab2/dictionary/tests/TestDictionary.cpp)
