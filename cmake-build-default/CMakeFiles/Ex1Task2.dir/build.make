# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ben/CLionProjects/Ex1Task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ben/CLionProjects/Ex1Task2/cmake-build-default

# Include any dependencies generated for this target.
include CMakeFiles/Ex1Task2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Ex1Task2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex1Task2.dir/flags.make

CMakeFiles/Ex1Task2.dir/main.cpp.o: CMakeFiles/Ex1Task2.dir/flags.make
CMakeFiles/Ex1Task2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/Ex1Task2/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ex1Task2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex1Task2.dir/main.cpp.o -c /home/ben/CLionProjects/Ex1Task2/main.cpp

CMakeFiles/Ex1Task2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex1Task2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/Ex1Task2/main.cpp > CMakeFiles/Ex1Task2.dir/main.cpp.i

CMakeFiles/Ex1Task2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex1Task2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/Ex1Task2/main.cpp -o CMakeFiles/Ex1Task2.dir/main.cpp.s

# Object files for target Ex1Task2
Ex1Task2_OBJECTS = \
"CMakeFiles/Ex1Task2.dir/main.cpp.o"

# External object files for target Ex1Task2
Ex1Task2_EXTERNAL_OBJECTS =

Ex1Task2: CMakeFiles/Ex1Task2.dir/main.cpp.o
Ex1Task2: CMakeFiles/Ex1Task2.dir/build.make
Ex1Task2: CMakeFiles/Ex1Task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/CLionProjects/Ex1Task2/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ex1Task2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ex1Task2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex1Task2.dir/build: Ex1Task2
.PHONY : CMakeFiles/Ex1Task2.dir/build

CMakeFiles/Ex1Task2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ex1Task2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ex1Task2.dir/clean

CMakeFiles/Ex1Task2.dir/depend:
	cd /home/ben/CLionProjects/Ex1Task2/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/CLionProjects/Ex1Task2 /home/ben/CLionProjects/Ex1Task2 /home/ben/CLionProjects/Ex1Task2/cmake-build-default /home/ben/CLionProjects/Ex1Task2/cmake-build-default /home/ben/CLionProjects/Ex1Task2/cmake-build-default/CMakeFiles/Ex1Task2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex1Task2.dir/depend
