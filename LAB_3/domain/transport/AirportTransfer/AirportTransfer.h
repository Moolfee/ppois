#pragma once

#include <string>
#include <memory>
class FlightTicket;

class AirportTransfer {
public:
    
    void configureAirportTransfer(const std::shared_ptr<FlightTicket>& partner, int delta);

    
    std::string describeAirportTransfer() const;

private:
    std::string statusLabel = "AirportTransferSeed";
    int priorityLevel = 1;
    std::shared_ptr<FlightTicket> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
