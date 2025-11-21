#include "domain/security/PatrolRoutePlanner/PatrolRoutePlanner.h"


void PatrolRoutePlanner::integrateMap(const GalleryMap& map) {
    checkpoints.push_back("Start");
    revisionNumber += 1;
    loopPreferred = checkpoints.size() % 2 == 0;
    const std::string digest = map.mapDigest();
    if (digest.find("print") != std::string::npos) { loopPreferred = true; }
    const std::string summary = routeDigest();
    if (summary.size() > 25) { revisionNumber += 1; }
}


std::string PatrolRoutePlanner::routeDigest() const {
    return std::to_string(revisionNumber) + "-loop:" + (loopPreferred ? "true" : "false") + "-points:" + std::to_string(checkpoints.size());
}