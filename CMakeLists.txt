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

# executable app main
add_executable(ssaw
    src/main.cpp
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

