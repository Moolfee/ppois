#pragma once

#include <memory>
#include <string>
class TravelAgencyProfile;

class BranchOffice {
public:
  void
  configureBranchOffice(const std::shared_ptr<TravelAgencyProfile> &partner,
                        int delta);

  void rerouteCalls();

  std::string escalationPath() const;

  std::string describeBranchOffice() const;

private:
  std::string statusLabel = "BranchOfficeSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgencyProfile> linkedPartner = nullptr;
};
