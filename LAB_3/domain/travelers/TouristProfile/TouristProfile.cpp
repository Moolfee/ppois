#include "domain/travelers/TouristProfile/TouristProfile.h"

void TouristProfile::configureTouristProfile(
    const std::shared_ptr<InsurancePlan> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string TouristProfile::describeTouristProfile() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
