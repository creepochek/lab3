// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QInputDialog>
#include <QMessageBox>
#include "Database.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    Records::Database faultDatabase;
    QPushButton *createDatabaseButton;
    QPushButton *addFaultTypeButton;
    QPushButton *solveFaultButton;
    QPushButton *changePriceButton;
    QPushButton *displayInfoButton;
    QLabel *infoLabel;

    QLineEdit *codeLineEdit;
    QLineEdit *modelCodeLineEdit;
    QLineEdit *descriptionLineEdit;
    QLineEdit *symptomsLineEdit;
    QLineEdit *repairMethodsLineEdit;
    QLineEdit *part1CodeLineEdit;
    QLineEdit *part2CodeLineEdit;
    QLineEdit *part3CodeLineEdit;
    QLineEdit *laborPriceLineEdit;

private slots:
    void createDatabase();
    void addFaultType();
    void solveFault();
    void changeLaborPrice();
    void displayFaultTypeInfo();
};

#endif // MAINWINDOW_H
