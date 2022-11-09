cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(Ratio)

# display VERBOSE messages : cmake --log-level=VERBOSE ..

# specify the system
message(VERBOSE "CMAKE_VERSION           : " ${CMAKE_VERSION})
message(VERBOSE "CMAKE_SYSTEM_NAME       : " ${CMAKE_SYSTEM_NAME})
message(VERBOSE "CMAKE_SYSTEM            : " ${CMAKE_SYSTEM})
message(VERBOSE "CMAKE_SYSTEM_PROCESSOR  : " ${CMAKE_SYSTEM_PROCESSOR} "\n")

# specify the directories
message(VERBOSE "CMAKE_BINARY_DIR        : " ${CMAKE_BINARY_DIR})
message(VERBOSE "CMAKE_SOURCE_DIR        : " ${CMAKE_SOURCE_DIR})
message(VERBOSE "CMAKE_HOME_DIRECTORY    : " ${CMAKE_HOME_DIRECTORY})
message(VERBOSE "PROJECT_BINARY_DIR      : " ${PROJECT_BINARY_DIR})
message(VERBOSE "PROJECT_SOURCE_DIR      : " ${PROJECT_SOURCE_DIR} "\n")

# compile flags
message(VERBOSE "CMAKE_CXX_FLAGS         : " ${CMAKE_CXX_FLAG})
message(VERBOSE "CMAKE_CXX_FLAGS_DEBUG   : " ${CMAKE_CXX_FLAGS_DEBUG})
message(VERBOSE "CMAKE_CXX_FLAGS_RELEASE : " ${CMAKE_CXX_FLAGS_RELEASE})
message(VERBOSE "CMAKE_CXX_COMPILER      : " ${CMAKE_CXX_COMPILER} "\n")


# not clear, but vscode can't work fine without
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Prevents compiler-specific extensions to C++ because they might allow code to compile on your machine but not on other people's machine
#set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

# (optional) add a "output" directory in the project binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# (optional) put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# add vectorDLib
message(STATUS "RatioLib cmake part ..." )
add_subdirectory(RatioLib INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/RatioLib/include) # important : other projects called by this cmake will know this include directory

# add tests
message(STATUS "tests cmake part ..." )
add_subdirectory(tests)


