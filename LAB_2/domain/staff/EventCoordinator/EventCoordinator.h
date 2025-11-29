#pragma once

#include "domain/exceptions/SchedulingConflictException/SchedulingConflictException.h"
#include "domain/operations/EventSchedule/EventSchedule.h"
#include "domain/staff/EducationOfficer/EducationOfficer.h"
#include "domain/staff/StaffMember/StaffMember.h"
#include <string>

class EventCoordinator : public StaffMember {
public:
  void alignEducation(EducationOfficer &officer);

  std::string eventSummary() const;

private:
  EventSchedule masterSchedule = {};
  bool pressBriefed = false;
  int vendorCount = 0;
};
