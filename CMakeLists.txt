cmake_minimum_required(VERSION 3.20)



project(LibrarySystem CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# ------------------------------------------------------------------------------
# 1. Fetch Asio & Crow (Web Framework)
# ------------------------------------------------------------------------------
FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG        asio-1-30-2
)
FetchContent_MakeAvailable(asio)

set(ASIO_INCLUDE_DIR "${asio_SOURCE_DIR}/asio/include" CACHE PATH "Asio include path" FORCE)

if(NOT TARGET asio::asio)
    add_library(asio_interface INTERFACE)
    target_include_directories(asio_interface INTERFACE "${ASIO_INCLUDE_DIR}")
    add_library(asio::asio ALIAS asio_interface)
endif()

FetchContent_Declare(
        Crow
        GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
        GIT_TAG        v1.1.0
)
set(CROW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CROW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(CROW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(Crow)

# ------------------------------------------------------------------------------
# 2. Fetch Apache Arrow / Parquet
# ------------------------------------------------------------------------------
set(ARROW_WITH_SNAPPY OFF CACHE BOOL "" FORCE)
set(ARROW_COMPUTE OFF CACHE BOOL "" FORCE)
set(ARROW_DATASET OFF CACHE BOOL "" FORCE)
set(ARROW_SIMD_LEVEL "NONE" CACHE STRING "" FORCE)

set(ARROW_DEPENDENCY_SOURCE "BUNDLED" CACHE STRING "" FORCE)
set(ARROW_DEPENDENCY_USE_SHARED OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        Arrow
        GIT_REPOSITORY https://github.com/apache/arrow.git
        GIT_TAG        apache-arrow-17.0.0
        SOURCE_SUBDIR  cpp
)

set(ARROW_PARQUET ON CACHE BOOL "" FORCE)
set(ARROW_BUILD_STATIC ON CACHE BOOL "" FORCE)
set(ARROW_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(ARROW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ARROW_BUILD_INTEGRATION OFF CACHE BOOL "" FORCE)
set(ARROW_BUILD_UTILITIES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(Arrow)

# ------------------------------------------------------------------------------
# 3. Executable Setup
# ------------------------------------------------------------------------------
add_executable(LibrarySystem src/main.cpp)

target_link_libraries(LibrarySystem
        PRIVATE
        Crow::Crow
        parquet_static
        arrow_static
)

# ------------------------------------------------------------------------------
# 4. Database Path Definition
# ------------------------------------------------------------------------------
target_compile_definitions(LibrarySystem
        PRIVATE
        DATABASE_DIR="${CMAKE_SOURCE_DIR}/database"
)
