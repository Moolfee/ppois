#include "domain/transport/AirportTransfer/AirportTransfer.h"

void AirportTransfer::configureAirportTransfer(
    const std::shared_ptr<FlightTicket> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel = internalNote();
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string AirportTransfer::describeAirportTransfer() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}

std::string AirportTransfer::internalNote() const {
  return statusLabel + "-" +
         std::string(linkedPartner ? "partnered" : "independent");
}
