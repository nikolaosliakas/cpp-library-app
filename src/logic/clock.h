
#ifndef LIBRARYSYSTEM_CLOCK_H
#define LIBRARYSYSTEM_CLOCK_H

#include <vector>
#include <mutex>
#include <chrono>

class LibClock {
public:
  struct LogEntry {
    int tick;
    std::chrono::system_clock::time_point time_stamp;
  };
private:
  int current_tick = 0;
  std::vector<LogEntry> time_log;
  mutable std::mutex mtx;

  LibClock() = default;

public:
  LibClock(const LibClock&) = delete;
  LibClock& operator=(const LibClock&) = delete;

  static LibClock& getInstance() {
    // value initialised only once
    static LibClock instance;
    return instance;
  }

  int requestNextTick() {
    // grab the mutex and pass it to reference to the guard;
    std::lock_guard<std::mutex> lock(mtx);
    // CRITICAL SECTION
    current_tick++;
    auto now = std::chrono::system_clock::now();
    time_log.push_back({current_tick, now});
    return current_tick;
  }
  std::vector<LogEntry> getLog() const {
    std::lock_guard<std::mutex> lock(mtx);
    return time_log;
  }
};


#endif // LIBRARYSYSTEM_CLOCK_H
