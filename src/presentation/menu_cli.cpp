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
  add_book_search(search_cmd);

}
std::vector<BookSearchFieldFilter> MenuCLI::build_book_filters() {
  std::vector<BookSearchFieldFilter> filters;
  if (!book_params_.author.empty())
    filters.push_back({BookSearchField::AUTHOR, book_params_.author, false});
  if (!book_params_.title.empty())
    filters.push_back({BookSearchField::TITLE, book_params_.title, false});
  if (!book_params_.isbn.empty())
    filters.push_back({BookSearchField::ISBN, book_params_.isbn, false});
  if (!book_params_.author_partial.empty())
    filters.push_back({BookSearchField::AUTHOR, book_params_.author_partial, true});
  if (!book_params_.title_partial.empty())
    filters.push_back({BookSearchField::TITLE, book_params_.title_partial, true});
  return filters;
}
void MenuCLI::run_book_search() {
  std::cout << "Executing Book Search...\n";
  // TODO:validate book params like isbn;
  auto filters = build_book_filters();
}
void MenuCLI::add_book_search(CLI::App* parent) {
    auto* books_cmd = parent->add_subcommand("books", "Search books!");
    books_cmd->alias("b");

    // These are the search fields for books
    auto* author   = books_cmd->add_option("-a,--author", book_params_.author, "Search by author");
    auto* author_p = books_cmd->add_option("--author-partial", book_params_.author_partial, "Partial author search");
    auto* title    = books_cmd->add_option("-t,--title", book_params_.title, "Search by title");
    auto* title_p  = books_cmd->add_option("--title-partial", book_params_.title_partial, "Partial title search");
    // auto* isbn     = books_cmd->add_option("-i,--isbn", book_params_.isbn, "Search by ISBN");
    books_cmd->add_option("-i,--isbn", book_params_.isbn, "Search by ISBN");

    // isbn->check(CLI::Validator(
    //   [](const std::string& s) -> std::string {
    //       return is_valid_isbn(s) ? "" : "Invalid ISBN: " + s;
    //   },
    //   "ISBN"));

    author->excludes(author_p);
    title->excludes(title_p);

    books_cmd->require_option(1,0);
  books_cmd->callback([this]() {
    run_book_search();
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