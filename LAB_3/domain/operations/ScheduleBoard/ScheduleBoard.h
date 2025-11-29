#pragma once

#include <memory>
#include <string>
class TrainPass;

class ScheduleBoard {
public:
  void configureScheduleBoard(const std::shared_ptr<TrainPass> &partner,
                              int delta);

  std::string describeScheduleBoard() const;

private:
  std::string statusLabel = "ScheduleBoardSeed";
  int priorityLevel = 1;
  std::shared_ptr<TrainPass> linkedPartner = nullptr;

  std::string internalNote() const;
};
