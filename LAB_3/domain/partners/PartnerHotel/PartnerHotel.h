#pragma once

#include <string>
#include <memory>
class ResortProfile;

class PartnerHotel {
public:
    
    void configurePartnerHotel(const std::shared_ptr<ResortProfile>& partner, int delta);

    
    std::string describePartnerHotel() const;

private:
    std::string statusLabel = "PartnerHotelSeed";
    int priorityLevel = 1;
    std::shared_ptr<ResortProfile> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
