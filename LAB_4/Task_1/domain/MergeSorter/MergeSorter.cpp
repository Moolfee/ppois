#include "domain/MergeSorter/MergeSorter.h"

namespace {
void mergeRange(int *rangeStart, int *rangeMid, int *rangeEnd) { 
  while (rangeStart < rangeMid && rangeMid < rangeEnd) {    
    if (!(*rangeMid < *rangeStart)) {
      ++rangeStart;
      continue;
    }
    int displacedValue = *rangeMid;
    
    int *shiftCursor = rangeMid;
    while (shiftCursor != rangeStart) {
      *shiftCursor = *(shiftCursor - 1);
      --shiftCursor;
    }
    *rangeStart = displacedValue;
    
    ++rangeStart;
    ++rangeMid;
  }
}

void sortRange(int *rangeStart, int *rangeEnd) {  
  const auto elementCount = rangeEnd - rangeStart;
  if (elementCount < 2) {
    return;
  } 
  int *rangeMid = rangeStart + elementCount / 2;  
  
  sortRange(rangeStart, rangeMid);
  sortRange(rangeMid, rangeEnd);
 
  mergeRange(rangeStart, rangeMid, rangeEnd);
}
} 

void MergeSorter::sortVector(std::vector<int> &items) {
  if (items.size() < 2) {
    return;
  }

  sortRange(items.data(), items.data() + static_cast<std::ptrdiff_t>(items.size()));
}
