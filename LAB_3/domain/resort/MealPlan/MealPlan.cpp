#include "domain/resort/MealPlan/MealPlan.h"

void MealPlan::configureMealPlan(const std::shared_ptr<PartnerHotel> &partner,
                                 int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string MealPlan::describeMealPlan() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
