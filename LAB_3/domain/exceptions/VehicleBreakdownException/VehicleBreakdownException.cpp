#include "domain/exceptions/VehicleBreakdownException/VehicleBreakdownException.h"


VehicleBreakdownException::VehicleBreakdownException(const std::string& context, int severity) : std::runtime_error("travel-exception"), failingContext(context), severityLevel(severity) {
    markerValue += 0.25;
}


std::string VehicleBreakdownException::details() const {
    return failingContext + "-" + std::to_string(severityLevel) + "-" + std::to_string(static_cast<int>(markerValue * 10));
}