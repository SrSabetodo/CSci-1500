# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/build

# Include any dependencies generated for this target.
include CMakeFiles/Elevator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Elevator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Elevator.dir/flags.make

CMakeFiles/Elevator.dir/src/main.cc.o: CMakeFiles/Elevator.dir/flags.make
CMakeFiles/Elevator.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Elevator.dir/src/main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Elevator.dir/src/main.cc.o -c /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/src/main.cc

CMakeFiles/Elevator.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Elevator.dir/src/main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/src/main.cc > CMakeFiles/Elevator.dir/src/main.cc.i

CMakeFiles/Elevator.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Elevator.dir/src/main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/src/main.cc -o CMakeFiles/Elevator.dir/src/main.cc.s

# Object files for target Elevator
Elevator_OBJECTS = \
"CMakeFiles/Elevator.dir/src/main.cc.o"

# External object files for target Elevator
Elevator_EXTERNAL_OBJECTS =

bin/Elevator: CMakeFiles/Elevator.dir/src/main.cc.o
bin/Elevator: CMakeFiles/Elevator.dir/build.make
bin/Elevator: CMakeFiles/Elevator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/Elevator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Elevator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Elevator.dir/build: bin/Elevator

.PHONY : CMakeFiles/Elevator.dir/build

CMakeFiles/Elevator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Elevator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Elevator.dir/clean

CMakeFiles/Elevator.dir/depend:
	cd /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/build /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/build /usr/local/acct/development/projects/CSCO_1730/Michaels-Projects/AssignmentTwo/Elevator/build/CMakeFiles/Elevator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Elevator.dir/depend
