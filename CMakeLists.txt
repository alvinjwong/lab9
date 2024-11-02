cmake_minimum_required(VERSION 3.14)

# Change "projectName" to whatever you want
set(this MyStringProj)

# Defines the project, and the language we are using
project(${this} CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# Allows us to include the Google Test framework
add_subdirectory(googletest)

# Set headers and sources for your project
set(Headers
    mystring.h
)

set(Sources
    mystring.cpp
)

# Creates a library from the source code we provided in "Sources" and "Headers"
add_library(${this} SHARED ${Sources} ${Headers})

# Sets the name of the testing executable we are creating
set(test MyStringTest)

# Change test.cpp to the name of your testing file
set(testSources
    test.cpp
)

# Creates the testing executable, and links it to our project and
# the Google Test framework
add_executable(${test} ${testSources})
target_link_libraries(${test} PUBLIC
    gtest_main # When testing, gtest provides the main function
    ${this}
)

# Allows us to use ctest
add_test(
    NAME ${test}
    COMMAND ${test}
)
