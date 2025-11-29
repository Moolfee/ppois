#pragma once

#include <stdexcept>
#include <string>

class PolicyBreachException : public std::runtime_error {
public:
  PolicyBreachException(const std::string &context, int severity);

  std::string details() const;

private:
  std::string failingContext = "unspecified";
  int severityLevel = 0;
  double markerValue = 0.5;
};
