set(SOURCES
        main.cpp

        # Presentation Layer
        presentation/menu_cli.cpp
        presentation/menu_cli.h

        # Logic Layer
        logic/library_manager.cpp
        logic/library_manager.h

        # Storage Layer
        storage/database.h
        storage/database.cpp
        storage/schemas.h
)

# Create the main executable target
add_executable(LibraryApp ${SOURCES})
find_package(SQLite3 REQUIRED)
# Tell the compiler to look inside 'src/' for includes
# This allows clean includes like: #include "logic/library_manager.h"
target_include_directories(LibraryApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(LibraryApp PRIVATE CLI11::CLI11)
target_link_libraries(LibraryApp PRIVATE SQLite::SQLite3)

