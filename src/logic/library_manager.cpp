
#include "library_manager.h"


int LibraryManager::requestData() {
  // Load CSV file (assumes first row contains column headers)
  rapidcsv::Document doc("data/books.csv");

  // Access a cell by column name and row index
  std::string name = doc.GetCell<std::string>("author_name", 9);
  int pub_year = doc.GetCell<int>("pub_year", 9);

  std::cout << "Ninth row - Name: " << name << ", pub_year: " << pub_year << std::endl;

  // Get an entire column as a vector
  std::vector<int> pub_years = doc.GetColumn<int>("pub_year");

  return 0;
}