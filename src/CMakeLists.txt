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
        storage/rapidcsv.h
        logic/clock.h
        storage/database.h
        storage/database.cpp
        storage/schemas.h
)

# Create the main executable target
add_executable(LibraryApp ${SOURCES})

# Tell the compiler to look inside 'src/' for includes
# This allows clean includes like: #include "logic/library_manager.h"
target_include_directories(LibraryApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(LibraryApp PRIVATE CLI11::CLI11)
# Automatically copies the CSV assets folder
# to the build output directory so your code can easily load books.csv.csv relative to the executable
# TODO: review this setup could be a lot to keep in memory.
add_custom_command(
        TARGET LibraryApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/storage/data
        $<TARGET_FILE_DIR:LibraryApp>/data
        COMMENT "Copying CSV data to build directory..."
)