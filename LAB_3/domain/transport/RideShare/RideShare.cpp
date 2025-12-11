#include "domain/transport/RideShare/RideShare.h"

void RideShare::configureRideShare(
    const std::shared_ptr<FlightTicket> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void RideShare::schedulePickup(const std::string &pickupCode) {
  statusLabel += "-pickup:" + pickupCode;
  priorityLevel += 1;
}

std::string RideShare::describeRideShare() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
