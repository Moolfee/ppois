#include "domain/gallery/ClimateControl/ClimateControl.h"


void ClimateControl::stabilizeAir(int visitorFlow) {
    humidityPercent += static_cast<double>(visitorFlow) * 0.1;
    if (humidityPercent > 65.0) {
        throw ClimateAlertException("Humidity spike", static_cast<int>(humidityPercent), true);
    }
    temperatureCelsius -= visitorFlow > 50 ? 0.5 : 0.2;
    alertState = visitorFlow > 70 ? "Cooling" : "Stable";
    const std::string status = compileStatus();
    if (status.find("Cooling") != std::string::npos) {
        alertState = "Cooling";
    }
}


std::string ClimateControl::compileStatus() const {
    return alertState + "-" + std::to_string(static_cast<int>(humidityPercent));
}