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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/evanw/Documents/dev/LEARNCMAKE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evanw/Documents/dev/LEARNCMAKE/build

# Include any dependencies generated for this target.
include dep/stb/CMakeFiles/stb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dep/stb/CMakeFiles/stb.dir/compiler_depend.make

# Include the progress variables for this target.
include dep/stb/CMakeFiles/stb.dir/progress.make

# Include the compile flags for this target's objects.
include dep/stb/CMakeFiles/stb.dir/flags.make

dep/stb/CMakeFiles/stb.dir/stb_image.cpp.o: dep/stb/CMakeFiles/stb.dir/flags.make
dep/stb/CMakeFiles/stb.dir/stb_image.cpp.o: ../dep/stb/stb_image.cpp
dep/stb/CMakeFiles/stb.dir/stb_image.cpp.o: dep/stb/CMakeFiles/stb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/evanw/Documents/dev/LEARNCMAKE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dep/stb/CMakeFiles/stb.dir/stb_image.cpp.o"
	cd /home/evanw/Documents/dev/LEARNCMAKE/build/dep/stb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dep/stb/CMakeFiles/stb.dir/stb_image.cpp.o -MF CMakeFiles/stb.dir/stb_image.cpp.o.d -o CMakeFiles/stb.dir/stb_image.cpp.o -c /home/evanw/Documents/dev/LEARNCMAKE/dep/stb/stb_image.cpp

dep/stb/CMakeFiles/stb.dir/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stb.dir/stb_image.cpp.i"
	cd /home/evanw/Documents/dev/LEARNCMAKE/build/dep/stb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evanw/Documents/dev/LEARNCMAKE/dep/stb/stb_image.cpp > CMakeFiles/stb.dir/stb_image.cpp.i

dep/stb/CMakeFiles/stb.dir/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stb.dir/stb_image.cpp.s"
	cd /home/evanw/Documents/dev/LEARNCMAKE/build/dep/stb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evanw/Documents/dev/LEARNCMAKE/dep/stb/stb_image.cpp -o CMakeFiles/stb.dir/stb_image.cpp.s

# Object files for target stb
stb_OBJECTS = \
"CMakeFiles/stb.dir/stb_image.cpp.o"

# External object files for target stb
stb_EXTERNAL_OBJECTS =

dep/stb/libstb.a: dep/stb/CMakeFiles/stb.dir/stb_image.cpp.o
dep/stb/libstb.a: dep/stb/CMakeFiles/stb.dir/build.make
dep/stb/libstb.a: dep/stb/CMakeFiles/stb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/evanw/Documents/dev/LEARNCMAKE/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libstb.a"
	cd /home/evanw/Documents/dev/LEARNCMAKE/build/dep/stb && $(CMAKE_COMMAND) -P CMakeFiles/stb.dir/cmake_clean_target.cmake
	cd /home/evanw/Documents/dev/LEARNCMAKE/build/dep/stb && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dep/stb/CMakeFiles/stb.dir/build: dep/stb/libstb.a
.PHONY : dep/stb/CMakeFiles/stb.dir/build

dep/stb/CMakeFiles/stb.dir/clean:
	cd /home/evanw/Documents/dev/LEARNCMAKE/build/dep/stb && $(CMAKE_COMMAND) -P CMakeFiles/stb.dir/cmake_clean.cmake
.PHONY : dep/stb/CMakeFiles/stb.dir/clean

dep/stb/CMakeFiles/stb.dir/depend:
	cd /home/evanw/Documents/dev/LEARNCMAKE/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evanw/Documents/dev/LEARNCMAKE /home/evanw/Documents/dev/LEARNCMAKE/dep/stb /home/evanw/Documents/dev/LEARNCMAKE/build /home/evanw/Documents/dev/LEARNCMAKE/build/dep/stb /home/evanw/Documents/dev/LEARNCMAKE/build/dep/stb/CMakeFiles/stb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dep/stb/CMakeFiles/stb.dir/depend

