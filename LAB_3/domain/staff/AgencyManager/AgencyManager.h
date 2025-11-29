#pragma once

#include <memory>
#include <string>
class BranchOffice;

class AgencyManager {
public:
  void configureAgencyManager(const std::shared_ptr<BranchOffice> &partner,
                              int delta);

  std::string describeAgencyManager() const;

private:
  std::string statusLabel = "AgencyManagerSeed";
  int priorityLevel = 1;
  std::shared_ptr<BranchOffice> linkedPartner = nullptr;

  std::string internalNote() const;
};
