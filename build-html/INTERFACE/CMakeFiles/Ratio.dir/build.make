# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html

# Include any dependencies generated for this target.
include INTERFACE/CMakeFiles/Ratio.dir/depend.make

# Include the progress variables for this target.
include INTERFACE/CMakeFiles/Ratio.dir/progress.make

# Include the compile flags for this target's objects.
include INTERFACE/CMakeFiles/Ratio.dir/flags.make

INTERFACE/CMakeFiles/Ratio.dir/src/Ratio.cpp.o: INTERFACE/CMakeFiles/Ratio.dir/flags.make
INTERFACE/CMakeFiles/Ratio.dir/src/Ratio.cpp.o: ../RatioLib/src/Ratio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object INTERFACE/CMakeFiles/Ratio.dir/src/Ratio.cpp.o"
	cd /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/INTERFACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ratio.dir/src/Ratio.cpp.o -c /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/RatioLib/src/Ratio.cpp

INTERFACE/CMakeFiles/Ratio.dir/src/Ratio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ratio.dir/src/Ratio.cpp.i"
	cd /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/RatioLib/src/Ratio.cpp > CMakeFiles/Ratio.dir/src/Ratio.cpp.i

INTERFACE/CMakeFiles/Ratio.dir/src/Ratio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ratio.dir/src/Ratio.cpp.s"
	cd /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/RatioLib/src/Ratio.cpp -o CMakeFiles/Ratio.dir/src/Ratio.cpp.s

# Object files for target Ratio
Ratio_OBJECTS = \
"CMakeFiles/Ratio.dir/src/Ratio.cpp.o"

# External object files for target Ratio
Ratio_EXTERNAL_OBJECTS =

INTERFACE/libRatio.a: INTERFACE/CMakeFiles/Ratio.dir/src/Ratio.cpp.o
INTERFACE/libRatio.a: INTERFACE/CMakeFiles/Ratio.dir/build.make
INTERFACE/libRatio.a: INTERFACE/CMakeFiles/Ratio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libRatio.a"
	cd /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/INTERFACE && $(CMAKE_COMMAND) -P CMakeFiles/Ratio.dir/cmake_clean_target.cmake
	cd /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/INTERFACE && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ratio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
INTERFACE/CMakeFiles/Ratio.dir/build: INTERFACE/libRatio.a

.PHONY : INTERFACE/CMakeFiles/Ratio.dir/build

INTERFACE/CMakeFiles/Ratio.dir/clean:
	cd /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/INTERFACE && $(CMAKE_COMMAND) -P CMakeFiles/Ratio.dir/cmake_clean.cmake
.PHONY : INTERFACE/CMakeFiles/Ratio.dir/clean

INTERFACE/CMakeFiles/Ratio.dir/depend:
	cd /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/RatioLib /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/INTERFACE /home/frankie/Bureau/IMAC_2/ProgMaths_ALIDOR_COUARDT/build-html/INTERFACE/CMakeFiles/Ratio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : INTERFACE/CMakeFiles/Ratio.dir/depend

