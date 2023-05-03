
cmake_minimum_required(VERSION 3.26.0)
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
	filuzzy
	histoguzzy
	strfmt
	statsi
	tabluzzy
	terminalcancer
)

project(${MAIN_PROJECT_NAME})



################
# Dependencies #
################

message("")
message("Finding and downloading submodules for project `${PROJECT_NAME}`")
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS ${PROJECT_SOURCE_DIR}/.git)
	# Update submodules as needed
	option(GIT_SUBMODULE "Check submodules during build" ON)
	if (GIT_SUBMODULE)
		message(STATUS "Submodules updating")
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --recursive --remote
			WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		    RESULT_VARIABLE GIT_SUBMOD_RESULT)
		if(NOT GIT_SUBMOD_RESULT EQUAL "0")
			message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
		endif()
	endif()
endif()
  

foreach(LIBRARY ${MAIN_LIBRARIES})
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/libs/${LIBRARY}/CMakeLists.txt")
	message(FATAL_ERROR "The ${LIBRARY} submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
else()
    message (STATUS "Submodule ${LIBRARY} was downloaded and has been found.")
endif()
message("")
endforeach(LIBRARY)



foreach(LIBRARY ${MAIN_LIBRARIES})
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/libs/${LIBRARY}/CMakeLists.txt")
	message(FATAL_ERROR "The ${LIBRARY} submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
endforeach(LIBRARY)



###########
# Project #
###########

set(CMD_DIR ${MAIN_SOURCE_DIR}/commands)

set (CMD_SOURCE_FILES
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

set(PROMPT_DIR ${MAIN_SOURCE_DIR}/prompt )
set (PROMPT_SOURCE_FILES
${PROMPT_DIR}/prompt.cpp
)

add_executable(${MAIN_PROJECT_NAME} ${MAIN_SOURCE} ${CMD_SOURCE_FILES} ${PROMPT_SOURCE_FILES})

foreach(LIBRARY ${MAIN_LIBRARIES})
    add_subdirectory(${MAIN_LIBRARIES_DIR}/${LIBRARY})
endforeach(LIBRARY)
target_link_libraries(${MAIN_PROJECT_NAME} ${MAIN_LIBRARIES})

# Installation
install(TARGETS ${PROJECT_NAME} DESTINATION bin/${PROJECT_NAME})
