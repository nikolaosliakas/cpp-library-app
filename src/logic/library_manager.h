
#ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include "storage/database.h"
#include<string>
class LibraryManager {
private:
  // std::vector<Record> readFromDB(Request req);


public:
  LibraryManager() = default;
  int requestData(DBRequest);

};

#endif
