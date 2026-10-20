#include "presentation/menu_cli.h"

#include <iostream>
#include <string>


int main(int argc, char *argv[]) {

    std::cout << "Library App starting up!" << '\n';

    MenuCLI menu_cli;
    menu_cli.run(argc, argv);
    return 0;
}