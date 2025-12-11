#pragma once

#include <memory>
#include <string>
class Invoice;

class BudgetAllocator {
public:
  void configureBudgetAllocator(const std::shared_ptr<Invoice> &partner,
                                int delta);

  void allocate(double amount);

  std::string describeBudgetAllocator() const;

private:
  std::string statusLabel = "BudgetAllocatorSeed";
  int priorityLevel = 1;
  double allocated = 0.0;
  std::shared_ptr<Invoice> linkedPartner = nullptr;
};
