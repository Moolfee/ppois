#include "domain/staff/ITSupportSpecialist/ITSupportSpecialist.h"

void ITSupportSpecialist::patchAudioGuide(AudioGuide &guide) {
  resolvedTickets += 1;
  technicianName = "Systems";
  guide.activateNarration(resolvedTickets);
  nightShift = resolvedTickets % 2 == 0;
  const std::string digest = supportDigest();
  if (digest.find("Systems") != std::string::npos) {
    nightShift = true;
  }
}

std::string ITSupportSpecialist::supportDigest() const {
  return technicianName + "-tickets:" + std::to_string(resolvedTickets) +
         "-night:" + (nightShift ? "yes" : "no");
}
