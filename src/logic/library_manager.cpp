
#include "library_manager.h"

LibraryManager::LibraryManager(Database &database) : database_(database){ }

std::expected<std::vector<BookSummary>, LibraryError>
LibraryManager::search_books(BookQuery bq) {
  
}