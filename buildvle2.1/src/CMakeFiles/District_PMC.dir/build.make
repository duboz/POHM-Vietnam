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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/raph/Modèles/POHM-Vietnam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raph/Modèles/POHM-Vietnam/buildvle2.1

# Include any dependencies generated for this target.
include src/CMakeFiles/District_PMC.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/District_PMC.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/District_PMC.dir/flags.make

src/CMakeFiles/District_PMC.dir/District_PMC.cpp.o: src/CMakeFiles/District_PMC.dir/flags.make
src/CMakeFiles/District_PMC.dir/District_PMC.cpp.o: ../src/District_PMC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raph/Modèles/POHM-Vietnam/buildvle2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/District_PMC.dir/District_PMC.cpp.o"
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/District_PMC.dir/District_PMC.cpp.o -c /home/raph/Modèles/POHM-Vietnam/src/District_PMC.cpp

src/CMakeFiles/District_PMC.dir/District_PMC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/District_PMC.dir/District_PMC.cpp.i"
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raph/Modèles/POHM-Vietnam/src/District_PMC.cpp > CMakeFiles/District_PMC.dir/District_PMC.cpp.i

src/CMakeFiles/District_PMC.dir/District_PMC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/District_PMC.dir/District_PMC.cpp.s"
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raph/Modèles/POHM-Vietnam/src/District_PMC.cpp -o CMakeFiles/District_PMC.dir/District_PMC.cpp.s

# Object files for target District_PMC
District_PMC_OBJECTS = \
"CMakeFiles/District_PMC.dir/District_PMC.cpp.o"

# External object files for target District_PMC
District_PMC_EXTERNAL_OBJECTS =

src/libDistrict_PMC.so: src/CMakeFiles/District_PMC.dir/District_PMC.cpp.o
src/libDistrict_PMC.so: src/CMakeFiles/District_PMC.dir/build.make
src/libDistrict_PMC.so: src/CMakeFiles/District_PMC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/raph/Modèles/POHM-Vietnam/buildvle2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module libDistrict_PMC.so"
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/District_PMC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/District_PMC.dir/build: src/libDistrict_PMC.so

.PHONY : src/CMakeFiles/District_PMC.dir/build

src/CMakeFiles/District_PMC.dir/clean:
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && $(CMAKE_COMMAND) -P CMakeFiles/District_PMC.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/District_PMC.dir/clean

src/CMakeFiles/District_PMC.dir/depend:
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raph/Modèles/POHM-Vietnam /home/raph/Modèles/POHM-Vietnam/src /home/raph/Modèles/POHM-Vietnam/buildvle2.1 /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src/CMakeFiles/District_PMC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/District_PMC.dir/depend

