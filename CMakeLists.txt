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
# 2. Find Apache Arrow / Parquet (installed via Homebrew)
# ------------------------------------------------------------------------------
find_package(Arrow REQUIRED)
find_package(Parquet REQUIRED)

# ------------------------------------------------------------------------------
# 3. Executable Setup
# ------------------------------------------------------------------------------
# A. Header-Only / Interface Library
add_library(utils INTERFACE
        src/utils/Schemas.cpp)
target_include_directories(utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)

# B. Static Compiled Library (e.g., Database handling)
add_library(database_handling STATIC
        src/database_handling/Database.cpp
)
target_include_directories(database_handling PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/database_handling)
target_link_libraries(database_handling PRIVATE Arrow::arrow_shared Parquet::parquet_shared)

add_executable(LibrarySystem src/main.cpp)

target_link_libraries(LibrarySystem
        PRIVATE
        Crow::Crow
)

# ------------------------------------------------------------------------------
# 4. Database Path Definition
# ------------------------------------------------------------------------------
target_compile_definitions(LibrarySystem
        PRIVATE
        DATABASE_DIR="${CMAKE_SOURCE_DIR}/database"
)