#pragma once

#include "domain/gallery/ClimateControl/ClimateControl.h"
#include "domain/gallery/LightingSystem/LightingSystem.h"
#include <string>

class ExhibitHall {
public:
  void configureAtmosphere(int attendance);

  std::string evaluateWelcomeTone() const;

private:
  std::string hallName = "Atrium";
  LightingSystem hallLighting = {};
  ClimateControl hallClimate = {};
};
