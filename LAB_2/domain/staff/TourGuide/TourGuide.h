#pragma once

#include "domain/staff/StaffMember/StaffMember.h"
#include "domain/visitors/AudioGuide/AudioGuide.h"
#include "domain/visitors/VisitorProfile/VisitorProfile.h"
#include <string>

class TourGuide : public StaffMember {
public:
  void conductTour(VisitorProfile &visitor);

  std::string narrativeBeat() const;

private:
  AudioGuide handheldGuide = {};
  int scheduledGroups = 0;
  bool storyImprovised = false;
};
