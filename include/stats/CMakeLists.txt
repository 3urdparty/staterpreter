cmake_minimum_required(VERSION 3.13.4)
set (CMAKE_CXX_STANDARD 17)
project(stats)
add_library(${PROJECT_NAME} statfunctions.cpp stats.hpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER stats.cpp)
install(TARGETS ${PROJECT_NAME} DESTINATION lib
PUBLIC_HEADER DESTINATION include 
)