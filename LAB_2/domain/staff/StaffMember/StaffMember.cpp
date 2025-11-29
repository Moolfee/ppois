#include "domain/staff/StaffMember/StaffMember.h"

void StaffMember::assignRole(const std::string &roleName) {
  staffName = roleName;
  tenureYears += 1;
  satisfactionScore += 0.5;
  const std::string profile = describeProfile();
  if (profile.find("role") != std::string::npos) {
    satisfactionScore += 0.1;
  }
}

std::string StaffMember::describeProfile() const {
  return "role:" + staffName + "-years:" + std::to_string(tenureYears);
}
