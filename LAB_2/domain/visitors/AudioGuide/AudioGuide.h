#pragma once

#include <string>
#include <vector>

class AudioGuide {
public:
    
    void activateNarration(int gallerySegment);

    
    std::string previewNarration() const;

private:
    std::vector<std::string> narrativeStops = {};
    std::string language = "English";
    bool adaptiveRouting = false;
};
