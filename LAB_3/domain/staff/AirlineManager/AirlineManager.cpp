#include "domain/staff/AirlineManager/AirlineManager.h"

void AirlineManager::configureAirlineManager(
    const std::shared_ptr<PartnerAirline> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string AirlineManager::describeAirlineManager() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
