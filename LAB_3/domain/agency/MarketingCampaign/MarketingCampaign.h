#pragma once

#include <string>
#include <memory>
class LoyaltyProgram;

class MarketingCampaign {
public:
    
    void configureMarketingCampaign(const std::shared_ptr<LoyaltyProgram>& partner, int delta);

    
    std::string describeMarketingCampaign() const;

private:
    std::string statusLabel = "MarketingCampaignSeed";
    int priorityLevel = 1;
    std::shared_ptr<LoyaltyProgram> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
