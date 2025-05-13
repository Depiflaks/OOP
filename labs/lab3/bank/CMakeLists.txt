cmake_minimum_required(VERSION 3.10)
project(lab3_bank)

set(CMAKE_CXX_STANDARD 20)

add_executable(bank_app
        main.cpp
        src/actor/Actor.cpp
        src/bank/Bank.cpp
        src/citizen/Citizen.cpp
        src/citizen/description/contactList/IContactList.cpp
        src/random/random.cpp
        src/town/Town.cpp
        src/town/citizenRegistry/CitizenRegistry.cpp
        src/citizen/citizens/citizens.h
        src/citizen/citizens/citizenApu.cpp
        src/citizen/citizens/citizenLisa.cpp
        src/citizen/citizens/citizenBart.cpp
        src/citizen/citizens/citizenHomer.cpp
        src/citizen/citizens/citizenMarge.cpp
        src/citizen/citizens/citizenMrBurns.cpp
        src/citizen/citizens/citizenNelson.cpp
        src/citizen/citizens/citizenSmithers.cpp
        src/citizen/citizens/citizenSnake.cpp
)

target_include_directories(bank_app PRIVATE
        src
        src/actor
        src/bank
        src/citizen
        src/citizen/citizens
        src/citizen/description
        src/citizen/description/contactList
        src/random
        src/town
        src/town/citizenRegistry
)

#if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/TestActor.cpp")
#    add_executable(bank_tests
#            tests/TestActor.cpp
#            tests/TestBank.cpp
#    )
#    target_include_directories(bank_tests PRIVATE src)
#    target_link_libraries(bank_tests PRIVATE bank_app)
#endif()