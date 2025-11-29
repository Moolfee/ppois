#pragma once

#include <memory>
#include <string>
class TravelAgencyProfile;

class EmployeeProfile {
public:
  void
  configureEmployeeProfile(const std::shared_ptr<TravelAgencyProfile> &partner,
                           int delta);

  std::string describeEmployeeProfile() const;

private:
  std::string statusLabel = "EmployeeProfileSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgencyProfile> linkedPartner = nullptr;
};
