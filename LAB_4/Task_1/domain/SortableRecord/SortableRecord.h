#pragma once

#include <string>

class SortableRecord {
public:
  SortableRecord() = default;
  SortableRecord(std::string label, int priority);

  bool operator<(const SortableRecord &other) const;
  bool operator==(const SortableRecord &other) const;

  std::string describe() const;

private:
  std::string recordLabel = "record";
  int priorityScore = 0;
};
