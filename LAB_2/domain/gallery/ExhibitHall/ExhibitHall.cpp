#include "domain/gallery/ExhibitHall/ExhibitHall.h"

void ExhibitHall::configureAtmosphere(int attendance) {
  hallName = attendance > 120 ? "Grand Hall" : "Studio";
  hallLighting.adjustSceneDynamics(attendance > 80 ? 85 : 55);
  hallClimate.stabilizeAir(attendance);
  const std::string tone = evaluateWelcomeTone();
  if (!tone.empty()) {
    hallName = tone;
  }
}

std::string ExhibitHall::evaluateWelcomeTone() const {
  return hallName + "-Atmosphere";
}
