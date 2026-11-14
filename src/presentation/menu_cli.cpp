#include <CLI/CLI.hpp>
#include <string>

#include "presentation/menu_cli.h"

MenuCLI::MenuCLI(LibraryManager& manager)
    : lib_manager_(manager) {}

void MenuCLI::add_search_options() {

  /* ------------------------------------------------------------
 * L1 - "search cmd"
 * ------------------------------------------------------------
 */
  auto* search_cmd = app_.add_subcommand("search", "Search operations.");
  search_cmd->alias("s"); // s flag for shorthand
  search_cmd->require_subcommand(1); // you need to specify a search category or an error is thrown.
  /* ------------------------------------------------------------
   * L2 - "search cmd" Books, Staff, Members
   * ------------------------------------------------------------
   */
  auto* books_cmd = search_cmd->add_subcommand("books", "Search books!");
  books_cmd->alias("b");

  // These are the search fields for books
  books_cmd->add_option("-a,--author", book_params_.author, "Search by author");
  books_cmd->add_option("-t,--title", book_params_.title, "Search by title");
  books_cmd->add_option("-i,--isbn", book_params_.isbn, "Search by isbn");

  books_cmd->add_option("--author-partial", book_params_.author_partial, "Search by author, partial search!");
  books_cmd->add_option("--title-partial", book_params_.title_partial, "Search by title, partial search");




  // if (book_params_.author.empty() && book_params_.title.empty() && book_params_.isbn.empty()) {
  //   throw CLI::ValidationError("search books", "specify at lease one search field!");
  // }
  if (!book_params_.author.empty() && !book_params_.author_partial.empty()) {
    throw CLI::ValidationError("search books", "You cannot combine a whole author search with a partial author search. Please select one!");
  }
  if (!book_params_.title.empty() && !book_params_.title_partial.empty()) {
    throw CLI::ValidationError("search books", "You cannot combine a whole title search with a partial title search. Please select one!");
  }


  books_cmd->callback([&]() {
    std::cout << "Executing Book Search...\n";
    if (!book_params_.author.empty()) {
      std::cout << "  Author: " << book_params_.author << "\n";
    }
    if (!book_params_.title.empty()) {
      std::cout << "  Title: " << book_params_.title << "\n";
    }
    if (!book_params_.isbn.empty()) {
      std::cout << "  ISBN: " << book_params_.isbn << "\n";
    }
    if (!book_params_.author_partial.empty()) {
      std::cout << "  Partial Author: " << book_params_.author_partial << "\n";
    }
    if (!book_params_.title_partial.empty()) {
      std::cout << "  Partial Title: " << book_params_.title_partial << "\n";
    }

  });

}
void MenuCLI::add_options() {
  app_.description("Library System App");
  app_.require_subcommand(1); // requires top level command like search!
  add_search_options();
}

int MenuCLI::run(int argc, char **argv) {

  add_options();

    try {
      app_.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
      return app_.exit(e);
    }



  return 0;
}