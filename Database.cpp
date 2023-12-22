// Database.cpp
#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {

Database::Database() : mNextFaultTypeCode(kFirstFaultTypeCode) {
    // Ініціалізація інших полів конструктора за необхідності
}

Database::~Database() {
    // Деструктор, видаляємо ресурси, якщо потрібно
}

FaultType& Database::addFaultType(const FaultType& newFaultType) {
    if (mFaultTypes.size() >= kMaxFaultTypes) {
        cerr << "There is no more room to add the new fault type!" << endl;
        throw exception();
    }

    mFaultTypes.push_back(newFaultType);
    return mFaultTypes.back();
}


FaultType& Database::getFaultType(std::string code) {
    for (FaultType& faultType : mFaultTypes) {
        if (faultType.getCode() == code) {
            return faultType;
        }
    }

    cerr << "No fault type with code " << code << endl;
    throw exception();
}

void Database::displayAll() {
    for (const FaultType& faultType : mFaultTypes) {
        faultType.displayInfo();
    }
}

void Database::increaseRepairPrice(std::string code, double raiseAmount) {
    FaultType& faultType = getFaultType(code);
    faultType.setLaborPrice(faultType.getLaborPrice() + raiseAmount);
}

void Database::decreaseRepairPrice(std::string code, double demeritAmount) {
    FaultType& faultType = getFaultType(code);
    double newPrice = faultType.getLaborPrice() - demeritAmount;
    if (newPrice >= 0) {
        faultType.setLaborPrice(newPrice);
    } else {
        cerr << "Error: Repair price cannot be negative." << endl;
        throw exception();
    }
}

void Database::displayFaultTypeInfo(std::string code) {
    for (const FaultType& faultType : mFaultTypes) {
        if (faultType.getCode() == code) {
            faultType.displayInfo();
            return;
        }
    }

    cerr << "No fault type with code " << code << endl;
    throw exception();
}

} // namespace Records
