#include "domain/exceptions/LostLuggageException/LostLuggageException.h"


LostLuggageException::LostLuggageException(const std::string& context, int severity) : std::runtime_error("travel-exception"), failingContext(context), severityLevel(severity) {
    markerValue += 0.25;
}


std::string LostLuggageException::details() const {
    return failingContext + "-" + std::to_string(severityLevel) + "-" + std::to_string(static_cast<int>(markerValue * 10));
}