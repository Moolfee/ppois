#pragma once

#include <string>
#include "domain/exceptions/ClimateAlertException/ClimateAlertException.h"

class ClimateControl {
public:
    
    void stabilizeAir(int visitorFlow);

    
    std::string compileStatus() const;

private:
    double humidityPercent = 45.0;
    double temperatureCelsius = 21.5;
    std::string alertState = "Stable";
};
