# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/theycallmemuzz/Code/staterpreter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/theycallmemuzz/Code/staterpreter/build

# Include any dependencies generated for this target.
include CMakeFiles/staterpreter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/staterpreter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/staterpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/staterpreter.dir/flags.make

CMakeFiles/staterpreter.dir/main.cpp.o: CMakeFiles/staterpreter.dir/flags.make
CMakeFiles/staterpreter.dir/main.cpp.o: /Users/theycallmemuzz/Code/staterpreter/main.cpp
CMakeFiles/staterpreter.dir/main.cpp.o: CMakeFiles/staterpreter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/theycallmemuzz/Code/staterpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/staterpreter.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/staterpreter.dir/main.cpp.o -MF CMakeFiles/staterpreter.dir/main.cpp.o.d -o CMakeFiles/staterpreter.dir/main.cpp.o -c /Users/theycallmemuzz/Code/staterpreter/main.cpp

CMakeFiles/staterpreter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/staterpreter.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/theycallmemuzz/Code/staterpreter/main.cpp > CMakeFiles/staterpreter.dir/main.cpp.i

CMakeFiles/staterpreter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/staterpreter.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/theycallmemuzz/Code/staterpreter/main.cpp -o CMakeFiles/staterpreter.dir/main.cpp.s

# Object files for target staterpreter
staterpreter_OBJECTS = \
"CMakeFiles/staterpreter.dir/main.cpp.o"

# External object files for target staterpreter
staterpreter_EXTERNAL_OBJECTS =

staterpreter: CMakeFiles/staterpreter.dir/main.cpp.o
staterpreter: CMakeFiles/staterpreter.dir/build.make
staterpreter: include/utilities/libutilities.a
staterpreter: include/table/libtable.a
staterpreter: include/commands/libcommands.a
staterpreter: include/prompt/libprompt.a
staterpreter: CMakeFiles/staterpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/theycallmemuzz/Code/staterpreter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable staterpreter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/staterpreter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/staterpreter.dir/build: staterpreter
.PHONY : CMakeFiles/staterpreter.dir/build

CMakeFiles/staterpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/staterpreter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/staterpreter.dir/clean

CMakeFiles/staterpreter.dir/depend:
	cd /Users/theycallmemuzz/Code/staterpreter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/theycallmemuzz/Code/staterpreter /Users/theycallmemuzz/Code/staterpreter /Users/theycallmemuzz/Code/staterpreter/build /Users/theycallmemuzz/Code/staterpreter/build /Users/theycallmemuzz/Code/staterpreter/build/CMakeFiles/staterpreter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/staterpreter.dir/depend

