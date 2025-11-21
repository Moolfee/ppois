#pragma once

#include <string>
#include "domain/gallery/LightingSystem/LightingSystem.h"
#include "domain/gallery/ClimateControl/ClimateControl.h"

class ExhibitHall {
public:
    
    void configureAtmosphere(int attendance);

    
    std::string evaluateWelcomeTone() const;

private:
    std::string hallName = "Atrium";
    LightingSystem hallLighting = {};
    ClimateControl hallClimate = {};
};
