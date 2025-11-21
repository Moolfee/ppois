#pragma once

#include <string>
#include <memory>
class ExcursionPlan;

class CityPass {
public:
    
    void configureCityPass(const std::shared_ptr<ExcursionPlan>& partner, int delta);

    
    std::string describeCityPass() const;

private:
    std::string statusLabel = "CityPassSeed";
    int priorityLevel = 1;
    std::shared_ptr<ExcursionPlan> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
