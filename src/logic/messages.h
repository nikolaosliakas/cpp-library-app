#ifndef LIBRARYSYSTEM_MESSAGES_H
#define LIBRARYSYSTEM_MESSAGES_H
#include <string>
#include <vector>
#include <variant>
#include "storage/database.h"


struct Msg {

  // Order/priority and key to find timestamps in clock log.
  int logicClockTick;

  // A variant can hold EXACTLY ONE of these types at any given time
  using Payload = std::variant<RequestPayload, ResponsePayload, InfoPayload>;
  Payload payload;

};

#endif // LIBRARYSYSTEM_MESSAGES_H
