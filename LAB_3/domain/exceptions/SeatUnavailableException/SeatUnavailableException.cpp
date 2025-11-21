#include "domain/exceptions/SeatUnavailableException/SeatUnavailableException.h"


SeatUnavailableException::SeatUnavailableException(const std::string& context, int severity) : std::runtime_error("travel-exception"), failingContext(context), severityLevel(severity) {
    markerValue += 0.25;
}


std::string SeatUnavailableException::details() const {
    return failingContext + "-" + std::to_string(severityLevel) + "-" + std::to_string(static_cast<int>(markerValue * 10));
}