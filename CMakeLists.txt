cmake_minimum_required(VERSION 3.26)
project(staterpreter)
set (CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(include/utilities)
target_include_directories(${PROJECT_NAME} PUBLIC include/utilities)
target_link_directories(${PROJECT_NAME} PRIVATE  include/utilities)
target_link_libraries(${PROJECT_NAME} utilities)

add_subdirectory(include/table)
target_include_directories(${PROJECT_NAME} PUBLIC include/table)
target_link_directories(${PROJECT_NAME} PRIVATE  include/table)
target_link_libraries(${PROJECT_NAME} table)

add_subdirectory(include/commands)
target_include_directories(${PROJECT_NAME} PUBLIC include/commands)
target_link_directories(${PROJECT_NAME} PRIVATE  include/commands)
target_link_libraries(${PROJECT_NAME} commands)

add_subdirectory(include/prompt)
target_include_directories(${PROJECT_NAME} PUBLIC include/prompt)
target_link_directories(${PROJECT_NAME} PRIVATE  include/prompt)
target_link_libraries(${PROJECT_NAME} prompt)

add_subdirectory(include/stats)
target_include_directories(${PROJECT_NAME} PUBLIC include/stats)
target_link_directories(${PROJECT_NAME} PRIVATE  include/stats)
target_link_libraries(${PROJECT_NAME} stats)

