#ifndef PLANTILLACASUAL_H
#define PLANTILLACASUAL_H

#include <QWidget>
#include <customqtui.h>
#include <QMap>
#include <plantillapersonnel.h>
#include <utils.h>
#include <viewplantillacasualappt.h>

namespace Ui {
class PlantillaCasual;
}

class PlantillaCasual : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit PlantillaCasual(QWidget *parent = 0);
    ~PlantillaCasual();
    void updateView();
    void displayTimedMessage(QString message, int countdown);

    void setMode(int value);
    void setFieldsWithID(QString pltID, QString deptDiv, QString sourceFunds, QString datePrep);
    void clearAll();
    void refreshData();

    void setDatab(const QSqlDatabase &value);

private slots:
    void on_addB_clicked();

    void on_setEmpDataB_clicked();

    void on_employeesTable_cellPressed(int row, int column);
    void presentEmpToCBChanged(int state);
    void renewalCBChanged(int state);

    void on_editB_clicked();

    void on_updateB_clicked();

    void on_deleteB_clicked();
    void terminateTimedMessage();

    void on_searcEmployeeEdit_textEdited(const QString name);

    void on_searchPlantillaEdit_textEdited(const QString name);

    void on_saveB_clicked();

    void on_backB_clicked();

public slots:
    void on_clearFieldsB_clicked();

    void on_clearTableB_clicked();

private:
    Ui::PlantillaCasual *ui;
    QSqlDatabase datab;
    QMap<QString, QString> employeeIDMap;
    QString selectedEmployeeFullName;
    QTimer *messageTimer;
    QLabel *messageLabel;
    QString currentPltID;
    int mode;

    QString generateValidPltID();
    bool plantillaCasualDeptExist(QString deptName);
};

#endif // PLANTILLACASUAL_H
