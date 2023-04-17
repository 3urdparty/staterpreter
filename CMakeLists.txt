cmake_minimum_required(VERSION 3.13.4)
project(staterpreter)
add_executable(${PROJECT_NAME} main.cpp)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)