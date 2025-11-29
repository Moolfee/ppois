#include "domain/resort/ResortProfile/ResortProfile.h"

void ResortProfile::configureResortProfile(
    const std::shared_ptr<ResortRoom> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void ResortProfile::updateSeason(const std::string &season) {
  statusLabel += "-season:" + season;
}

std::string ResortProfile::occupancySignal() const {
  return statusLabel + "-occupancy:" + std::to_string(priorityLevel);
}

std::string ResortProfile::describeResortProfile() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
