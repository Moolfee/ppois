#include "domain/exceptions/ClimateAlertException/ClimateAlertException.h"

ClimateAlertException::ClimateAlertException(const std::string &sensor,
                                             int reading, bool purge)
    : std::runtime_error("Climate alert: " + sensor), sensorName(sensor),
      humidityReading(reading), autoPurge(purge) {}

std::string ClimateAlertException::describeIssue() const {
  return climateSignal() + "-sensor:" + sensorName;
}

std::string ClimateAlertException::climateSignal() const {
  return std::string(autoPurge ? "PURGE" : "STABLE") + "-" +
         std::to_string(humidityReading);
}
