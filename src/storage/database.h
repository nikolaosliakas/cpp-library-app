
#ifndef LIBRARYSYSTEM_DATABASE_H
#define LIBRARYSYSTEM_DATABASE_H
#include <string>
#include "search.h"
#include "sqlite3.h"





class Database {
private:
  // pointer to database
  sqlite3* db_;

public:
  Database();
  ~Database();
  // receive request for data - may expand for multiple library terminals?
//   DBResponse processRequest(const BookQuery& request);
// private:
//   DBResponse findBook(BookQuery req);
//   DBResponse findMember(MemberRequest req);
//   DBResponse findStaff(StaffRequest req);
//   void lookupBookByAuthor(DBResponse& db_response, const std::string& value,
//                           bool isPartial);
};

#endif // LIBRARYSYSTEM_DATABASE_H
