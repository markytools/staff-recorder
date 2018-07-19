#ifndef CUSTOMQTUI_H
#define CUSTOMQTUI_H

#include <QStackedWidget>
#include <QGridLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class CustomQtUI
{

protected:
    void remove(QGridLayout *layout, int row, int column, bool deleteWidgets);
    void deleteChildWidgets(QLayoutItem *item);
    void removeRow(QGridLayout *&layout, int row, bool deleteWidgets);
    void removeColumn(QGridLayout *&layout, int column, bool deleteWidgets);

public:
    CustomQtUI();
    QStackedWidget *stackWidget;
};

#endif // CUSTOMQTUI_H
