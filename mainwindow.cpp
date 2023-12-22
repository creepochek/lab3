// mainwindow.cpp
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createDatabaseButton = new QPushButton("Create Database", this);
    addFaultTypeButton = new QPushButton("Add Fault Type", this);
    infoLabel = new QLabel("Database not created", this);
    solveFaultButton = new QPushButton("Mark as Solved", this);
    changePriceButton = new QPushButton("Change Labor Price", this);
    displayInfoButton = new QPushButton("Display Fault Type Info", this);

    // Новые QLineEdit для ввода данных
    codeLineEdit = new QLineEdit(this);
    modelCodeLineEdit = new QLineEdit(this);
    descriptionLineEdit = new QLineEdit(this);
    symptomsLineEdit = new QLineEdit(this);
    repairMethodsLineEdit = new QLineEdit(this);
    part1CodeLineEdit = new QLineEdit(this);
    part2CodeLineEdit = new QLineEdit(this);
    part3CodeLineEdit = new QLineEdit(this);
    laborPriceLineEdit = new QLineEdit(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(createDatabaseButton);
    layout->addWidget(infoLabel);
    layout->addWidget(addFaultTypeButton);
    layout->addWidget(solveFaultButton);
    layout->addWidget(changePriceButton);
    layout->addWidget(displayInfoButton);

    // Добавляем новые QLineEdit в макет
    layout->addWidget(codeLineEdit);
    layout->addWidget(modelCodeLineEdit);
    layout->addWidget(descriptionLineEdit);
    layout->addWidget(symptomsLineEdit);
    layout->addWidget(repairMethodsLineEdit);
    layout->addWidget(part1CodeLineEdit);
    layout->addWidget(part2CodeLineEdit);
    layout->addWidget(part3CodeLineEdit);
    layout->addWidget(laborPriceLineEdit);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(createDatabaseButton, &QPushButton::clicked, this, &MainWindow::createDatabase);
    connect(addFaultTypeButton, &QPushButton::clicked, this, &MainWindow::addFaultType);
    connect(solveFaultButton, &QPushButton::clicked, this, &MainWindow::solveFault);
    connect(changePriceButton, &QPushButton::clicked, this, &MainWindow::changeLaborPrice);
    connect(displayInfoButton, &QPushButton::clicked, this, &MainWindow::displayFaultTypeInfo);
}

void MainWindow::createDatabase()
{
    try {
        faultDatabase = Records::Database();
        infoLabel->setText("Database created successfully");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", "Failed to create the database. " + QString(e.what()));
    }
}

void MainWindow::addFaultType() {
    // Создаем объект FaultType с введенными данными
    Records::FaultType newFaultType = Records::FaultType::readFaultTypeFromGUI(
        codeLineEdit, modelCodeLineEdit, descriptionLineEdit,
        symptomsLineEdit, repairMethodsLineEdit,
        part1CodeLineEdit, part2CodeLineEdit, part3CodeLineEdit,
        laborPriceLineEdit);

    // Добавляем объект в базу данных
    faultDatabase.addFaultType(newFaultType);
    QMessageBox::information(this, "Успішно", "Запис успішно додано в базу даних!");
}

void MainWindow::solveFault()
{
    // Введите код неисправности
    QString code = QInputDialog::getText(this, "Enter Fault Code", "Fault Code:");

    // Получите объект FaultType из базы данных
    Records::FaultType& fault = faultDatabase.getFaultType(code.toStdString());

    // Установите флаг решенности
    fault.setIsSolved(true);

    // Вывод сообщения об успешном решении
    QMessageBox::information(this, "Success", "Fault marked as solved.");
}

void MainWindow::changeLaborPrice()
{
    // Введите код неисправности
    QString code = QInputDialog::getText(this, "Enter Fault Code", "Fault Code:");

    // Получите объект FaultType из базы данных
    Records::FaultType& fault = faultDatabase.getFaultType(code.toStdString());

    // Введите новую цену
    bool ok;
    double newPrice = QInputDialog::getDouble(this, "Enter New Labor Price", "New Labor Price:", 0, 0, 100000, 2, &ok);

    // Если пользователь не отменил ввод
    if (ok) {
        // Установите новую цену
        fault.setLaborPrice(newPrice);

        // Вывод сообщения об успешном изменении цены
        QMessageBox::information(this, "Success", "Labor price changed successfully.");
    }
}

void MainWindow::displayFaultTypeInfo()
{
    // Введите код неисправности
    QString code = QInputDialog::getText(this, "Enter Fault Code", "Fault Code:");

    // Получите объект FaultType из базы данных
    Records::FaultType& fault = faultDatabase.getFaultType(code.toStdString());

    // Вывод информации о неисправности
    fault.displayInfo();
}
