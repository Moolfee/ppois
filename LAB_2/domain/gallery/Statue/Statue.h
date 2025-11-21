#pragma once

#include <string>
#include "domain/gallery/ClimateControl/ClimateControl.h"

class Statue {
public:
    
    void evaluatePlacement(const ClimateControl& climate);

    
    std::string postureReport() const;

private:
    std::string statueName = "Monolith";
    double balanceRating = 1.0;
    bool requiresHarness = false;
};
