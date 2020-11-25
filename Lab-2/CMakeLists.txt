cmake_minimum_required(VERSION 3.16.3)

project("Main")
 
add_library(calculator STATIC calculator.cpp)

add_executable("${PROJECT_NAME}" main.cpp)

target_link_libraries("${PROJECT_NAME}" calculator)
