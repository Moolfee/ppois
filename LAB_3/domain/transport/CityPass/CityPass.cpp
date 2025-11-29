#include "domain/transport/CityPass/CityPass.h"

void CityPass::configureCityPass(const std::shared_ptr<ExcursionPlan> &partner,
                                 int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void CityPass::activateDay(int dayIndex) {
  statusLabel += "-day:" + std::to_string(dayIndex);
  priorityLevel += 1;
}

bool CityPass::isActive() const { return priorityLevel > 1; }

std::string CityPass::describeCityPass() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         (attached ? "-partnered" : "-independent");
}
