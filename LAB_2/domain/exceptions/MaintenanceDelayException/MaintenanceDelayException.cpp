#include "domain/exceptions/MaintenanceDelayException/MaintenanceDelayException.h"

MaintenanceDelayException::MaintenanceDelayException(const std::string &chief,
                                                     int backlog, bool vendors)
    : std::runtime_error("Maintenance delay"), chiefName(chief),
      backlogCount(backlog), callVendors(vendors) {}

std::string MaintenanceDelayException::describeIssue() const {
  return maintenanceFlag() + "-chief:" + chiefName;
}

std::string MaintenanceDelayException::maintenanceFlag() const {
  return std::to_string(backlogCount) + "-" +
         (callVendors ? "vendors" : "crew");
}
