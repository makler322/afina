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
CMAKE_SOURCE_DIR = /home/makler/Documents/afina

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/makler/Documents/afina

# Include any dependencies generated for this target.
include src/CMakeFiles/afina.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/afina.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/afina.dir/flags.make

src/CMakeFiles/afina.dir/main.cpp.o: src/CMakeFiles/afina.dir/flags.make
src/CMakeFiles/afina.dir/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/makler/Documents/afina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/afina.dir/main.cpp.o"
	cd /home/makler/Documents/afina/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/afina.dir/main.cpp.o -c /home/makler/Documents/afina/src/main.cpp

src/CMakeFiles/afina.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/afina.dir/main.cpp.i"
	cd /home/makler/Documents/afina/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/makler/Documents/afina/src/main.cpp > CMakeFiles/afina.dir/main.cpp.i

src/CMakeFiles/afina.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/afina.dir/main.cpp.s"
	cd /home/makler/Documents/afina/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/makler/Documents/afina/src/main.cpp -o CMakeFiles/afina.dir/main.cpp.s

src/CMakeFiles/afina.dir/Version.cpp.o: src/CMakeFiles/afina.dir/flags.make
src/CMakeFiles/afina.dir/Version.cpp.o: src/Version.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/makler/Documents/afina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/afina.dir/Version.cpp.o"
	cd /home/makler/Documents/afina/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/afina.dir/Version.cpp.o -c /home/makler/Documents/afina/src/Version.cpp

src/CMakeFiles/afina.dir/Version.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/afina.dir/Version.cpp.i"
	cd /home/makler/Documents/afina/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/makler/Documents/afina/src/Version.cpp > CMakeFiles/afina.dir/Version.cpp.i

src/CMakeFiles/afina.dir/Version.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/afina.dir/Version.cpp.s"
	cd /home/makler/Documents/afina/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/makler/Documents/afina/src/Version.cpp -o CMakeFiles/afina.dir/Version.cpp.s

# Object files for target afina
afina_OBJECTS = \
"CMakeFiles/afina.dir/main.cpp.o" \
"CMakeFiles/afina.dir/Version.cpp.o"

# External object files for target afina
afina_EXTERNAL_OBJECTS = \
"/home/makler/Documents/afina/third-party/backward-cpp/CMakeFiles/backward_object.dir/backward.cpp.o"

src/afina: src/CMakeFiles/afina.dir/main.cpp.o
src/afina: src/CMakeFiles/afina.dir/Version.cpp.o
src/afina: third-party/backward-cpp/CMakeFiles/backward_object.dir/backward.cpp.o
src/afina: src/CMakeFiles/afina.dir/build.make
src/afina: src/logging/libLogging.a
src/afina: src/concurrency/libConcurrency.a
src/afina: src/network/libNetwork.a
src/afina: src/storage/libStorage.a
src/afina: src/logging/libLogging.a
src/afina: src/protocol/libProtocol.a
src/afina: src/execute/libExecute.a
src/afina: src/storage/libStorage.a
src/afina: src/coroutine/libCoroutine.a
src/afina: src/CMakeFiles/afina.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/makler/Documents/afina/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable afina"
	cd /home/makler/Documents/afina/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/afina.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/afina.dir/build: src/afina

.PHONY : src/CMakeFiles/afina.dir/build

src/CMakeFiles/afina.dir/clean:
	cd /home/makler/Documents/afina/src && $(CMAKE_COMMAND) -P CMakeFiles/afina.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/afina.dir/clean

src/CMakeFiles/afina.dir/depend:
	cd /home/makler/Documents/afina && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/makler/Documents/afina /home/makler/Documents/afina/src /home/makler/Documents/afina /home/makler/Documents/afina/src /home/makler/Documents/afina/src/CMakeFiles/afina.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/afina.dir/depend

