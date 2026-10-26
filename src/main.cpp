#include "presentation/menu_cli.h"

#include <iostream>
#include <string>


int main(int argc, char *argv[]) {

    std::cout << "Library App starting up!" << '\n';
    Database database{};
    LibraryManager library_manager(database);
    MenuCLI menu_cli(library_manager);
    menu_cli.run(argc, argv);
    return 0;
}