#include "domain/gallery/Statue/Statue.h"


void Statue::evaluatePlacement(const ClimateControl& climate) {
    statueName = climate.compileStatus();
    balanceRating += 0.5;
    requiresHarness = balanceRating < 1.0;
    const std::string report = postureReport();
    if (report.find("Harness") != std::string::npos) { requiresHarness = true; }
}


std::string Statue::postureReport() const {
    return statueName + "-Harness:" + (requiresHarness ? "yes" : "no") + "-Balance:" + std::to_string(balanceRating);
}