#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackWidget = new QStackedWidget();

//    FormA *ui1 = new FormA(this);
//    ui1->stackWidget = stackWidget;   //Add more UI here!
    NewEmployee *ui1 = new NewEmployee(this);
    ui1->stackWidget = stackWidget;
    ui1->setDatab(datab);
    ui1->setWindowTitle("New Employee");
    PlantillaPersonnel *ui2 = new PlantillaPersonnel(this);
    ui2->stackWidget = stackWidget;
    ui2->setDatab(datab);
    ui2->setWindowTitle("Plantill Personnel");
    PlantillaCasual *ui3 = new PlantillaCasual(this);
    ui3->stackWidget = stackWidget;
    ui3->setDatab(datab);
    ui3->setWindowTitle("Plantilla Casual");
    NumPlantillaVacPos *ui4 = new NumPlantillaVacPos(this);
    ui4->stackWidget = stackWidget;
    ui4->setDatab(datab);
    ui4->setWindowTitle("Number of Plantilla Vacant Positions");
    ViewEmployees *ui5 = new ViewEmployees(this);
    ui5->stackWidget = stackWidget;
    ui5->setDatab(datab);
    ui5->setWindowTitle("View Employees");
    EmployeeManagerHome *ui6 = new EmployeeManagerHome(this);
    ui6->stackWidget = stackWidget;
    ui6->setDatab(datab);
    ui6->setWindowTitle("Home");
    ViewPlantillaPersonnels *ui7 = new ViewPlantillaPersonnels(this);
    ui7->stackWidget = stackWidget;
    ui7->setDatab(datab);
    ui7->setWindowTitle("View Plantilla Personnels");
    ViewPlantillaCasualAppt *ui8 = new ViewPlantillaCasualAppt(this);
    ui8->stackWidget = stackWidget;
    ui8->setDatab(datab);
    ui8->setWindowTitle("View Plantilla Casual Appointments");
    NumPlantillaVacPos *ui9 = new NumPlantillaVacPos(this);
    ui9->stackWidget = stackWidget;
    ui9->setDatab(datab);
    ui9->setWindowTitle("Number of Plantilla Vacant Positions");
    CustomQuery *ui10 = new CustomQuery(this);
    ui10->stackWidget = stackWidget;
    ui10->setDatab(datab);
    ui10->setWindowTitle("Custom Query");
    EnterPassword *ui11 = new EnterPassword(this);
    ui11->stackWidget = stackWidget;
    ui11->setDatab(datab);
    ui11->setWindowTitle("Staff Record");

    stackWidget->addWidget(ui1);
    stackWidget->addWidget(ui2);
    stackWidget->addWidget(ui3);
    stackWidget->addWidget(ui4);
    stackWidget->addWidget(ui5);
    stackWidget->addWidget(ui6);
    stackWidget->addWidget(ui7);
    stackWidget->addWidget(ui8);
    stackWidget->addWidget(ui9);
    stackWidget->addWidget(ui10);
    stackWidget->addWidget(ui11);
    stackWidget->setCurrentIndex(10);    //DEFAULT - 5
    setWindowTitle("Staff Record");

    setCentralWidget(stackWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayTimedMessage(QString message, int countdown)
{
    messageLabel->setText(message);
    messageTimer->start(countdown);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
}

void MainWindow::terminateTimedMessage()
{
    messageLabel->setText("");
}

void MainWindow::initDatabase()
{

}

void MainWindow::on_enterB_clicked()
{

}
