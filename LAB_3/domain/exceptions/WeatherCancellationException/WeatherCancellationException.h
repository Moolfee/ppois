#pragma once

#include <stdexcept>
#include <string>

class WeatherCancellationException : public std::runtime_error {
public:
    
    WeatherCancellationException(const std::string& context, int severity);

    
    std::string details() const;

private:
    std::string failingContext = "unspecified";
    int severityLevel = 0;
    double markerValue = 0.5;
};
