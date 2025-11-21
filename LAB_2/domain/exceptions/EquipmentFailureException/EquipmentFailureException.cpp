#include "domain/exceptions/EquipmentFailureException/EquipmentFailureException.h"


EquipmentFailureException::EquipmentFailureException(const std::string& device, int code, bool ground) : std::runtime_error("Equipment failure"), deviceName(device), failureCode(code), requiresGrounding(ground) {
}


std::string EquipmentFailureException::describeIssue() const {
    return equipmentStamp() + "-device:" + deviceName;
}


std::string EquipmentFailureException::equipmentStamp() const {
    return std::to_string(failureCode) + "-" + (requiresGrounding ? "ground" : "observe");
}