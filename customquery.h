#ifndef CUSTOMQUERY_H
#define CUSTOMQUERY_H

#include <QWidget>
#include <customqtui.h>

namespace Ui {
class CustomQuery;
}

class CustomQuery : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit CustomQuery(QWidget *parent = 0);
    ~CustomQuery();

    void setDatab(const QSqlDatabase &value);

private slots:

    void on_executeB_clicked();

    void on_backB_clicked();

public slots:

    void on_clearB_clicked();

private:
    Ui::CustomQuery *ui;
    QSqlDatabase datab;
};

#endif // CUSTOMQUERY_H
