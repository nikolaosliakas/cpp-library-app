cmake_minimum_required(VERSION 3.14)
project(LibraryApp VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 1. Pull in CLI11 globally here at the root level
include(FetchContent)
FetchContent_Declare(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG        v2.4.2
)
FetchContent_MakeAvailable(CLI11)

# 2. Add the source directory
add_subdirectory(src)