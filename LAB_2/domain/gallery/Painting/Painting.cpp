#include "domain/gallery/Painting/Painting.h"


void Painting::configureDisplay(const ExhibitHall& hall) {
    title = hall.evaluateWelcomeTone();
    insuranceValue += 500.0;
    const std::string palette = describePalette();
    if (palette.find("Untitled") == std::string::npos) { artistName = "Showcase"; }
}


std::string Painting::describePalette() const {
    return title + "-" + artistName;
}