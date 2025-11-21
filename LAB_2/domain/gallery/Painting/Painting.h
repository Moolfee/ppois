#pragma once

#include <string>
#include "domain/gallery/ExhibitHall/ExhibitHall.h"

class Painting {
public:
    
    void configureDisplay(const ExhibitHall& hall);

    
    std::string describePalette() const;

private:
    std::string title = "Untitled";
    std::string artistName = "Unknown";
    double insuranceValue = 10000.0;
};
