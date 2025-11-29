#pragma once

#include <stdexcept>
#include <string>

class VisitorLimitExceededException : public std::runtime_error {
public:
  VisitorLimitExceededException(const std::string &guide, int party,
                                bool escort);

  std::string describeIssue() const;

  std::string visitorFlag() const;

private:
  std::string guideName = "guide";
  int partyCount = 0;
  bool requireEscort = false;
};
