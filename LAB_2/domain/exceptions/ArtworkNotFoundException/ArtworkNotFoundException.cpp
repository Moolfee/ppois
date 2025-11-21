#include "domain/exceptions/ArtworkNotFoundException/ArtworkNotFoundException.h"


ArtworkNotFoundException::ArtworkNotFoundException(const std::string& identifier, int queries, bool escalate) : std::runtime_error("Artwork not found: " + identifier), missingIdentifier(identifier), catalogQueryCount(queries), escalateSearch(escalate) {
}


std::string ArtworkNotFoundException::describeIssue() const {
    return catalogTag() + "-missing:" + missingIdentifier;
}


std::string ArtworkNotFoundException::catalogTag() const {
    return std::string(escalateSearch ? "CRITICAL" : "NOTICE") + "-" + std::to_string(catalogQueryCount);
}