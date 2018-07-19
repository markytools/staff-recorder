#ifndef NUMPLANTILLAVACPOS_H
#define NUMPLANTILLAVACPOS_H

#include <QWidget>
#include <customqtui.h>

namespace Ui {
class NumPlantillaVacPos;
}

class NumPlantillaVacPos : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit NumPlantillaVacPos(QWidget *parent = 0);
    ~NumPlantillaVacPos();

    void setDatab(const QSqlDatabase &value);

public slots:
    void on_updateB_clicked();

private slots:
    void on_noPltPosFirstLvl_textEdited(const QString str);

    void on_noPltPosSecondLvl_textEdited(const QString str);

    void on_vanPltPosFirstLvl_textEdited(const QString str);

    void on_vanPltPosSecondLvl_textEdited(const QString str);

    void on_coterminous_textEdited(const QString str);

    void on_casual_textEdited(const QString str);

    void on_contractOfService_textEdited(const QString str);

    void on_jobOrders_textEdited(const QString str);

    void on_backB_clicked();

    void on_permMaleFirstLvl_textEdited(const QString str);

    void on_permMaleSecondLvl_textEdited(const QString str);

    void on_permFemaleFirstLvl_textEdited(const QString str);

    void on_permFemaleSecondLvl_textEdited(const QString str);

private:
    Ui::NumPlantillaVacPos *ui;
    QSqlDatabase datab;
};

#endif // NUMPLANTILLAVACPOS_H
