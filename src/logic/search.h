#ifndef LIBRARYSYSTEM_SEARCH_H
#define LIBRARYSYSTEM_SEARCH_H
#include <variant>
#include <vector>
#include <string>
#include <chrono>
/**
 * ============================================
 *        Database Requests
 * ============================================
 */


// Request Books by author, title, isbn TODO: expand this
enum class BookSearchField {
  AUTHOR,
  TITLE,
  ISBN
};

struct BookSearchPayload {
  BookSearchField field;
  std::string value;
  bool partial = false;
};
struct BookQuery{
  // TODO: convert to logical clock when dist system has settled.
  std::chrono::time_point<std::chrono::system_clock> t_point_sent;
  std::vector<BookSearchPayload> payload;
};

struct MemberRequest{}; // TODO: membership lookup
struct StaffRequest{}; // TODO: staff lookup

struct SearchQuery {

  using SearchType = std::variant<BookQuery, MemberRequest, StaffRequest>;
  SearchType requestType;
};
/**
 * ============================================
 *        Database Responses
 * ============================================
 */
// give data from database
struct DBResponse {

  bool success;
  // vector containing book records.
  std::vector<std::string> rows;
  std::string errorMessage; // should be an optional based on success.
};

// Database Status Information - to give to logic - delete if unused.
struct InfoPayload {
  std::string messageText;
};

#endif // LIBRARYSYSTEM_SEARCH_H
