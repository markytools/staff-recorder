#ifndef VIEWPLANTILLAPERSONNELS_H
#define VIEWPLANTILLAPERSONNELS_H

#include <QWidget>
#include <customqtui.h>
#include <QMap>
#include <utils.h>
#include <plantillapersonnel.h>

namespace Ui {
class ViewPlantillaPersonnels;
}

class ViewPlantillaPersonnels : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit ViewPlantillaPersonnels(QWidget *parent = 0);
    ~ViewPlantillaPersonnels();

    void updateView();
    void setDatab(const QSqlDatabase &value);

private slots:
    void on_backB_clicked();

    void on_officeSearch_textEdited(const QString name);

    void on_editB_clicked();

    void on_plantillaPersonnelsTable_cellPressed(int row, int column);

    void on_refreshB_clicked();

    void on_deleteB_clicked();

private:
    Ui::ViewPlantillaPersonnels *ui;
    QSqlDatabase datab;
    QMap<QString, QString> pltIDMap;
    QString selectedOfficeName;
    QString selectedCertDate;
};

#endif // VIEWPLANTILLAPERSONNELS_H
