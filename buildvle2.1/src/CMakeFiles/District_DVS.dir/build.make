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
include src/CMakeFiles/District_DVS.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/District_DVS.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/District_DVS.dir/flags.make

src/CMakeFiles/District_DVS.dir/District_DVS.cpp.o: src/CMakeFiles/District_DVS.dir/flags.make
src/CMakeFiles/District_DVS.dir/District_DVS.cpp.o: ../src/District_DVS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raph/Modèles/POHM-Vietnam/buildvle2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/District_DVS.dir/District_DVS.cpp.o"
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/District_DVS.dir/District_DVS.cpp.o -c /home/raph/Modèles/POHM-Vietnam/src/District_DVS.cpp

src/CMakeFiles/District_DVS.dir/District_DVS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/District_DVS.dir/District_DVS.cpp.i"
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raph/Modèles/POHM-Vietnam/src/District_DVS.cpp > CMakeFiles/District_DVS.dir/District_DVS.cpp.i

src/CMakeFiles/District_DVS.dir/District_DVS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/District_DVS.dir/District_DVS.cpp.s"
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raph/Modèles/POHM-Vietnam/src/District_DVS.cpp -o CMakeFiles/District_DVS.dir/District_DVS.cpp.s

# Object files for target District_DVS
District_DVS_OBJECTS = \
"CMakeFiles/District_DVS.dir/District_DVS.cpp.o"

# External object files for target District_DVS
District_DVS_EXTERNAL_OBJECTS =

src/libDistrict_DVS.so: src/CMakeFiles/District_DVS.dir/District_DVS.cpp.o
src/libDistrict_DVS.so: src/CMakeFiles/District_DVS.dir/build.make
src/libDistrict_DVS.so: src/CMakeFiles/District_DVS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/raph/Modèles/POHM-Vietnam/buildvle2.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module libDistrict_DVS.so"
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/District_DVS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/District_DVS.dir/build: src/libDistrict_DVS.so

.PHONY : src/CMakeFiles/District_DVS.dir/build

src/CMakeFiles/District_DVS.dir/clean:
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src && $(CMAKE_COMMAND) -P CMakeFiles/District_DVS.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/District_DVS.dir/clean

src/CMakeFiles/District_DVS.dir/depend:
	cd /home/raph/Modèles/POHM-Vietnam/buildvle2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raph/Modèles/POHM-Vietnam /home/raph/Modèles/POHM-Vietnam/src /home/raph/Modèles/POHM-Vietnam/buildvle2.1 /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src /home/raph/Modèles/POHM-Vietnam/buildvle2.1/src/CMakeFiles/District_DVS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/District_DVS.dir/depend
