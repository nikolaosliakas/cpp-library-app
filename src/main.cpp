#include "presentation/menu_cli.h"

#include <iostream>
#include <string>


int main(int argc, char *argv[]) {

    std::cout << "Library App starting up!" << '\n';
    LibraryManager library_manager;
    MenuCLI menu_cli(library_manager);
    menu_cli.run(argc, argv);
    return 0;
}