cmake_minimum_required(VERSION 3.13.4)
set (CMAKE_CXX_STANDARD 17)
project(histogram)
add_library(${PROJECT_NAME} histogram.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER histogram.h)
install(TARGETS ${PROJECT_NAME} DESTINATION lib
PUBLIC_HEADER DESTINATION include 
)