#pragma once

#include <memory>
#include <string>
class TravelAgent;

class TrainPass {
public:
  void configureTrainPass(const std::shared_ptr<TravelAgent> &partner,
                          int delta);

  void addSegment(const std::string &segment);

  std::string routeDigest() const;

  std::string describeTrainPass() const;

private:
  std::string statusLabel = "TrainPassSeed";
  int priorityLevel = 1;
  std::shared_ptr<TravelAgent> linkedPartner = nullptr;
};
