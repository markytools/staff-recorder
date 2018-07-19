#ifndef PLANTILLAPERSONNEL_H
#define PLANTILLAPERSONNEL_H

#include <QWidget>
#include <customqtui.h>
#include <QMap>
#include <QVector>
#include <QSqlQuery>
#include <utils.h>
#include <QLabel>
#include <QTimer>
#include <boolquery.h>
#include <employeemanagerhome.h>
#include <viewplantillapersonnels.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <QtXlsx>
using namespace std;

struct ServiceRecData {
    QString dateFrom;
    QString dateTo;
    QString designation;
    QString status;
};

class PlantillaPersonnelRowData {
public:
    bool doublePositionLayer();
    void setLevel(QString level); //set with ui.combobox
    void setDateOfBirth(QDate date);
    void setDateOfAppt(QDate date);
    void setDateOfProm(QDate date);
    void adjustForRealAndVacantIncum();

    PlantillaPersonnelRowData();
    bool isDoubleLayered;   //default false
    QString itemNo;
    QString position, position2;
    QString level;
    QString sg;
    QString nameOfIncumbent;
    QString gender;
    QString dateOfBirth;
    QString dateOfAppt;
    QString dateOfProm;
    QString empStatus;
    QString edu;
    QString elig;
    int excelRowNum;
};

namespace Ui {
class PlantillaPersonnel;
}

class PlantillaPersonnel : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit PlantillaPersonnel(QWidget *parent = 0);
    ~PlantillaPersonnel();

    void updateViews();

    void setMode(int value);
    void displayTimedMessage(QString message, int countdown);
    void setFieldsWithID(QString pltID, QString officeName, QString dateCorrected);
    void clearAll();
    void refreshData();
    void setPrintedOfficeName(QString officeName);

    void setDatab(const QSqlDatabase &value);
    void updateItemNumbers();

private slots:
    void on_setEmployeeID_clicked();

    void on_employeesTable_cellPressed(int row, int column);

    void on_addB_clicked();

    void on_deleteB_clicked();

    void on_searchEmployeeEdit_textEdited(const QString name);

    void on_searchPlantillaEdit_textEdited(const QString name);

    void on_editB_clicked();

    void on_updateB_clicked();

    void on_saveB_clicked();
    void terminateTimedMessage();

    void on_backB_clicked();

    void on_openExcelB_clicked();
    void messageReceived();

public slots:
    void on_clearB_clicked();

    void on_clearFields_clicked();

private:
    Ui::PlantillaPersonnel *ui;
    QSqlDatabase datab;
    QSqlDatabase pltPersonnelDtb;
    QMap<QString, QString> employeeIDMap;
    QString selectedEmployeeFullName;
    int mode = 0; //0 - normal/delete, 1 - add, 2 - edit
    QTimer *messageTimer;
    QLabel *messageLabel;
    QString currentPltID;
    QString generateValidPltID();
    QProcess *myProcess;

    bool plantillaPersonnelOfficeExist(QString officeName);
    void updatePltPersonnelDetails(string certifiedDate, string approvedByName, string approvedByPos, string signatureByName,
                                   string signatureByPos);
    void savePlantillaPersonnel(bool goBackToViewPltPersonnel);
};

#endif // PLANTILLAPERSONNEL_H
