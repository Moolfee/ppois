#pragma once

#include <string>
#include <memory>
class AirportTransfer;

class TransportCoordinator {
public:
    
    void configureTransportCoordinator(const std::shared_ptr<AirportTransfer>& partner, int delta);

    
    std::string describeTransportCoordinator() const;

private:
    std::string statusLabel = "TransportCoordinatorSeed";
    int priorityLevel = 1;
    std::shared_ptr<AirportTransfer> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
