#include <iostream>
#include "database.h"
#include "sqlite3.h"

  Database::Database() {
    // Creates or assigns database.
    sqlite3_open("library_system.db", &db_);
  }
Database::~Database() {
    sqlite3_close(db_);
  }

  DBResponse Database::processRequest(const DBRequest& request) {

    return std::visit([this](const auto& req) -> DBResponse {
        using T = std::decay_t<decltype(req)>;

        if constexpr (std::is_same_v<T, BookRequest>) {
            return findBook(req);
        }
        else if constexpr (std::is_same_v<T, MemberRequest>) {
            return findMember(req);
        }
        else if constexpr (std::is_same_v<T, StaffRequest>) {
            return findStaff(req);
        }
        else {
            // Fallback required so all paths return a DBResponse
            return DBResponse{false,{},""};
        }
    }, request.requestType);
  }

  void Database::lookupBookByAuthor(DBResponse& response, const std::string& value, const bool isPartial) {

    sqlite3_stmt* stmt;
    if (isPartial) {
      sqlite3_prepare_v2(db_, "SELECT * FROM books WHERE author_name LIKE %?%", -1, &stmt, nullptr);
    } else {
      sqlite3_prepare_v2(db_, "SELECT * FROM books WHERE author_name = ?", -1, &stmt, nullptr);
    }

    sqlite3_bind_text(stmt, 1, value.c_str(), -1, SQLITE_TRANSIENT);
    int rc = sqlite3_step(stmt);
    while (rc == SQLITE_ROW) {
      // 1. Extract columns using 0-based indices
      int id = sqlite3_column_int(stmt, 0);

      // sqlite3_column_text returns a pointer to unsigned char, cast it to char* for std::string
      std::string title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
      std::string author = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
      std::string isbn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

      int pub_year = sqlite3_column_int(stmt, 4);
      std::string publisher = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
      std::string misc_json = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));

      rc = sqlite3_step(stmt);

    }
    sqlite3_finalize(stmt);

  }
  DBResponse Database::findBook(BookRequest request) {
    DBResponse response{};
    switch (request.lookupBy) {
      case(BookRequest::AUTHOR): {
        lookupBookByAuthor(response, request.lookupVal, request.isPartial);
        break;
      }
    case(BookRequest::TITLE): {
        break;
    }
    case(BookRequest::ISBN): {
        break;
    }

      default: {
        std::cout << "Can only lookup book by author, title and isbn!\n";
      }
    }
    const std::vector<std::string> out = {"book", "hello", "world"};

    return { true, out };
  }
  DBResponse Database::findMember(MemberRequest request) {
    // call CSV handler here.
    const std::vector<std::string> out = {"member", "hello", "world"};

    return {true, out };

  }
DBResponse Database::findStaff(StaffRequest request) {
    // call CSV handler here.
    const std::vector<std::string> out = {"staff", "hello", "world"};

    return {true, out };

  }