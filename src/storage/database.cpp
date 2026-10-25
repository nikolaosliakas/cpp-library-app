
#include "database.h"

#include "logic/clock.h"
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
            return DBResponse{LibClock::getInstance().requestNextTick(),false,{},""};
        }
    }, request.requestType);
  }
  DBResponse Database::findBook(BookRequest request) {
    // call CSV handler here.
    const std::vector<std::string> out = {"book", "hello", "world"};

    return {LibClock::getInstance().requestNextTick(), true, out };
  }
  DBResponse Database::findMember(MemberRequest request) {
    // call CSV handler here.
    const std::vector<std::string> out = {"member", "hello", "world"};

    return {LibClock::getInstance().requestNextTick(), true, out };

  }
DBResponse Database::findStaff(StaffRequest request) {
    // call CSV handler here.
    const std::vector<std::string> out = {"staff", "hello", "world"};

    return {LibClock::getInstance().requestNextTick(), true, out };

  }