# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kplums/school/practika/exam/5_rpn_calc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kplums/school/practika/exam/5_rpn_calc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/5_rpn_calc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5_rpn_calc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5_rpn_calc.dir/flags.make

CMakeFiles/5_rpn_calc.dir/main.c.o: CMakeFiles/5_rpn_calc.dir/flags.make
CMakeFiles/5_rpn_calc.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kplums/school/practika/exam/5_rpn_calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/5_rpn_calc.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/5_rpn_calc.dir/main.c.o   -c /Users/kplums/school/practika/exam/5_rpn_calc/main.c

CMakeFiles/5_rpn_calc.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5_rpn_calc.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kplums/school/practika/exam/5_rpn_calc/main.c > CMakeFiles/5_rpn_calc.dir/main.c.i

CMakeFiles/5_rpn_calc.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5_rpn_calc.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kplums/school/practika/exam/5_rpn_calc/main.c -o CMakeFiles/5_rpn_calc.dir/main.c.s

# Object files for target 5_rpn_calc
5_rpn_calc_OBJECTS = \
"CMakeFiles/5_rpn_calc.dir/main.c.o"

# External object files for target 5_rpn_calc
5_rpn_calc_EXTERNAL_OBJECTS =

5_rpn_calc: CMakeFiles/5_rpn_calc.dir/main.c.o
5_rpn_calc: CMakeFiles/5_rpn_calc.dir/build.make
5_rpn_calc: CMakeFiles/5_rpn_calc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kplums/school/practika/exam/5_rpn_calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 5_rpn_calc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/5_rpn_calc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5_rpn_calc.dir/build: 5_rpn_calc

.PHONY : CMakeFiles/5_rpn_calc.dir/build

CMakeFiles/5_rpn_calc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/5_rpn_calc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/5_rpn_calc.dir/clean

CMakeFiles/5_rpn_calc.dir/depend:
	cd /Users/kplums/school/practika/exam/5_rpn_calc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kplums/school/practika/exam/5_rpn_calc /Users/kplums/school/practika/exam/5_rpn_calc /Users/kplums/school/practika/exam/5_rpn_calc/cmake-build-debug /Users/kplums/school/practika/exam/5_rpn_calc/cmake-build-debug /Users/kplums/school/practika/exam/5_rpn_calc/cmake-build-debug/CMakeFiles/5_rpn_calc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5_rpn_calc.dir/depend

