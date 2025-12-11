#include "domain/transport/ShuttleService/ShuttleService.h"

void ShuttleService::configureShuttleService(
    const std::shared_ptr<AirportTransfer> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void ShuttleService::logRide(const std::string &rideId) {
  statusLabel += "-ride:" + rideId;
  priorityLevel += 1;
}

std::string ShuttleService::describeShuttleService() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
