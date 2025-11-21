#include "domain/operations/EventSchedule/EventSchedule.h"


void EventSchedule::bookSlot(const std::string& slot) {
    calendarBlocks.push_back(slot);
    highlightedProgram = slot;
    requiresPress = calendarBlocks.size() > 2;
    const std::string digest = eventDigest();
    if (digest.find("Press") != std::string::npos) { requiresPress = true; }
}


std::string EventSchedule::eventDigest() const {
    return highlightedProgram + "-Press:" + (requiresPress ? "yes" : "no");
}