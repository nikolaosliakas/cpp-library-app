#ifndef LIBRARYSYSTEM_SCHEMAS_H
#define LIBRARYSYSTEM_SCHEMAS_H
#include <string>
#include <unordered_map>

struct BookRecord {
  int id;
  std::string title;
  std::string author_name;
  int isbn;
  int pub_year;
  std::string publisher;
  // std::unordered_map<std::string, std::string> misc;
  std::string misc; // contains JSON
};

#endif // LIBRARYSYSTEM_SCHEMAS_H
