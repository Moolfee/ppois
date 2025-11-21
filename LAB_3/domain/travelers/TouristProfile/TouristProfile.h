#pragma once

#include <string>
#include <memory>
class InsurancePlan;

class TouristProfile {
public:
    
    void configureTouristProfile(const std::shared_ptr<InsurancePlan>& partner, int delta);

    
    std::string describeTouristProfile() const;

private:
    std::string statusLabel = "TouristProfileSeed";
    int priorityLevel = 1;
    std::shared_ptr<InsurancePlan> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
