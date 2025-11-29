#pragma once

#include <string>

class StaffMember {
public:
  void assignRole(const std::string &roleName);

  std::string describeProfile() const;

private:
  std::string staffName = "Onboarding";
  int tenureYears = 0;
  double satisfactionScore = 1.0;
};
