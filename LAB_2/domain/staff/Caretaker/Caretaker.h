#pragma once

#include "domain/gallery/Painting/Painting.h"
#include "domain/operations/CleaningSchedule/CleaningSchedule.h"
#include "domain/staff/StaffMember/StaffMember.h"
#include <string>

class Caretaker : public StaffMember {
public:
  void refreshPainting(Painting &painting);

  std::string caretakerNote() const;

private:
  CleaningSchedule cleaningPlan = {};
  bool ladderCertified = false;
  int completedRounds = 0;
};
