#include "domain/staff/EventCoordinator/EventCoordinator.h"

void EventCoordinator::alignEducation(EducationOfficer &officer) {
  assignRole("Coordinator");
  vendorCount += 1;
  masterSchedule.bookSlot("Lecture");
  pressBriefed = vendorCount > 2;
  const std::string snapshot = officer.educationSnapshot();
  if (vendorCount > 4) {
    throw SchedulingConflictException("Vendors", vendorCount, true);
  }
  const std::string summary = eventSummary();
  if (summary.find("Coord") != std::string::npos) {
    pressBriefed = true;
  }
}

std::string EventCoordinator::eventSummary() const {
  return "Coord-" + std::to_string(vendorCount) +
         "-Press:" + (pressBriefed ? "yes" : "no");
}
