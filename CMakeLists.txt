cmake_minimum_required(VERSION 3.30)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP lab1/replace/main.cpp
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
        lab2/dictionary/tests/TestDictionary.cpp
        lab3/bank/main.cpp
        lab3/bank/src/bank/Bank.cpp
        lab3/bank/src/bank/Bank.h
        lab3/bank/src/actor/Actor.cpp
        lab3/bank/src/actor/Actor.h
        lab3/bank/tests/TestBank.cpp
        lab3/bank/tests/TestActor.cpp
        lab3/bank/src/citizen/ICitizen.h
        lab3/bank/src/citizen/description/name/CitizenName.h
        lab3/bank/src/town/Town.cpp
        lab3/bank/src/town/Town.h
        lab3/bank/src/citizen/citizens/homer/CitizenHomer.cpp
        lab3/bank/src/citizen/citizens/homer/CitizenHomer.h
        lab3/bank/src/citizen/ICitizen.cpp
        lab3/bank/src/citizen/description/CitizenDescription.cpp
        lab3/bank/src/citizen/description/CitizenDescription.h
        lab3/bank/src/citizen/description/map/citizenMap.h
        lab3/bank/src/citizen/citizens/marge/CitizenMarge.cpp
        lab3/bank/src/citizen/citizens/marge/CitizenMarge.h
        lab3/bank/src/citizen/citizens/bartAndLisa/CitizenBartAndLisa.cpp
        lab3/bank/src/citizen/citizens/bartAndLisa/CitizenBartAndLisa.h
        lab3/bank/src/citizen/citizens/apu/CitizenApu.cpp
        lab3/bank/src/citizen/citizens/apu/CitizenApu.h
        lab3/bank/src/citizen/citizens/mrBurns/CitizenMrBurns.cpp
        lab3/bank/src/citizen/citizens/mrBurns/CitizenMrBurns.h
        lab3/bank/src/citizen/citizens/nelson/CitizenNelson.cpp
        lab3/bank/src/citizen/citizens/nelson/CitizenNelson.h
        lab3/bank/src/citizen/citizens/snake/CitizenSnake.cpp
        lab3/bank/src/citizen/citizens/snake/CitizenSnake.h
        lab3/bank/src/citizen/citizens/smithers/CitizenSmithers.cpp
        lab3/bank/src/citizen/citizens/smithers/CitizenSmithers.h)
