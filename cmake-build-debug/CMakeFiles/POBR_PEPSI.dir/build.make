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
CMAKE_COMMAND = /home/demongo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/demongo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/demongo/CLionProjects/POBR_PEPSI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/POBR_PEPSI.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/POBR_PEPSI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/POBR_PEPSI.dir/flags.make

CMakeFiles/POBR_PEPSI.dir/src/main.cpp.o: CMakeFiles/POBR_PEPSI.dir/flags.make
CMakeFiles/POBR_PEPSI.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/POBR_PEPSI.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/POBR_PEPSI.dir/src/main.cpp.o -c /home/demongo/CLionProjects/POBR_PEPSI/src/main.cpp

CMakeFiles/POBR_PEPSI.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/POBR_PEPSI.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/demongo/CLionProjects/POBR_PEPSI/src/main.cpp > CMakeFiles/POBR_PEPSI.dir/src/main.cpp.i

CMakeFiles/POBR_PEPSI.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/POBR_PEPSI.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/demongo/CLionProjects/POBR_PEPSI/src/main.cpp -o CMakeFiles/POBR_PEPSI.dir/src/main.cpp.s

CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.o: CMakeFiles/POBR_PEPSI.dir/flags.make
CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.o: ../src/SegmentDescriptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.o -c /home/demongo/CLionProjects/POBR_PEPSI/src/SegmentDescriptor.cpp

CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/demongo/CLionProjects/POBR_PEPSI/src/SegmentDescriptor.cpp > CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.i

CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/demongo/CLionProjects/POBR_PEPSI/src/SegmentDescriptor.cpp -o CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.s

CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.o: CMakeFiles/POBR_PEPSI.dir/flags.make
CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.o: ../src/Scalers/NearestNeighbour.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.o -c /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/NearestNeighbour.cpp

CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/NearestNeighbour.cpp > CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.i

CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/NearestNeighbour.cpp -o CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.s

CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.o: CMakeFiles/POBR_PEPSI.dir/flags.make
CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.o: ../src/Scalers/Bilinear.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.o -c /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/Bilinear.cpp

CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/Bilinear.cpp > CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.i

CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/Bilinear.cpp -o CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.s

CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.o: CMakeFiles/POBR_PEPSI.dir/flags.make
CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.o: ../src/Scalers/IScaler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.o -c /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/IScaler.cpp

CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/IScaler.cpp > CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.i

CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/demongo/CLionProjects/POBR_PEPSI/src/Scalers/IScaler.cpp -o CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.s

# Object files for target POBR_PEPSI
POBR_PEPSI_OBJECTS = \
"CMakeFiles/POBR_PEPSI.dir/src/main.cpp.o" \
"CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.o" \
"CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.o" \
"CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.o" \
"CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.o"

# External object files for target POBR_PEPSI
POBR_PEPSI_EXTERNAL_OBJECTS =

POBR_PEPSI: CMakeFiles/POBR_PEPSI.dir/src/main.cpp.o
POBR_PEPSI: CMakeFiles/POBR_PEPSI.dir/src/SegmentDescriptor.cpp.o
POBR_PEPSI: CMakeFiles/POBR_PEPSI.dir/src/Scalers/NearestNeighbour.cpp.o
POBR_PEPSI: CMakeFiles/POBR_PEPSI.dir/src/Scalers/Bilinear.cpp.o
POBR_PEPSI: CMakeFiles/POBR_PEPSI.dir/src/Scalers/IScaler.cpp.o
POBR_PEPSI: CMakeFiles/POBR_PEPSI.dir/build.make
POBR_PEPSI: CMakeFiles/POBR_PEPSI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable POBR_PEPSI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/POBR_PEPSI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/POBR_PEPSI.dir/build: POBR_PEPSI
.PHONY : CMakeFiles/POBR_PEPSI.dir/build

CMakeFiles/POBR_PEPSI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/POBR_PEPSI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/POBR_PEPSI.dir/clean

CMakeFiles/POBR_PEPSI.dir/depend:
	cd /home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/demongo/CLionProjects/POBR_PEPSI /home/demongo/CLionProjects/POBR_PEPSI /home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug /home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug /home/demongo/CLionProjects/POBR_PEPSI/cmake-build-debug/CMakeFiles/POBR_PEPSI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/POBR_PEPSI.dir/depend

