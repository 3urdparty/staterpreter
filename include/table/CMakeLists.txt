cmake_minimum_required(VERSION 3.13.4)
set (CMAKE_CXX_STANDARD 17)
project(table)
add_library(${PROJECT_NAME} columns.cpp table.cpp table.hpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER table.hpp)
install(TARGETS ${PROJECT_NAME} DESTINATION lib
PUBLIC_HEADER DESTINATION include 
)