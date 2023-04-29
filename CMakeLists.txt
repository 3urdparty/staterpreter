
cmake_minimum_required(VERSION 3.0.0)
set (CMAKE_CXX_STANDARD 17)

set(MAIN_PROJECT_NAME
    staterpreter
)
set(MAIN_SOURCE_DIR
    src
)
set(MAIN_SOURCE
    ${MAIN_SOURCE_DIR}/main.cpp
)
set(MAIN_LIBRARIES_DIR
    libs
)
set(MAIN_LIBRARIES 
terminal
fileoperations
strfmt
table
statistical
histogram
)

set(CMD_DIR ${MAIN_SOURCE_DIR}/commands)

set(MAIN_CMDS
${CMD_DIR}/addCMD.cpp
${CMD_DIR}/cloneFileCMD.cpp
${CMD_DIR}/columnsCMD.cpp
${CMD_DIR}/corrCMD.cpp
${CMD_DIR}/deleteCMD.cpp
${CMD_DIR}/evenRowsCMD.cpp
${CMD_DIR}/generateHTMLCMD.cpp
${CMD_DIR}/helpCMD.cpp
${CMD_DIR}/hhistoCMD.cpp
${CMD_DIR}/insertRowCMD.cpp
${CMD_DIR}/loadFileCMD.cpp
${CMD_DIR}/manCMD.cpp
${CMD_DIR}/maxCMD.cpp
${CMD_DIR}/meanCMD.cpp
${CMD_DIR}/medianCMD.cpp
${CMD_DIR}/minCMD.cpp
${CMD_DIR}/oddRowsCMD.cpp
${CMD_DIR}/primesCMD.cpp
${CMD_DIR}/regressionCMD.cpp
${CMD_DIR}/replaceCMD.cpp
${CMD_DIR}/reportCMD.cpp
${CMD_DIR}/rowsCMD.cpp
${CMD_DIR}/showCMD.cpp
${CMD_DIR}/sortCMD.cpp
${CMD_DIR}/stdvCMD.cpp
${CMD_DIR}/storeFileCMD.cpp
${CMD_DIR}/subCMD.cpp
${CMD_DIR}/titlesCMD.cpp
${CMD_DIR}/varianceCMD.cpp
${CMD_DIR}/vhistoCMD.cpp
${CMD_DIR}/addCMD.cpp
${CMD_DIR}/cloneFileCMD.cpp
${CMD_DIR}/columnsCMD.cpp
${CMD_DIR}/corrCMD.cpp
${CMD_DIR}/deleteCMD.cpp
${CMD_DIR}/evenRowsCMD.cpp
${CMD_DIR}/generateHTMLCMD.cpp
${CMD_DIR}/helpCMD.cpp
${CMD_DIR}/hhistoCMD.cpp
${CMD_DIR}/insertRowCMD.cpp
${CMD_DIR}/loadFileCMD.cpp
${CMD_DIR}/manCMD.cpp
${CMD_DIR}/maxCMD.cpp
${CMD_DIR}/meanCMD.cpp
${CMD_DIR}/medianCMD.cpp
${CMD_DIR}/minCMD.cpp
${CMD_DIR}/oddRowsCMD.cpp
${CMD_DIR}/primesCMD.cpp
${CMD_DIR}/regressionCMD.cpp
${CMD_DIR}/replaceCMD.cpp
${CMD_DIR}/reportCMD.cpp
${CMD_DIR}/rowsCMD.cpp
${CMD_DIR}/showCMD.cpp
${CMD_DIR}/sortCMD.cpp
${CMD_DIR}/stdvCMD.cpp
${CMD_DIR}/storeFileCMD.cpp
${CMD_DIR}/subCMD.cpp
${CMD_DIR}/titlesCMD.cpp
${CMD_DIR}/varianceCMD.cpp
${CMD_DIR}/vhistoCMD.cpp
)



project(${MAIN_PROJECT_NAME})


###########
# Project #
###########
add_executable(${MAIN_PROJECT_NAME} ${MAIN_SOURCE} ${MAIN_CMDS} ${MAIN_SOURCE_DIR}/prompt/prompt.cpp)

foreach(LIBRARY ${MAIN_LIBRARIES})
    add_subdirectory(${MAIN_LIBRARIES_DIR}/${LIBRARY})
endforeach(LIBRARY)
target_link_libraries(${MAIN_PROJECT_NAME} ${MAIN_LIBRARIES})



# set_target_properties(${LIBRARY_NAME} PROPERTIES PUBLIC_HEADER ${LIBRARY_HEADERS})
# install(TARGETS ${LIBRARY_NAME} DESTINATION lib/${LIBRARY_NAME})
