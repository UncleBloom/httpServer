# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/wangyizhou/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/wangyizhou/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangyizhou/Desktop/code/C/HttpServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangyizhou/Desktop/code/C/HttpServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HttpServer.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/HttpServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HttpServer.dir/flags.make

CMakeFiles/HttpServer.dir/main.cpp.o: CMakeFiles/HttpServer.dir/flags.make
CMakeFiles/HttpServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyizhou/Desktop/code/C/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HttpServer.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HttpServer.dir/main.cpp.o -c /Users/wangyizhou/Desktop/code/C/HttpServer/main.cpp

CMakeFiles/HttpServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyizhou/Desktop/code/C/HttpServer/main.cpp > CMakeFiles/HttpServer.dir/main.cpp.i

CMakeFiles/HttpServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyizhou/Desktop/code/C/HttpServer/main.cpp -o CMakeFiles/HttpServer.dir/main.cpp.s

CMakeFiles/HttpServer.dir/HttpProcessor.cpp.o: CMakeFiles/HttpServer.dir/flags.make
CMakeFiles/HttpServer.dir/HttpProcessor.cpp.o: ../HttpProcessor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangyizhou/Desktop/code/C/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HttpServer.dir/HttpProcessor.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HttpServer.dir/HttpProcessor.cpp.o -c /Users/wangyizhou/Desktop/code/C/HttpServer/HttpProcessor.cpp

CMakeFiles/HttpServer.dir/HttpProcessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/HttpProcessor.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangyizhou/Desktop/code/C/HttpServer/HttpProcessor.cpp > CMakeFiles/HttpServer.dir/HttpProcessor.cpp.i

CMakeFiles/HttpServer.dir/HttpProcessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/HttpProcessor.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangyizhou/Desktop/code/C/HttpServer/HttpProcessor.cpp -o CMakeFiles/HttpServer.dir/HttpProcessor.cpp.s

# Object files for target HttpServer
HttpServer_OBJECTS = \
"CMakeFiles/HttpServer.dir/main.cpp.o" \
"CMakeFiles/HttpServer.dir/HttpProcessor.cpp.o"

# External object files for target HttpServer
HttpServer_EXTERNAL_OBJECTS =

HttpServer: CMakeFiles/HttpServer.dir/main.cpp.o
HttpServer: CMakeFiles/HttpServer.dir/HttpProcessor.cpp.o
HttpServer: CMakeFiles/HttpServer.dir/build.make
HttpServer: CMakeFiles/HttpServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangyizhou/Desktop/code/C/HttpServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable HttpServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HttpServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HttpServer.dir/build: HttpServer
.PHONY : CMakeFiles/HttpServer.dir/build

CMakeFiles/HttpServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HttpServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HttpServer.dir/clean

CMakeFiles/HttpServer.dir/depend:
	cd /Users/wangyizhou/Desktop/code/C/HttpServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangyizhou/Desktop/code/C/HttpServer /Users/wangyizhou/Desktop/code/C/HttpServer /Users/wangyizhou/Desktop/code/C/HttpServer/cmake-build-debug /Users/wangyizhou/Desktop/code/C/HttpServer/cmake-build-debug /Users/wangyizhou/Desktop/code/C/HttpServer/cmake-build-debug/CMakeFiles/HttpServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HttpServer.dir/depend
