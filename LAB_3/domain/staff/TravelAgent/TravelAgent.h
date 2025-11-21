#pragma once

#include <string>
#include <memory>
class TouristProfile;

class TravelAgent {
public:
    
    void configureTravelAgent(const std::shared_ptr<TouristProfile>& partner, int delta);

    
    std::string describeTravelAgent() const;

private:
    std::string statusLabel = "TravelAgentSeed";
    int priorityLevel = 1;
    std::shared_ptr<TouristProfile> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
