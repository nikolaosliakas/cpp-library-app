
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
    std::string author_partial;
    std::string title;
    std::string title_partial;
    std::string isbn;

  } book_params_;

  void add_options();
  void add_search_options();
  void add_book_search(CLI::App*);
  std::vector<BookSearchFieldFilter> build_book_filters() const;
  void run_book_search();
public:
  explicit MenuCLI(LibraryManager& manager);
  int run(int argc, char** argv);
  void handle_search(char** argv);
  // void print_book_table(std::cout, *result)

};

#endif
