// FaultType.cpp
#include "FaultType.h"
#include <iostream>

namespace Records {

    FaultType::FaultType(std::string code, std::string modelCode, std::string description,
                         std::string symptoms, std::string repairMethods,
                         std::string part1Code, std::string part2Code, std::string part3Code, double laborPrice)
        : solved(false), code(code), modelCode(modelCode), description(description),
          symptoms(symptoms), repairMethods(repairMethods),
          part1Code(part1Code), part2Code(part2Code), part3Code(part3Code), laborPrice(laborPrice) {}

    void FaultType::displayInfo() const {
        QString info;
        info += "Код виду: " + QString::fromStdString(code) + "\n";
        info += "Код моделі: " + QString::fromStdString(modelCode) + "\n";
        info += "Опис: " + QString::fromStdString(description) + "\n";
        info += "Симптоми: " + QString::fromStdString(symptoms) + "\n";
        info += "Методи ремонту: " + QString::fromStdString(repairMethods) + "\n";
        info += "Код запчастини 1: " + QString::fromStdString(part1Code) + "\n";
        info += "Код запчастини 2: " + QString::fromStdString(part2Code) + "\n";
        info += "Код запчастини 3: " + QString::fromStdString(part3Code) + "\n";
        info += "Ціна роботи: $" + QString::number(laborPrice) + "\n";
        info += QString("Вирішено: ") + (solved ? "так" : "ні");

        // Используем QMessageBox для вывода информации
        QMessageBox::information(nullptr, "Fault Type Information", info);
    }

    FaultType FaultType::readFaultTypeFromGUI(QLineEdit* codeLineEdit, QLineEdit* modelCodeLineEdit,
                                              QLineEdit* descriptionLineEdit, QLineEdit* symptomsLineEdit,
                                              QLineEdit* repairMethodsLineEdit, QLineEdit* part1CodeLineEdit,
                                              QLineEdit* part2CodeLineEdit, QLineEdit* part3CodeLineEdit,
                                              QLineEdit* laborPriceLineEdit) {
        std::string code = codeLineEdit->text().toStdString();
        std::string modelCode = modelCodeLineEdit->text().toStdString();
        std::string description = descriptionLineEdit->text().toStdString();
        std::string symptoms = symptomsLineEdit->text().toStdString();
        std::string repairMethods = repairMethodsLineEdit->text().toStdString();
        std::string part1Code = part1CodeLineEdit->text().toStdString();
        std::string part2Code = part2CodeLineEdit->text().toStdString();
        std::string part3Code = part3CodeLineEdit->text().toStdString();
        double laborPrice = laborPriceLineEdit->text().toDouble();

        // Создание объекта FaultType с введенными данными
        return FaultType(code, modelCode, description, symptoms, repairMethods,
                         part1Code, part2Code, part3Code, laborPrice);
    }

    void FaultType::setLaborPrice(double newLaborPrice) {
        laborPrice = newLaborPrice;
    }

    double FaultType::getLaborPrice() const {
        return laborPrice;
    }

    std::string FaultType::getCode() const {
        return code;
    }

    void FaultType::setIsSolved(bool isSolved) {
        solved = isSolved;
    }

    void FaultType::displaySolvedStatus() const {
        std::cout << "Вирішено: " << (solved ? "так" : "ні") << std::endl;
    }


} // namespace Records
