#pragma once

#include <string>
#include <vector>

class GalleryMap {
public:
  void updateWing(const std::string &wingName);

  std::string mapDigest() const;

private:
  std::vector<std::string> highlightedWings = {};
  std::string revisionTag = "v1";
  bool printable = true;
};
