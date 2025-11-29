#include "domain/operations/CleaningSchedule/CleaningSchedule.h"

void CleaningSchedule::assignCaretaker(const std::string &caretakerName) {
  tasks.push_back(caretakerName + " sweep");
  assignedStaffCount += 1;
  overnightRequired = assignedStaffCount > 2;
  const std::string plan = outlineSanitationPlan();
  if (plan.find("overnight") != std::string::npos) {
    overnightRequired = true;
  }
}

std::string CleaningSchedule::outlineSanitationPlan() const {
  const std::string lastTask = tasks.empty() ? "none" : tasks.back();
  return lastTask + "-" + std::to_string(assignedStaffCount) + "-overnight-" +
         (overnightRequired ? "true" : "false");
}
