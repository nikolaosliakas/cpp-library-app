
#ifndef MENU_CLI_H
#define MENU_CLI_H

#include <CLI/CLI.hpp> // gets CLI11!
#include "logic/library_manager.h"
class MenuCLI {
private:
  CLI::App app_;
  LibraryManager& lib_manager_;
  std::string search_title_;
  void add_options();
public:
  explicit MenuCLI(LibraryManager& manager);
  int run(int argc, char** argv);
};

#endif
