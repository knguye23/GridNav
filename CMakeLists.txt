cmake_minimum_required(VERSION 3.10)
project(GridNav)

set(CMAKE_CXX_STANDARD 17)

# Include all .cpp files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add executable
add_executable(simulation ${SOURCES})

# Include directories
target_include_directories(simulation PRIVATE src)