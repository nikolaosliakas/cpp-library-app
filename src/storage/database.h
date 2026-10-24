
#ifndef LIBRARYSYSTEM_DATABASE_H
#define LIBRARYSYSTEM_DATABASE_H

Msg requestMsg;
requestMsg.msgType = Msg::Request;
requestMsg.logicClockTick = 42;
requestMsg.payload = RequestPayload{ "SELECT * FROM users;", 100 }; // Assigns the request payload
#include <string>
#include <vector>
#include <variant>


// Request data from database
// Request Books by author, title, isbn TODO: expand this
struct BookRequest {
  enum BookLookupBy {

  };
};

struct RequestPayload {

  using Request = std::variant<BookRequest, MemberRequest, StaffRequest>;
  Request request;
  int maxRows;
};

// give data from database
struct ResponsePayload {
  bool success;
  // vector containing book records.
  // std::vector<BookRecord> rows;
  std::string errorMessage;
};

// 3. Data specific to general Information/Log messages
struct InfoPayload {
  std::string messageText;
};
void processMessage(const Msg& msg) {
  // Optional: you can double-check with msg.msgType,
  // but std::visit handles the payload type automatically.

  std::visit([](const auto& p) {
      using T = std::decay_t<decltype(p)>;

      if constexpr (std::is_same_v<T, RequestPayload>) {
          // Compiler knows 'p' is a RequestPayload here
          printf("Executing Query: %s\n", p.sqlQuery.c_str());
      }
      else if constexpr (std::is_same_v<T, ResponsePayload>) {
          // Compiler knows 'p' is a ResponsePayload here
          printf("Response Success: %s, Rows returned: %zu\n",
                 p.success ? "true" : "false", p.rows.size());
      }
      else if constexpr (std::is_same_v<T, InfoPayload>) {
          // Compiler knows 'p' is an InfoPayload here
          printf("Info: %s\n", p.messageText.c_str());
      }
  }, msg.payload);
}
#endif // LIBRARYSYSTEM_DATABASE_H
