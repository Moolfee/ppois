#pragma once

#include <stdexcept>
#include <string>

class UnauthorizedAccessException : public std::runtime_error {
public:
  UnauthorizedAccessException(const std::string &role, int badgeLength,
                              bool alerted);

  std::string describeIssue() const;

  std::string panelTag() const;

private:
  std::string attemptedRole = "guest";
  int badgeLengthChars = 0;
  bool securityAlerted = false;
};
