#ifndef EMPLOYEEMANAGERHOME_H
#define EMPLOYEEMANAGERHOME_H

#include <QWidget>
#include <customqtui.h>
#include <newemployee.h>
#include <iostream>
#include <viewemployees.h>
#include <QTimer>
#include <plantillapersonnel.h>
#include <plantillacasual.h>
#include <viewplantillacasualappt.h>
#include <viewplantillapersonnels.h>
#include <numplantillavacpos.h>
#include <customquery.h>
using namespace std;

namespace Ui {
class EmployeeManagerHome;
}

class EmployeeManagerHome : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit EmployeeManagerHome(QWidget *parent = 0);
    ~EmployeeManagerHome();

    void displayTimedMessage(QString message, int countdown);

    void setDatab(const QSqlDatabase &value);

private slots:
    void on_newEmployee_clicked();

    void on_viewEmployees_clicked();
    void terminateTimedMessage();

    void on_newPlantillaPersonnel_clicked();

    void on_newPlantillaCasual_clicked();

    void on_viewPlantillaPersonnels_clicked();

    void on_viewPlantillaCasualAppointments_clicked();

    void on_noPlantillaVacPos_clicked();

    void on_customQuery_clicked();

private:
    Ui::EmployeeManagerHome *ui;
    QSqlDatabase datab;
    QTimer *messageTimer;
    int countdown;
    QString message;
    QLabel *messageLabel;
};

#endif // EMPLOYEEMANAGERHOME_H
