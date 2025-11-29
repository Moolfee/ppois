#pragma once

#include <memory>
#include <string>
class ComplianceOfficer;

class TravelPolicy {
public:
  void configureTravelPolicy(const std::shared_ptr<ComplianceOfficer> &partner,
                             int delta);

  void enforceCompliance();

  void relaxPolicy();

  std::string describeTravelPolicy() const;

private:
  std::string statusLabel = "TravelPolicySeed";
  int priorityLevel = 1;
  std::shared_ptr<ComplianceOfficer> linkedPartner = nullptr;
};
