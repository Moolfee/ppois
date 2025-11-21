#pragma once

#include <string>
#include <memory>
class PartnerHotel;

class HotelManager {
public:
    
    void configureHotelManager(const std::shared_ptr<PartnerHotel>& partner, int delta);

    
    std::string describeHotelManager() const;

private:
    std::string statusLabel = "HotelManagerSeed";
    int priorityLevel = 1;
    std::shared_ptr<PartnerHotel> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
