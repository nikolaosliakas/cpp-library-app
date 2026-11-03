
#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include "search.h"

#include "storage/database.h"
#include <vector>

class LibraryManager {
private:
  // std::vector<Record> readFromDB(Request req);

  Database& database_;
public:
  explicit LibraryManager(Database& database);
  //
  // std::expected<std::vector<BookSummary>>,LibraryError> search_books(BookQuery title);

};

#endif
