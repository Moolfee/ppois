#pragma once

#include <string>
#include <memory>
class FrequentFlyerAccount;

class LoyaltyProgram {
public:
    
    void configureLoyaltyProgram(const std::shared_ptr<FrequentFlyerAccount>& partner, int delta);

    
    std::string describeLoyaltyProgram() const;

private:
    std::string statusLabel = "LoyaltyProgramSeed";
    int priorityLevel = 1;
    std::shared_ptr<FrequentFlyerAccount> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
