
#ifndef MENU_CLI_H
#define MENU_CLI_H

#include <CLI/CLI.hpp> // gets CLI11!
#include <iostream>
#include "logic/library_manager.h"
class MenuCLI {
private:
  CLI::App app_;
  LibraryManager& lib_manager_;
  BookQuery book_query_;
  struct BookSearchParams {
    std::string author;
    std::string title;
    std::string isbn;
    bool partial;
  } book_params_;

  void add_options();
  void add_search_options();
public:
  explicit MenuCLI(LibraryManager& manager);
  int run(int argc, char** argv);
  void handle_search(char** argv);
  // void print_book_table(std::cout, *result)

};

#endif
