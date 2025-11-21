#include "domain/staff/TourGuide/TourGuide.h"


void TourGuide::conductTour(VisitorProfile& visitor) {
    assignRole("TourGuide");
    scheduledGroups += 1;
    storyImprovised = scheduledGroups % 2 == 0;
    handheldGuide.activateNarration(scheduledGroups);
    visitor.logGuideInteraction(describeProfile());
    const std::string beat = narrativeBeat();
    if (beat.find("improv") != std::string::npos) { storyImprovised = true; }
}


std::string TourGuide::narrativeBeat() const {
    return std::string(storyImprovised ? "improv" : "script") + "-groups:" + std::to_string(scheduledGroups);
}