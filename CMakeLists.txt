# General version specs for CMake.
cmake_minimum_required(VERSION 3.4)

# Define the project name.
project(hhcrsp-instgen-2021)

# Builds the osrm-backend dependency prior setting our project flags.
# This need to be defined before the other settings to not polute OSRM build.
add_subdirectory(osrm-backend)

# General project definitions. Assumes g++ being used to compile the code.
add_definitions(
   -std=c++17
   -pipe
   -march=native -mtune=native
   -Wall -Wextra -Wshadow
   -flto
)

# Set some include directories to the compiler look for header files of project dependencies.
include_directories(osrm-backend/include)
include_directories(ovig/include)

# Add the source code directory to the compiler include path.
include_directories(src)

# Definitions for Debug and Release compilation.
# To set the build mode, specify the value of var `CMAKE_BUILD_TYPE` when running CMake.
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -fno-omit-frame-pointer -g3")

# Fallback to Debug build type automatically if no compilation mode was specified.
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Debug")
endif()

message("-- Using compilation flags of mode \"" ${CMAKE_BUILD_TYPE} "\"")

# Creates the binaries relative to the project.
add_executable(instgen
   src/main.cpp
)

