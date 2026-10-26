
#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include "storage/database.h"

class LibraryManager {
private:
  // std::vector<Record> readFromDB(Request req);

  Database& database_;
public:
  explicit LibraryManager(Database& database);


};

#endif
