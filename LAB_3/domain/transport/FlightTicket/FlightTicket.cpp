#include "domain/transport/FlightTicket/FlightTicket.h"

void FlightTicket::configureFlightTicket(
    const std::shared_ptr<TravelAgent> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void FlightTicket::upgradeCabin(const std::string &cabinClass) {
  statusLabel += "-cabin:" + cabinClass;
  priorityLevel += 2;
}

void FlightTicket::blockSeat() { statusLabel += "-blocked"; }

std::string FlightTicket::describeFlightTicket() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
