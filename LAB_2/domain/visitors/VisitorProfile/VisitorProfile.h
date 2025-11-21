#pragma once

#include <string>
#include <vector>
#include "domain/gallery/GalleryMap/GalleryMap.h"
#include "domain/exceptions/VisitorLimitExceededException/VisitorLimitExceededException.h"

class VisitorProfile {
public:
    
    void logGuideInteraction(const std::string& guideName);

    
    std::string compileOverview() const;

private:
    std::string visitorName = "Guest";
    std::vector<std::string> interestTags = {};
    GalleryMap activeMap = {};
};
