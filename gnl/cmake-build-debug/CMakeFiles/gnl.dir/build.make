# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/kplums/school/gnl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kplums/school/gnl/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gnl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gnl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gnl.dir/flags.make

CMakeFiles/gnl.dir/main.c.o: CMakeFiles/gnl.dir/flags.make
CMakeFiles/gnl.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kplums/school/gnl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gnl.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gnl.dir/main.c.o   -c /Users/kplums/school/gnl/main.c

CMakeFiles/gnl.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gnl.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kplums/school/gnl/main.c > CMakeFiles/gnl.dir/main.c.i

CMakeFiles/gnl.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gnl.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kplums/school/gnl/main.c -o CMakeFiles/gnl.dir/main.c.s

CMakeFiles/gnl.dir/get_next_line.c.o: CMakeFiles/gnl.dir/flags.make
CMakeFiles/gnl.dir/get_next_line.c.o: ../get_next_line.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kplums/school/gnl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gnl.dir/get_next_line.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gnl.dir/get_next_line.c.o   -c /Users/kplums/school/gnl/get_next_line.c

CMakeFiles/gnl.dir/get_next_line.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gnl.dir/get_next_line.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kplums/school/gnl/get_next_line.c > CMakeFiles/gnl.dir/get_next_line.c.i

CMakeFiles/gnl.dir/get_next_line.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gnl.dir/get_next_line.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kplums/school/gnl/get_next_line.c -o CMakeFiles/gnl.dir/get_next_line.c.s

# Object files for target gnl
gnl_OBJECTS = \
"CMakeFiles/gnl.dir/main.c.o" \
"CMakeFiles/gnl.dir/get_next_line.c.o"

# External object files for target gnl
gnl_EXTERNAL_OBJECTS =

gnl: CMakeFiles/gnl.dir/main.c.o
gnl: CMakeFiles/gnl.dir/get_next_line.c.o
gnl: CMakeFiles/gnl.dir/build.make
gnl: //Users/kplums/school/gnl/libft/libft.a
gnl: CMakeFiles/gnl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kplums/school/gnl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable gnl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gnl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gnl.dir/build: gnl

.PHONY : CMakeFiles/gnl.dir/build

CMakeFiles/gnl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gnl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gnl.dir/clean

CMakeFiles/gnl.dir/depend:
	cd /Users/kplums/school/gnl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kplums/school/gnl /Users/kplums/school/gnl /Users/kplums/school/gnl/cmake-build-debug /Users/kplums/school/gnl/cmake-build-debug /Users/kplums/school/gnl/cmake-build-debug/CMakeFiles/gnl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gnl.dir/depend

