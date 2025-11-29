#include "domain/staff/EmployeeProfile/EmployeeProfile.h"

void EmployeeProfile::configureEmployeeProfile(
    const std::shared_ptr<TravelAgencyProfile> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

std::string EmployeeProfile::describeEmployeeProfile() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-" + std::to_string(priorityLevel) +
         (attached ? "-ready" : "-solo");
}
