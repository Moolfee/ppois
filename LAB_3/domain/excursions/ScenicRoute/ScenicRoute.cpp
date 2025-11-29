#include "domain/excursions/ScenicRoute/ScenicRoute.h"

void ScenicRoute::configureScenicRoute(
    const std::shared_ptr<ExcursionPlan> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string ScenicRoute::describeScenicRoute() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
