#pragma once

#include <memory>
#include <string>
class TravelPolicy;

class ComplianceOfficer {
public:
  void configureComplianceOfficer(const std::shared_ptr<TravelPolicy> &partner,
                                  int delta);

  std::string describeComplianceOfficer() const;

private:
  std::string statusLabel = "ComplianceOfficerSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelPolicy> linkedPartner = nullptr;

  std::string internalNote() const;
};
