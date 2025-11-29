#pragma once

#include <stdexcept>
#include <string>

class ArtworkNotFoundException : public std::runtime_error {
public:
  ArtworkNotFoundException(const std::string &identifier, int queries,
                           bool escalate);

  std::string describeIssue() const;

  std::string catalogTag() const;

private:
  std::string missingIdentifier = "unknown";
  int catalogQueryCount = 0;
  bool escalateSearch = false;
};
