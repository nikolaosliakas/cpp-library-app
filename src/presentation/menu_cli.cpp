#include <CLI/CLI.hpp>
#include <string>

#include "presentation/menu_cli.h"

MenuCLI::MenuCLI(LibraryManager& manager)
    : lib_manager_(manager) {}

void MenuCLI::add_options() {
  app_.description("Library System App");

  // Pass variable reference directly
  app_.add_option("-s,--search", search_title_, "Search for a book by title");
}

int MenuCLI::run(int argc, char **argv) {
  add_options();

  try {
    app_.parse(argc, argv);
  } catch (const CLI::ParseError &e) {
    return app_.exit(e);
  }

  // Check if option was passed on CLI
  if (app_.count("--search") > 0) {
    std::cout << "[CLI] Searching for title: " << search_title_ << "\n";
    // lib_manager_.search_by_title(search_title_);
  }

  return 0;
}