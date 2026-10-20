include(FetchContent)
FetchContent_Declare(
        CLI11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG        v2.4.2   # You can use any recent stable release tag
)
FetchContent_MakeAvailable(CLI11)

set(SOURCES
        main.cpp

        # Presentation Layer
        presentation/menu_cli.cpp
        presentation/menu_cli.h

        # Logic Layer
        logic/library_manager.cpp
        logic/library_manager.h

        # Storage Layer
        storage/csv_handler.cpp
        storage/csv_handler.h
)

# Create the main executable target
add_executable(LibraryApp ${SOURCES})

# Tell the compiler to look inside 'src/' for includes
# This allows clean includes like: #include "business/library_manager.h"
target_include_directories(LibraryApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Automatically copies the CSV assets folder
# to the build output directory so your code can easily load books.csv relative to the executable
# TODO: review this setup could be a lot to keep in memory.
add_custom_command(
        TARGET LibraryApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/storage/assets
        $<TARGET_FILE_DIR:LibraryApp>/assets
        COMMENT "Copying CSV assets to build directory..."
)