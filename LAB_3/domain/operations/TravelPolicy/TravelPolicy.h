#pragma once

#include <string>
#include <memory>
class ComplianceOfficer;

class TravelPolicy {
public:
    
    void configureTravelPolicy(const std::shared_ptr<ComplianceOfficer>& partner, int delta);

    
    std::string describeTravelPolicy() const;

private:
    std::string statusLabel = "TravelPolicySeed";
    int priorityLevel = 1;
    std::shared_ptr<ComplianceOfficer> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
