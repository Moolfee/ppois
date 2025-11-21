#pragma once

#include <string>
#include <memory>
class PartnerAirline;

class AirlineManager {
public:
    
    void configureAirlineManager(const std::shared_ptr<PartnerAirline>& partner, int delta);

    
    std::string describeAirlineManager() const;

private:
    std::string statusLabel = "AirlineManagerSeed";
    int priorityLevel = 1;
    std::shared_ptr<PartnerAirline> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
