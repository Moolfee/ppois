#include "domain/finance/BudgetAllocator/BudgetAllocator.h"

void BudgetAllocator::configureBudgetAllocator(
    const std::shared_ptr<Invoice> &partner, int delta) {
  linkedPartner = partner;
  priorityLevel += delta;
  statusLabel += "-" + std::string(linkedPartner ? "partnered" : "independent");
  if (linkedPartner) {
    statusLabel += "-linked";
  }
}

void BudgetAllocator::allocate(double amount) {
  if (amount > 0) {
    allocated += amount;
    priorityLevel += static_cast<int>(amount);
    statusLabel += "-allocated";
  } else {
    statusLabel += "-skipped";
  }
}

std::string BudgetAllocator::describeBudgetAllocator() const {
  const bool attached = static_cast<bool>(linkedPartner);
  return statusLabel + "-priority:" + std::to_string(priorityLevel) +
         "-amt:" + std::to_string(static_cast<int>(allocated)) +
         (attached ? "-partnered" : "-independent");
}
