#include "domain/exceptions/SchedulingConflictException/SchedulingConflictException.h"


SchedulingConflictException::SchedulingConflictException(const std::string& area, int vendors, bool urgent) : std::runtime_error("Scheduling conflict"), conflictArea(area), requestedVendors(vendors), urgentCall(urgent) {
}


std::string SchedulingConflictException::describeIssue() const {
    return scheduleMarker() + "-area:" + conflictArea;
}


std::string SchedulingConflictException::scheduleMarker() const {
    return std::to_string(requestedVendors) + "-" + (urgentCall ? "urgent" : "hold");
}