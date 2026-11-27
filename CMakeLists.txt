cmake_minimum_required(VERSION 3.21)

project(
    SensorSignalWorkbench
    VERSION 0.1.0
    DESCRIPTION "Sensor signal analysis application"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1

)

FetchContent_MakeAvailable(Catch2)

# executable app main
add_executable(ssaw
    src/main.cpp

    src/core/models/SignalMetadata.cpp 
    src/core/models/SignalMetadata.hpp
    
    src/core/models/SignalData.cpp
    src/core/models/SignalData.hpp
)

# including directories
target_include_directories(ssaw 
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
)

# Warnings for compiler
if(MSVC)
    target_compile_options(ssaw PRIVATE /W4 /permissive-)
else()
    target_compile_options(ssaw PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()

add_executable(
    ssaw_tests
    tests/unit/test_main.cpp
)

target_link_libraries(
    ssaw_tests
    PRIVATE 
        Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(ssaw_tests)

