#include "domain/staff/TransportCoordinator/TransportCoordinator.h"

void TransportCoordinator::configureTransportCoordinator(
    const std::shared_ptr<AirportTransfer> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string TransportCoordinator::describeTransportCoordinator() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
