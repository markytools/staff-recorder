#ifndef VIEWEMPLOYEES_H
#define VIEWEMPLOYEES_H

#include <QWidget>
#include <customqtui.h>
#include <string>
#include <utils.h>
#include <QMap>
#include <newemployee.h>
namespace Ui {
class ViewEmployees;
}

class ViewEmployees : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit ViewEmployees(QWidget *parent = 0);
    ~ViewEmployees();

    void updateView();

    void setDatab(const QSqlDatabase &value);

private slots:
    void on_nameSearch_textEdited(const QString name);

    void on_editB_clicked();
    void on_employeesListTable_cellPressed(int row, int column);

    void on_refreshB_clicked();

    void on_backB_clicked();

    void on_deleteB_clicked();

private:
    Ui::ViewEmployees *ui;
    QSqlDatabase datab;
    QMap<QString, QString> employeeIDMap;
    QString selectedFullName;
};

#endif // VIEWEMPLOYEES_H
