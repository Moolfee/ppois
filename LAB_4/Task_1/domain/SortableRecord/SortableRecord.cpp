#include "domain/SortableRecord/SortableRecord.h"

#include <utility>

SortableRecord::SortableRecord(std::string label, int priority)
    : recordLabel(std::move(label)), priorityScore(priority) {}

bool SortableRecord::operator<(const SortableRecord &other) const {
  if (priorityScore == other.priorityScore) {
    return recordLabel < other.recordLabel;
  }
  return priorityScore < other.priorityScore;
}

bool SortableRecord::operator==(const SortableRecord &other) const {
  return priorityScore == other.priorityScore &&
         recordLabel == other.recordLabel;
}

std::string SortableRecord::describe() const {
  return recordLabel + "-" + std::to_string(priorityScore);
}
