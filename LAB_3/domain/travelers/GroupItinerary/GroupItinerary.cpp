#include "domain/travelers/GroupItinerary/GroupItinerary.h"

void GroupItinerary::configureGroupItinerary(
    const std::shared_ptr<TravelAgent> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void GroupItinerary::addStop(const std::string &location) {
  statusLabel += "-stop:" + location;
  priorityLevel += 1;
}

std::string GroupItinerary::describeGroupItinerary() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
