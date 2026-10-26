
#ifndef LIBRARYSYSTEM_DATABASE_H
#define LIBRARYSYSTEM_DATABASE_H
#include <string>
#include <variant>
#include <vector>
#include "sqlite3.h"


/**
 * ============================================
 *        Database Requests
 * ============================================
 */
// Request Books by author, title, isbn TODO: expand this
struct BookRequest {
  enum BookLookupBy {
    AUTHOR,
    TITLE,
    ISBN
  };
  // TODO: expand this to vector for union of lookups
  BookLookupBy lookupBy;
  std::string lookupVal;
  // check for substring or for whole string match
  bool isPartial;

};

struct MemberRequest{}; // TODO: membership lookup
struct StaffRequest{}; // TODO: staff lookup

struct DBRequest {

  using RequestType = std::variant<BookRequest, MemberRequest, StaffRequest>;
  RequestType requestType;
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


class Database {
private:
  // pointer to database
  sqlite3* db_;

public:
  Database();
  ~Database();
  // receive request for data - may expand for multiple library terminals?
  DBResponse processRequest(const DBRequest& request);
private:
  DBResponse findBook(BookRequest req);
  DBResponse findMember(MemberRequest req);
  DBResponse findStaff(StaffRequest req);
  void lookupBookByAuthor(DBResponse& db_response, const std::string& value,
                          bool isPartial);
};

#endif // LIBRARYSYSTEM_DATABASE_H
