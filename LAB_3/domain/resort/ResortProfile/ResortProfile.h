#pragma once

#include <string>
#include <memory>
class ResortRoom;

class ResortProfile {
public:
    
    void configureResortProfile(const std::shared_ptr<ResortRoom>& partner, int delta);

    
    std::string describeResortProfile() const;

private:
    std::string statusLabel = "ResortProfileSeed";
    int priorityLevel = 1;
    std::shared_ptr<ResortRoom> linkedPartner = nullptr;
    
    std::string internalNote() const;
};
