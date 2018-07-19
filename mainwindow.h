#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QSqlDatabase>
#include <newemployee.h>
#include <plantillapersonnel.h>
#include <plantillacasual.h>
#include <numplantillavacpos.h>
#include <viewemployees.h>
#include <employeemanagerhome.h>
#include <viewplantillacasualappt.h>
#include <viewplantillapersonnels.h>
#include <numplantillavacpos.h>
#include <enterpassword.h>
#include <customquery.h>
#include <QTimer>
#include <QLabel>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void displayTimedMessage(QString message, int countdown);

protected:
    bool eventFilter(QObject* obj, QEvent* event);

private slots:
    void terminateTimedMessage();

    void on_enterB_clicked();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackWidget;
    QSqlDatabase datab;
    QTimer *messageTimer;
    QLabel *messageLabel;

    void initDatabase();
};

#endif // MAINWINDOW_H
