#include "domain/exceptions/InventoryMismatchException/InventoryMismatchException.h"

InventoryMismatchException::InventoryMismatchException(
    const std::string &identifier, int count, bool overnight)
    : std::runtime_error("Inventory mismatch"), identifierToken(identifier),
      mismatchCount(count), requiresOvernight(overnight) {}

std::string InventoryMismatchException::describeIssue() const {
  return inventoryToken() + "-id:" + identifierToken;
}

std::string InventoryMismatchException::inventoryToken() const {
  return std::to_string(mismatchCount) + "-" +
         (requiresOvernight ? "overnight" : "day");
}
