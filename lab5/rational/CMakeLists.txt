cmake_minimum_required(VERSION 3.10)
project(lab5_rational)

set(CMAKE_CXX_STANDARD 20)

add_executable(rational_app
        main.cpp
        src/cRational/CRational.cpp
        src/cRational/CRational.h

)

target_include_directories(rational_app PRIVATE
)

#if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/TestActor.cpp")
#    add_executable(bank_tests
#            tests/TestActor.cpp
#            tests/TestBank.cpp
#    )
#    target_include_directories(bank_tests PRIVATE src)
#    target_link_libraries(bank_tests PRIVATE bank_app)
#endif()