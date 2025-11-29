#include "domain/excursions/ExcursionPlan/ExcursionPlan.h"

void ExcursionPlan::configureExcursionPlan(
    const std::shared_ptr<TourGuideProfile> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string ExcursionPlan::describeExcursionPlan() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
