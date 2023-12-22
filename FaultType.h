// FaultType.h
#ifndef FAULTTYPE_H
#define FAULTTYPE_H

#include <string>
#include <QLineEdit>  // Добавьте эту строку
#include <QMessageBox>

namespace Records {

class FaultType {
private:
    bool solved;
    std::string code;
    std::string modelCode;
    std::string description;
    std::string symptoms;
    std::string repairMethods;
    std::string part1Code;
    std::string part2Code;
    std::string part3Code;
    double laborPrice;

public:
    FaultType(std::string code, std::string modelCode, std::string description,
              std::string symptoms, std::string repairMethods,
              std::string part1Code, std::string part2Code, std::string part3Code, double laborPrice);

    static FaultType readFaultTypeFromGUI(QLineEdit* codeLineEdit, QLineEdit* modelCodeLineEdit,
                                          QLineEdit* descriptionLineEdit, QLineEdit* symptomsLineEdit,
                                          QLineEdit* repairMethodsLineEdit, QLineEdit* part1CodeLineEdit,
                                          QLineEdit* part2CodeLineEdit, QLineEdit* part3CodeLineEdit,
                                          QLineEdit* laborPriceLineEdit);
    void displayInfo() const;
    void setLaborPrice(double newLaborPrice);
    double getLaborPrice() const;
    std::string getCode() const;
    bool getIsSolved() const;
    void setIsSolved(bool isSolved);
    void displaySolvedStatus() const;
};

} // namespace Records

#endif // FAULTTYPE_H
