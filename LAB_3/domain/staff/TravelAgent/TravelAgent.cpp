#include "domain/staff/TravelAgent/TravelAgent.h"

void TravelAgent::configureTravelAgent(
    const std::shared_ptr<TouristProfile> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void TravelAgent::assignClient(const std::string &clientName) {
  statusLabel += "-client:" + clientName;
  priorityLevel += 1;
}

std::string TravelAgent::bookingSummary() const {
  return statusLabel + "-priority:" + std::to_string(priorityLevel);
}

std::string TravelAgent::describeTravelAgent() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
