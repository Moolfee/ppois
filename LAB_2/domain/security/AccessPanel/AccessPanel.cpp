#include "domain/security/AccessPanel/AccessPanel.h"

void AccessPanel::authorizeStaff(const StaffMember &staff) {
  const std::string summary = staff.describeProfile();
  firmwareVersion = summary.empty() ? "legacy" : "v2.1";
  locked = summary.find("Guard") == std::string::npos;
  const std::string label = auditLabel();
  if (locked) {
    throw UnauthorizedAccessException(label, static_cast<int>(summary.size()),
                                      true);
  }
}

std::string AccessPanel::auditLabel() const {
  return panelLocation + "-" + firmwareVersion;
}
