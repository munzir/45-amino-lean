# @author Munzir Zafar
# @date Nov 14, 2018

cmake_minimum_required(VERSION 2.6)
project(amino)

# Set the top level directory for use in the code
add_definitions(-DTOP_LEVEL_PATH="${CMAKE_SOURCE_DIR}")

# Set the C99 standard for the C files
set(CMAKE_INSTALL_PREFIX /usr)
#set(CMAKE_C_FLAGS --std=gnu99 -g)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=gnu++0x")

# Guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds are not allowed. You may need to remove CMakeCache.txt.")
endif()

# ================================================================================================
# Include and link to libraries

link_libraries(stdc++ lapack)

# ================================================================================================
# Build the codebase library and the executables

# Include the project files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Collect the source, script and fortran files
file(GLOB main_source "src/*.c" "src/*.cpp")
#set_source_files_properties("src/math.c" PROPERTIES LANGUAGE CXX)
file(GLOB scripts_source "exe/*.c" "exe/*.cpp")
list(SORT scripts_source)

# Build the library and set the executables that use it (have to hardcode for now)
add_library(amino SHARED ${main_source})

# Install
install(TARGETS amino DESTINATION /usr/local/lib)
FILE(GLOB headers "include/amino/*.h" "include/amino/*.hpp")
install(FILES ${headers} DESTINATION /usr/local/include/amino)
install(FILES "include/amino.h" DESTINATION /usr/local/include)

message(STATUS " ")
