#ifndef VIEWPLANTILLACASUALAPPT_H
#define VIEWPLANTILLACASUALAPPT_H

#include <QWidget>
#include <customqtui.h>
#include <QMap>
#include <utils.h>
#include <plantillacasual.h>

namespace Ui {
class ViewPlantillaCasualAppt;
}

class ViewPlantillaCasualAppt : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit ViewPlantillaCasualAppt(QWidget *parent = 0);
    ~ViewPlantillaCasualAppt();

    void updateView();

    void setDatab(const QSqlDatabase &value);

private slots:
    void on_backB_clicked();

    void on_nameSearch_textEdited(const QString name);

    void on_refreshB_clicked();

    void on_deleteB_clicked();

    void on_plantillaCAppointmentsTable_cellPressed(int row, int column);

    void on_editB_clicked();

private:
    Ui::ViewPlantillaCasualAppt *ui;
    QSqlDatabase datab;
    QMap<QString, QString> pltIDMap;
    QString selectedDivName, selectedSourceFunds, selectedDatePrep;
};

#endif // VIEWPLANTILLACASUALAPPT_H
