#pragma once

#include <string>
#include <vector>

class CleaningSchedule {
public:
  void assignCaretaker(const std::string &caretakerName);

  std::string outlineSanitationPlan() const;

private:
  std::vector<std::string> tasks = {};
  int assignedStaffCount = 0;
  bool overnightRequired = false;
};
