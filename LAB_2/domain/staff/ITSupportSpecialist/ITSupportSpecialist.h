#pragma once

#include "domain/visitors/AudioGuide/AudioGuide.h"
#include <string>

class ITSupportSpecialist {
public:
  void patchAudioGuide(AudioGuide &guide);

  std::string supportDigest() const;

private:
  std::string technicianName = "HelpDesk";
  int resolvedTickets = 0;
  bool nightShift = false;
};
