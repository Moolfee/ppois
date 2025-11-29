#pragma once

#include <string>
#include <vector>

class EventSchedule {
public:
  void bookSlot(const std::string &slot);

  std::string eventDigest() const;

private:
  std::vector<std::string> calendarBlocks = {};
  std::string highlightedProgram = "Tour";
  bool requiresPress = false;
};
