#include "enterpassword.h"
#include "ui_enterpassword.h"

EnterPassword::EnterPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterPassword)
{
    ui->setupUi(this);

    messageTimer = new QTimer(this);
    connect(messageTimer, SIGNAL(timeout()), this, SLOT(terminateTimedMessage()));

    const QFont f1("Segoe UI", 14);
    messageLabel = new QLabel(this);
    QPalette palette = messageLabel->palette();
    palette.setColor(messageLabel->foregroundRole(), QColor("#ff0000"));
    messageLabel->setFont(f1);
    messageLabel->setText("");
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setPalette(palette);

    ui->messageForm->addRow(messageLabel);
    messageLabel->setText("");

    installEventFilter(this);
}

EnterPassword::~EnterPassword()
{
    delete ui;
}
void EnterPassword::setDatab(const QSqlDatabase &value)
{
    datab = value;
}

void EnterPassword::displayTimedMessage(QString message, int countdown)
{
    messageLabel->setText(message);
    messageTimer->start(countdown);
}

bool EnterPassword::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type()==QEvent::KeyPress) {
           QKeyEvent* key = static_cast<QKeyEvent*>(event);
           if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
               on_enterB_clicked();
           } else {
               return QObject::eventFilter(obj, event);
           }
           return true;
       } else {
           return QObject::eventFilter(obj, event);
       }
       return false;
}

void EnterPassword::on_enterB_clicked()
{
    if (ui->passwordEdit->text().isEmpty()){
        ui->passwordEdit->clear();
        displayTimedMessage("Enter a password", 3000);
        return;
    }
    datab = QSqlDatabase::addDatabase("QODBC", "Main Database");
    QString databasename = "EmployeeManagerChannel";
    datab.setDatabaseName(databasename);
    datab.setPassword(ui->passwordEdit->text());
    datab.open();
    if (datab.isOpen()){

//         *ui1 = new NewEmployee(this);
//        ui1->stackWidget = stackWidget;
//        ui1->setDatab(datab);
//         *ui2 = new (this);
//        ui2->stackWidget = stackWidget;
//        ui2->setDatab(datab);
//        PlantillaCasual *ui3 = new (this);
//        ui3->stackWidget = stackWidget;
//        ui3->setDatab(datab);
//        NumPlantillaVacPos *ui4 = new (this);
//        ui4->stackWidget = stackWidget;
//        ui4->setDatab(datab);
//        ViewEmployees *ui5 = new (this);
//        ui5->stackWidget = stackWidget;
//        ui5->setDatab(datab);
//        EmployeeManagerHome *ui6 = new (this);
//        ui6->stackWidget = stackWidget;
//        ui6->setDatab(datab);
//        ViewPlantillaPersonnels *ui7 = new (this);
//        ui7->stackWidget = stackWidget;
//        ui7->setDatab(datab);
//        ViewPlantillaCasualAppt *ui8 = new (this);
//        ui8->stackWidget = stackWidget;
//        ui8->setDatab(datab);
//        NumPlantillaVacPos *ui9 = new (this);
//        ui9->stackWidget = stackWidget;
//        ui9->setDatab(datab);
//        CustomQuery *ui10 = new (this);
//        ui10->stackWidget = stackWidget;
//        ui10->setDatab(datab);
//        EnterPassword *ui11 = new (this);
//        ui11->stackWidget = stackWidget;
//        ui11->setDatab(datab);

        NewEmployee *w0 = (NewEmployee*)(stackWidget->widget(0));
        w0->setDatab(datab);
        PlantillaPersonnel *w1 = (PlantillaPersonnel*)(stackWidget->widget(1));
        w1->setDatab(datab);
        PlantillaCasual *w2 = (PlantillaCasual*)(stackWidget->widget(2));
        w2->setDatab(datab);
        NumPlantillaVacPos *w3 = (NumPlantillaVacPos*)(stackWidget->widget(3));
        w3->setDatab(datab);
        ViewEmployees *w4 = (ViewEmployees*)(stackWidget->widget(4));
        w4->setDatab(datab);
        EmployeeManagerHome *w5 = (EmployeeManagerHome*)(stackWidget->widget(5));
        w5->setDatab(datab);
        ViewPlantillaPersonnels *w6 = (ViewPlantillaPersonnels*)(stackWidget->widget(6));
        w6->setDatab(datab);
        ViewPlantillaCasualAppt *w7 = (ViewPlantillaCasualAppt*)(stackWidget->widget(7));
        w7->setDatab(datab);
        NumPlantillaVacPos *w8 = (NumPlantillaVacPos*)(stackWidget->widget(8));
        w8->setDatab(datab);
        CustomQuery *w9 = (CustomQuery*)(stackWidget->widget(9));
        w9->setDatab(datab);
        EnterPassword *w10 = (EnterPassword*)(stackWidget->widget(10));
        w10->setDatab(datab);
        stackWidget->setCurrentIndex(5);    //DEFAULT - 5
        stackWidget->window()->resize(800, 500);
        stackWidget->window()->setGeometry(QStyle::alignedRect(Qt::LeftToRight,
                                                               Qt::AlignCenter,
                                                               stackWidget->window()->size(),
                                                               qApp->desktop()->availableGeometry()));
    }
    else {
        ui->passwordEdit->clear();
        displayTimedMessage("Incorrect password", 3000);
    }
}

void EnterPassword::terminateTimedMessage()
{
    messageLabel->setText("");
}
