#ifndef NEWEMPLOYEE_H
#define NEWEMPLOYEE_H

#include <QWidget>
#include <customqtui.h>
#include <QLayout>
#include <iostream>
#include <QComboBox>
#include <QLabel>
#include <QSignalMapper>
#include <utils.h>
#include <fstream>
#include <boolquery.h>
#include <math.h>
#include <QDateTime>
#include <QDateEdit>
#include <QCheckBox>
#include <QMessageBox>
#include <QScrollBar>
#include <employeemanagerhome.h>
#include <QSqlQuery>
#include <QTimer>
#include <QLabel>
using namespace std;

namespace Ui {
class NewEmployee;
}

class PresentDateData : public QObject {

public:
    QDateEdit *dateEdit;
    QCheckBox *checkBox;
    PresentDateData();
    PresentDateData(QDateEdit *&dateEdit, QCheckBox *&checkBox);
};

class NewEmployee : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit NewEmployee(QWidget *parent = 0);
    ~NewEmployee();

    void setMode(int value);
    void updateFormsWithID(QString employeeID);
    void clearAll();

    void setDatab(const QSqlDatabase &value);
    void displayTimedMessage(QString message, int countdown);

private slots:
    void on_addSpouse_clicked();
    void on_deleteSpouseB_clicked();
    void on_addChild_clicked();

    void on_deleteChild_clicked();

    void on_addEduBg_clicked();

    void on_deleteEduBg_clicked();
    void on_otherCivilStatusClicked(int state);

    void on_addCivilServB_clicked();

    void on_deleteCivilServ_clicked();

    void on_addServiceRecordB_clicked();

    void on_deleteServiceRecord_clicked();

    void on_addVWorkB_clicked();

    void on_deleteVWorkB_clicked();

    void on_addTrainingProgramB_clicked();

    void on_deleteTrainingProgramB_clicked();

    void on_addNewSkillHobbyB_clicked();

    void on_deleteSkillHobbyB_clicked();

    void on_addNonAcademicRecB_clicked();

    void on_deleteNonAcademicRecB_clicked();

    void on_adOrgMembershipB_clicked();

    void on_deleteOrgMembership_clicked();

    void on_newReferenceB_clicked();

    void on_deleteReferenceB_clicked();

    void on_question1AYesCBClicked(int state);
    void on_question1BYesCBClicked(int state);
    void on_question2AYesCBClicked(int state);
    void on_question2BYesCBClicked(int state);
    void on_question3AYesCBClicked(int state);
    void on_question4AYesCBClicked(int state);
    void on_question5AYesCBClicked(int state);
    void on_question6AYesCBClicked(int state);
    void on_question6BYesCBClicked(int state);
    void on_question6CYesCBClicked(int state);
    void terminateTimedMessage();


    void on_registerB_clicked();

    void on_feetEdit_textEdited(const QString str);

    void on_inchEdit_textEdited(const QString str);

    void on_heightEdit_textEdited(const QString str);
    void enableQDateObject(QObject *dateDataObj);

    void on_backB_clicked();

private:
    Ui::NewEmployee *ui;
    int totalSpouses, totalChildren, totalEduBg, totalCivilService, totalServiceRecord, totalVoluntaryWork, totalTrainingProg,
    totalSkills, totalNonAcademicRec, totalOrgMembership, totalReferences;
    int mode;   //0 - new, 1 - view, 2 - update

    void removeItem(QLayout *item);
    QString generateValidEmployeeID();
    QString currentEmployeeID;

    QSqlDatabase datab;
    BoolQuery *boolQuery;
    QLabel *messageLabel;
    QTimer *messageTimer;

    void addSpouse(QString firstNameV, QString lastNameV, QString middleNameV, QString occupationV, QString employerNameV,
                                QString busAddrV, QString telNoV);
    void addChild(QString childNameV, QString bDayV);
    void addEducationBG(QString levelV, QString schoolNameV, QString degreeV, QString yearGradV, QString unitsV,
                                     QString incDateFromV, QString incDateToV, QString scholarshipV);
    void addCivilService(QString careerServiceV, QString ratingV, QString dateOfExamV, QString placeOfExamV,
                                      QString licenseNumberV, QString licenseDateV);
    void addServiceRecord(QString incDateFromV, QString incDateToV, QString designationV, QString statusV, QString salaryV,
                                       QString stationV, QString branchV, QString lwPayV, QString separationDateFromV, QString separationCauseV);
    void addVoluntaryWork(QString nameAndAddrV, QString incDateFromV, QString incDateToV, QString numOfHoursV, QString posOfWorkV);
    void addTrainingProgram(QString seminarNameV, QString incDateFromV, QString incDateToV, QString numOfHoursV, QString conductedV);
    void addNewSkillHobby(QString skillHobbyV);
    void addNonAcademicRecognition(QString nonARec);
    void addOrgMembership(QString orgMembership);
    void addReference(QString nameV, QString addressV, QString telNoV);

    bool displayMsgAlertForRegUpdate(int mode);
};

#endif // NEWEMPLOYEE_H
