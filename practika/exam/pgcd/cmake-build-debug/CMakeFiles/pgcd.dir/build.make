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
CMAKE_SOURCE_DIR = /Users/kplums/practika/exam/pgcd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kplums/practika/exam/pgcd/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pgcd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pgcd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pgcd.dir/flags.make

CMakeFiles/pgcd.dir/main.c.o: CMakeFiles/pgcd.dir/flags.make
CMakeFiles/pgcd.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kplums/practika/exam/pgcd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pgcd.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pgcd.dir/main.c.o   -c /Users/kplums/practika/exam/pgcd/main.c

CMakeFiles/pgcd.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pgcd.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kplums/practika/exam/pgcd/main.c > CMakeFiles/pgcd.dir/main.c.i

CMakeFiles/pgcd.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pgcd.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kplums/practika/exam/pgcd/main.c -o CMakeFiles/pgcd.dir/main.c.s

# Object files for target pgcd
pgcd_OBJECTS = \
"CMakeFiles/pgcd.dir/main.c.o"

# External object files for target pgcd
pgcd_EXTERNAL_OBJECTS =

pgcd: CMakeFiles/pgcd.dir/main.c.o
pgcd: CMakeFiles/pgcd.dir/build.make
pgcd: CMakeFiles/pgcd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kplums/practika/exam/pgcd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pgcd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pgcd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pgcd.dir/build: pgcd

.PHONY : CMakeFiles/pgcd.dir/build

CMakeFiles/pgcd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pgcd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pgcd.dir/clean

CMakeFiles/pgcd.dir/depend:
	cd /Users/kplums/practika/exam/pgcd/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kplums/practika/exam/pgcd /Users/kplums/practika/exam/pgcd /Users/kplums/practika/exam/pgcd/cmake-build-debug /Users/kplums/practika/exam/pgcd/cmake-build-debug /Users/kplums/practika/exam/pgcd/cmake-build-debug/CMakeFiles/pgcd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pgcd.dir/depend

