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
CMAKE_SOURCE_DIR = /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/build

# Include any dependencies generated for this target.
include CMakeFiles/Email_Validation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Email_Validation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Email_Validation.dir/flags.make

CMakeFiles/Email_Validation.dir/src/main.cc.o: CMakeFiles/Email_Validation.dir/flags.make
CMakeFiles/Email_Validation.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Email_Validation.dir/src/main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Email_Validation.dir/src/main.cc.o -c /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/src/main.cc

CMakeFiles/Email_Validation.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Email_Validation.dir/src/main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/src/main.cc > CMakeFiles/Email_Validation.dir/src/main.cc.i

CMakeFiles/Email_Validation.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Email_Validation.dir/src/main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/src/main.cc -o CMakeFiles/Email_Validation.dir/src/main.cc.s

# Object files for target Email_Validation
Email_Validation_OBJECTS = \
"CMakeFiles/Email_Validation.dir/src/main.cc.o"

# External object files for target Email_Validation
Email_Validation_EXTERNAL_OBJECTS =

bin/Email_Validation: CMakeFiles/Email_Validation.dir/src/main.cc.o
bin/Email_Validation: CMakeFiles/Email_Validation.dir/build.make
bin/Email_Validation: CMakeFiles/Email_Validation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/Email_Validation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Email_Validation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Email_Validation.dir/build: bin/Email_Validation

.PHONY : CMakeFiles/Email_Validation.dir/build

CMakeFiles/Email_Validation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Email_Validation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Email_Validation.dir/clean

CMakeFiles/Email_Validation.dir/depend:
	cd /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/build /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/build /usr/local/acct/development/projects/CSCI_1730/Michaels-Projects/AssignmentThree/Email_Validation/build/CMakeFiles/Email_Validation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Email_Validation.dir/depend

