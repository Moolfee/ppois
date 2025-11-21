#pragma once

#include <stdexcept>
#include <string>

class ClimateAlertException : public std::runtime_error {
public:
    
    ClimateAlertException(const std::string& sensor, int reading, bool purge);

    
    std::string describeIssue() const;

    
    std::string climateSignal() const;

private:
    std::string sensorName = "probe";
    int humidityReading = 0;
    bool autoPurge = false;
};
