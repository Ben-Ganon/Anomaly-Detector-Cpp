# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/175/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/175/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ben/CLionProjects/AdvancedCompEx1Task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/Ex1Task2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Ex1Task2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Ex1Task2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex1Task2.dir/flags.make

CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o: CMakeFiles/Ex1Task2.dir/flags.make
CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o: ../MainTrain.cpp
CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o: CMakeFiles/Ex1Task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o -MF CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o.d -o CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o -c /home/ben/CLionProjects/AdvancedCompEx1Task2/MainTrain.cpp

CMakeFiles/Ex1Task2.dir/MainTrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex1Task2.dir/MainTrain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/AdvancedCompEx1Task2/MainTrain.cpp > CMakeFiles/Ex1Task2.dir/MainTrain.cpp.i

CMakeFiles/Ex1Task2.dir/MainTrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex1Task2.dir/MainTrain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/AdvancedCompEx1Task2/MainTrain.cpp -o CMakeFiles/Ex1Task2.dir/MainTrain.cpp.s

CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o: CMakeFiles/Ex1Task2.dir/flags.make
CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o: ../HybridAnomalyDetector.cpp
CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o: CMakeFiles/Ex1Task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o -MF CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o.d -o CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o -c /home/ben/CLionProjects/AdvancedCompEx1Task2/HybridAnomalyDetector.cpp

CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/AdvancedCompEx1Task2/HybridAnomalyDetector.cpp > CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.i

CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/AdvancedCompEx1Task2/HybridAnomalyDetector.cpp -o CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.s

CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o: CMakeFiles/Ex1Task2.dir/flags.make
CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o: ../anomaly_detection_util.cpp
CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o: CMakeFiles/Ex1Task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o -MF CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o.d -o CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o -c /home/ben/CLionProjects/AdvancedCompEx1Task2/anomaly_detection_util.cpp

CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/AdvancedCompEx1Task2/anomaly_detection_util.cpp > CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.i

CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/AdvancedCompEx1Task2/anomaly_detection_util.cpp -o CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.s

CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o: CMakeFiles/Ex1Task2.dir/flags.make
CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o: ../SimpleAnomalyDetector.cpp
CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o: CMakeFiles/Ex1Task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o -MF CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o.d -o CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o -c /home/ben/CLionProjects/AdvancedCompEx1Task2/SimpleAnomalyDetector.cpp

CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/AdvancedCompEx1Task2/SimpleAnomalyDetector.cpp > CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.i

CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/AdvancedCompEx1Task2/SimpleAnomalyDetector.cpp -o CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.s

CMakeFiles/Ex1Task2.dir/timeseries.cpp.o: CMakeFiles/Ex1Task2.dir/flags.make
CMakeFiles/Ex1Task2.dir/timeseries.cpp.o: ../timeseries.cpp
CMakeFiles/Ex1Task2.dir/timeseries.cpp.o: CMakeFiles/Ex1Task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Ex1Task2.dir/timeseries.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ex1Task2.dir/timeseries.cpp.o -MF CMakeFiles/Ex1Task2.dir/timeseries.cpp.o.d -o CMakeFiles/Ex1Task2.dir/timeseries.cpp.o -c /home/ben/CLionProjects/AdvancedCompEx1Task2/timeseries.cpp

CMakeFiles/Ex1Task2.dir/timeseries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex1Task2.dir/timeseries.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/AdvancedCompEx1Task2/timeseries.cpp > CMakeFiles/Ex1Task2.dir/timeseries.cpp.i

CMakeFiles/Ex1Task2.dir/timeseries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex1Task2.dir/timeseries.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/AdvancedCompEx1Task2/timeseries.cpp -o CMakeFiles/Ex1Task2.dir/timeseries.cpp.s

CMakeFiles/Ex1Task2.dir/minCircle.cpp.o: CMakeFiles/Ex1Task2.dir/flags.make
CMakeFiles/Ex1Task2.dir/minCircle.cpp.o: ../minCircle.cpp
CMakeFiles/Ex1Task2.dir/minCircle.cpp.o: CMakeFiles/Ex1Task2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Ex1Task2.dir/minCircle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ex1Task2.dir/minCircle.cpp.o -MF CMakeFiles/Ex1Task2.dir/minCircle.cpp.o.d -o CMakeFiles/Ex1Task2.dir/minCircle.cpp.o -c /home/ben/CLionProjects/AdvancedCompEx1Task2/minCircle.cpp

CMakeFiles/Ex1Task2.dir/minCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex1Task2.dir/minCircle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/AdvancedCompEx1Task2/minCircle.cpp > CMakeFiles/Ex1Task2.dir/minCircle.cpp.i

CMakeFiles/Ex1Task2.dir/minCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex1Task2.dir/minCircle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/AdvancedCompEx1Task2/minCircle.cpp -o CMakeFiles/Ex1Task2.dir/minCircle.cpp.s

# Object files for target Ex1Task2
Ex1Task2_OBJECTS = \
"CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o" \
"CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o" \
"CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o" \
"CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o" \
"CMakeFiles/Ex1Task2.dir/timeseries.cpp.o" \
"CMakeFiles/Ex1Task2.dir/minCircle.cpp.o"

# External object files for target Ex1Task2
Ex1Task2_EXTERNAL_OBJECTS =

Ex1Task2: CMakeFiles/Ex1Task2.dir/MainTrain.cpp.o
Ex1Task2: CMakeFiles/Ex1Task2.dir/HybridAnomalyDetector.cpp.o
Ex1Task2: CMakeFiles/Ex1Task2.dir/anomaly_detection_util.cpp.o
Ex1Task2: CMakeFiles/Ex1Task2.dir/SimpleAnomalyDetector.cpp.o
Ex1Task2: CMakeFiles/Ex1Task2.dir/timeseries.cpp.o
Ex1Task2: CMakeFiles/Ex1Task2.dir/minCircle.cpp.o
Ex1Task2: CMakeFiles/Ex1Task2.dir/build.make
Ex1Task2: CMakeFiles/Ex1Task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Ex1Task2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ex1Task2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex1Task2.dir/build: Ex1Task2
.PHONY : CMakeFiles/Ex1Task2.dir/build

CMakeFiles/Ex1Task2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ex1Task2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ex1Task2.dir/clean

CMakeFiles/Ex1Task2.dir/depend:
	cd /home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/CLionProjects/AdvancedCompEx1Task2 /home/ben/CLionProjects/AdvancedCompEx1Task2 /home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage /home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage /home/ben/CLionProjects/AdvancedCompEx1Task2/cmake-build-debug-coverage/CMakeFiles/Ex1Task2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex1Task2.dir/depend

