#pragma once

#include <string>
#include <memory>
class TravelPolicy;

class InsurancePlan {
public:
    
    void configureInsurancePlan(const std::shared_ptr<TravelPolicy>& partner, int delta);

    
    std::string describeInsurancePlan() const;

private:
    std::string statusLabel = "InsurancePlanSeed";
    int priorityLevel = 1;
    std::shared_ptr<TravelPolicy> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
