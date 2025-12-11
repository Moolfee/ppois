#pragma once

#include <memory>
#include <string>
class BranchOffice;

class FranchiseAgreement {
public:
  void configureFranchiseAgreement(const std::shared_ptr<BranchOffice> &partner,
                                   int delta);

  void renewAgreement(int extraYears);

  std::string describeFranchiseAgreement() const;

private:
  std::string statusLabel = "FranchiseAgreementSeed";
  int priorityLevel = 1;
  std::shared_ptr<BranchOffice> linkedPartner = nullptr;
};
