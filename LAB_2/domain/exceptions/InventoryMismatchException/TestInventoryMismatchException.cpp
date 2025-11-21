#include <gtest/gtest.h>
#include "domain/exceptions/InventoryMismatchException/InventoryMismatchException.h"

TEST(InventoryMismatchException, DescribesInventoryIssue) {
    InventoryMismatchException exceptionInstance("Art-5", 3, true);
    EXPECT_NE(exceptionInstance.describeIssue().find("Art-5"), std::string::npos);
    InventoryMismatchException dayInstance("Art-1", 1, false);
    EXPECT_NE(dayInstance.inventoryToken().find("day"), std::string::npos);
}