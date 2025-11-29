#pragma once

#include <memory>
#include <string>
class ResortRoom;

class ResortProfile {
public:
  void configureResortProfile(const std::shared_ptr<ResortRoom> &partner,
                              int delta);

  void updateSeason(const std::string &season);

  std::string occupancySignal() const;

  std::string describeResortProfile() const;

private:
  std::string statusLabel = "ResortProfileSeed";
  int priorityLevel = 1;
  std::shared_ptr<ResortRoom> linkedPartner = nullptr;
};
