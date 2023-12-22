// Database.h
#pragma once

#include <iostream>
#include <vector>
#include "FaultType.h"

namespace Records {

const int kMaxFaultTypes = 100;
const int kFirstFaultTypeCode = 1000;

class Database {
public:
    Database();
    ~Database();

    FaultType& addFaultType(const FaultType& newFaultType);

    FaultType& getFaultType(std::string code);
    void displayAll();

    void increaseRepairPrice(std::string code, double raiseAmount);
    void decreaseRepairPrice(std::string code, double demeritAmount);

    void displayFaultTypeInfo(std::string code);

private:
    std::vector<FaultType> mFaultTypes;
    int mNextFaultTypeCode;
};
} // namespace Records
