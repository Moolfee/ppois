#include "domain/resort/ResortRoom/ResortRoom.h"

void ResortRoom::configureResortRoom(const std::shared_ptr<MealPlan> &partner,
                                     int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string ResortRoom::describeResortRoom() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
