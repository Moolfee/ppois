#pragma once

#include "domain/gallery/GalleryMap/GalleryMap.h"
#include <string>
#include <vector>

class PatrolRoutePlanner {
public:
  void integrateMap(const GalleryMap &map);

  std::string routeDigest() const;

private:
  std::vector<std::string> checkpoints = {};
  int revisionNumber = 0;
  bool loopPreferred = true;
};
