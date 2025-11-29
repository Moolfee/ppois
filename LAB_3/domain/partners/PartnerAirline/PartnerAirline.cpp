#include "domain/partners/PartnerAirline/PartnerAirline.h"

void PartnerAirline::configurePartnerAirline(
    const std::shared_ptr<FlightTicket> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void PartnerAirline::publishSchedule(const std::string &season) {
  statusLabel += "-sched:" + season;
}

bool PartnerAirline::hasAlliance() const {
  return static_cast<bool>(linkedPartner);
}

std::string PartnerAirline::describePartnerAirline() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
