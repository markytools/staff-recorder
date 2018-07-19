#include "employeemanagerhome.h"
#include "ui_employeemanagerhome.h"

EmployeeManagerHome::EmployeeManagerHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeManagerHome)
{
    ui->setupUi(this);

    messageTimer = new QTimer(this);
    connect(messageTimer, SIGNAL(timeout()), this, SLOT(terminateTimedMessage()));



    const QFont f1("Segoe UI", 14);
    messageLabel = new QLabel(this);
    QPalette palette = messageLabel->palette();
    palette.setColor(messageLabel->foregroundRole(), QColor("#016700"));
    messageLabel->setFont(f1);
    messageLabel->setText(message);
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setPalette(palette);

    ui->messageForm->addRow(messageLabel);
    messageLabel->setText("");
}

EmployeeManagerHome::~EmployeeManagerHome()
{
    delete ui;
}

void EmployeeManagerHome::displayTimedMessage(QString message, int countdown)
{
    this->message = message;
    this->countdown = countdown;

    messageLabel->setText(message);
    messageTimer->start(countdown);
}



void EmployeeManagerHome::on_newEmployee_clicked()
{
    NewEmployee *newEmployee = (NewEmployee*)(stackWidget->widget(0));
    newEmployee->setMode(0);
    newEmployee->clearAll();
    stackWidget->setCurrentIndex(0);
}

void EmployeeManagerHome::on_viewEmployees_clicked()
{
    ViewEmployees *viewEmployees = (ViewEmployees*)(stackWidget->widget(4));
    viewEmployees->updateView();
    stackWidget->setCurrentIndex(4);
}

void EmployeeManagerHome::terminateTimedMessage()
{
    messageLabel->setText("");
}

void EmployeeManagerHome::on_newPlantillaPersonnel_clicked()
{
    PlantillaPersonnel *plantillaPersonnel = (PlantillaPersonnel*)(stackWidget->widget(1));
    plantillaPersonnel->setMode(0);
    plantillaPersonnel->clearAll();
    plantillaPersonnel->updateViews();
    stackWidget->setCurrentIndex(1);
    stackWidget->window()->showMaximized();
}

void EmployeeManagerHome::on_newPlantillaCasual_clicked()
{
    PlantillaCasual *plantillaCasual = (PlantillaCasual*)(stackWidget->widget(2));
    plantillaCasual->setMode(0);
    plantillaCasual->clearAll();
    plantillaCasual->updateView();
    stackWidget->setCurrentIndex(2);
    stackWidget->window()->showMaximized();
}

void EmployeeManagerHome::on_viewPlantillaPersonnels_clicked()
{
    ViewPlantillaPersonnels *viewPPersonnel = (ViewPlantillaPersonnels*)(stackWidget->widget(6));
    viewPPersonnel->updateView();
    stackWidget->setCurrentIndex(6);
}

void EmployeeManagerHome::on_viewPlantillaCasualAppointments_clicked()
{
    ViewPlantillaCasualAppt *viewPCAppointments = (ViewPlantillaCasualAppt*)(stackWidget->widget(7));
    viewPCAppointments->updateView();
    stackWidget->setCurrentIndex(7);
}

void EmployeeManagerHome::on_noPlantillaVacPos_clicked()
{
    NumPlantillaVacPos *numPltPos = (NumPlantillaVacPos*)(stackWidget->widget(8));
    numPltPos->on_updateB_clicked();
    stackWidget->setCurrentIndex(8);
}

void EmployeeManagerHome::on_customQuery_clicked()
{
    CustomQuery *customQuery = (CustomQuery*)(stackWidget->widget(9));
    customQuery->on_clearB_clicked();
    stackWidget->setCurrentIndex(9);
}
void EmployeeManagerHome::setDatab(const QSqlDatabase &value)
{
    datab = value;
}

