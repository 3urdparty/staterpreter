cmake_minimum_required(VERSION 3.13.4)
set (CMAKE_CXX_STANDARD 17)
project(utilities)
add_library(${PROJECT_NAME} fileoperations.cpp stringfmt.cpp terminal.cpp textformat.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER utilities.h)
install(TARGETS ${PROJECT_NAME} DESTINATION lib
PUBLIC_HEADER DESTINATION include 
)