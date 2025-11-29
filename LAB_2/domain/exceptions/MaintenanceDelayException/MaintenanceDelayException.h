#pragma once

#include <stdexcept>
#include <string>

class MaintenanceDelayException : public std::runtime_error {
public:
  MaintenanceDelayException(const std::string &chief, int backlog,
                            bool vendors);

  std::string describeIssue() const;

  std::string maintenanceFlag() const;

private:
  std::string chiefName = "chief";
  int backlogCount = 0;
  bool callVendors = false;
};
