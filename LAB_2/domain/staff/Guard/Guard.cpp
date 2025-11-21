#include "domain/staff/Guard/Guard.h"


void Guard::resolveIncident(IncidentLogger& logger) {
    assignRole("Guard");
    alertnessScore += 10;
    armored = true;
    logger.captureIncident("Guard resolved");
    const std::string plannerDigest = assignedPlanner.routeDigest();
    if (plannerDigest.empty()) { alertnessScore += 2; }
    const std::string summary = guardSummary();
    if (summary.find("LOW") != std::string::npos) { alertnessScore += 5; }
}


std::string Guard::guardSummary() const {
    const std::string level = alertnessScore < 40 ? "LOW" : "HIGH";
    return level + "-" + std::to_string(alertnessScore);
}