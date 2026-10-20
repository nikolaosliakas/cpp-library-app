#include <CLI/CLI.hpp>
#include <string>

#include "presentation/menu_cli.h"

void MenuCLI::add_options() {
  app_.description("Library System App");
  std::string searchTitle;
  app_.add_option("-s,--search", searchTitle, "Search for a book by title");


}
int MenuCLI::run(int argc, char **argv) {
  add_options();
  app_
  return 0;
}