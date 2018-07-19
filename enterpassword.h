#ifndef ENTERPASSWORD_H
#define ENTERPASSWORD_H

#include <QWidget>
#include <customqtui.h>
#include <QTimer>
#include <QLabel>
#include <QKeyEvent>
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
#include <QStyle>
#include <QDesktopWidget>

namespace Ui {
class EnterPassword;
}

class EnterPassword : public QWidget, public CustomQtUI
{
    Q_OBJECT

public:
    explicit EnterPassword(QWidget *parent = 0);
    ~EnterPassword();
    QSqlDatabase datab;

    void setDatab(const QSqlDatabase &value);
    void displayTimedMessage(QString message, int countdown);

protected:
    virtual bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_enterB_clicked();
    void terminateTimedMessage();

private:
    Ui::EnterPassword *ui;
    QLabel *messageLabel;
    QTimer *messageTimer;
};

#endif // ENTERPASSWORD_H
