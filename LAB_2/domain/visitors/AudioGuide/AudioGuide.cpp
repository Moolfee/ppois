#include "domain/visitors/AudioGuide/AudioGuide.h"


void AudioGuide::activateNarration(int gallerySegment) {
    const std::string stopTag = "Segment-" + std::to_string(gallerySegment);
    narrativeStops.push_back(stopTag);
    language = gallerySegment % 2 == 0 ? "English" : "Spanish";
    adaptiveRouting = gallerySegment > 3;
    const std::string preview = previewNarration();
    if (preview.size() > 15) {
        adaptiveRouting = true;
    }
}


std::string AudioGuide::previewNarration() const {
    if (narrativeStops.empty()) {
        return language + "-Idle";
    }
    return language + ":" + narrativeStops.back();
}