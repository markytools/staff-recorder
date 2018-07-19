#include "viewemployees.h"
#include "ui_viewemployees.h"

ViewEmployees::ViewEmployees(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewEmployees)
{
    ui->setupUi(this);

    QFont f1("Segoe UI", 11);
    f1.setBold(true);

    QTableWidgetItem *nameHeader = new QTableWidgetItem("Name");
    nameHeader->setTextAlignment(Qt::AlignCenter);
    nameHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    nameHeader->setFont(f1);
    QTableWidgetItem *addrHeader = new QTableWidgetItem("Address (Permanent)");
    addrHeader->setTextAlignment(Qt::AlignCenter);
    addrHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    addrHeader->setFont(f1);
    QTableWidgetItem *emailHeader = new QTableWidgetItem("Email");
    emailHeader->setTextAlignment(Qt::AlignCenter);
    emailHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    emailHeader->setFont(f1);
    QTableWidgetItem *celNoHeader = new QTableWidgetItem("Cellphone No.");
    celNoHeader->setTextAlignment(Qt::AlignCenter);
    celNoHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    celNoHeader->setFont(f1);
    QTableWidgetItem *lastProfUpdate = new QTableWidgetItem("Profile Last Updated");
    lastProfUpdate->setTextAlignment(Qt::AlignCenter);
    lastProfUpdate->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    lastProfUpdate->setFont(f1);

    ui->employeesListTable->setColumnCount(5);
    ui->employeesListTable->setHorizontalHeaderItem(0, nameHeader);
    ui->employeesListTable->setHorizontalHeaderItem(1, addrHeader);
    ui->employeesListTable->setHorizontalHeaderItem(2, emailHeader);
    ui->employeesListTable->setHorizontalHeaderItem(3, celNoHeader);
    ui->employeesListTable->setHorizontalHeaderItem(4, lastProfUpdate);

    ui->employeesListTable->setColumnWidth(0, 300);
    ui->employeesListTable->setColumnWidth(1, 400);
    ui->employeesListTable->setColumnWidth(2, 300);
    ui->employeesListTable->setColumnWidth(3, 200);
    ui->employeesListTable->setColumnWidth(4, 400);
    ui->employeesListTable->setSelectionBehavior(QAbstractItemView::SelectRows);
}

ViewEmployees::~ViewEmployees()
{
    delete ui;
}

void ViewEmployees::updateView()
{
    //   string databasefilename = removeLastOccurrenceStr(getCurrentFileDirector(), '\\') + "\\database.loc";
    //   cout << databasefilename << endl;
    //   string databaseLocation;
    //   ifstream nameFileout;
    //   nameFileout.open(databasefilename);
    //   getline(nameFileout, databaseLocation);
    //   nameFileout.close();
    //   cout << databaseLocation << endl;


    //   QSqlDatabase *datab = new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));
    //   QString databasename = "EmployeeManagerChannel";
    //   datab->setDatabaseName(databasename);
    //   datab->open();
    //   if (datab->isOpen()){
    //       cout << "Connection Success" << endl;
    //   }

    //   QStringList tables = datab->tables();
    //   qDebug() << tables;

    //   char c[5];
    //   generateRandStr(c, 5);
    //   QString employeeid = QString::fromStdString(string(c));

    //   QDateEdit* birthdayEdit = ui->personalInfoBox->findChild<QDateEdit*>("birthdateEdit");
    //   birthdayEdit->date().toString();

    //   QSqlQuery (datab)query;
    //       query.prepare("INSERT INTO [PERSONAL INFO] ([EMPLOYEE ID], [FIRST NAME], [MIDDLE NAME], [SURNAME], [BIRTHDATE]) "
    //                     "VALUES (:id, :firstName, :middleName, :lastName, :birthdate)");
    //       query.bindValue(":id", employeeid);
    //       query.bindValue(":firstName", ui->firstnameedit->text());
    //       query.bindValue(":middleName", ui->middlenameedit->text());
    //       query.bindValue(":lastName", ui->lastnameedit->text());
    //       query.bindValue(":birthdate", birthdayEdit->date().toString());
    //       query.exec();

    //    QSqlQuery (datab)query;
    //    query.exec("SELECT [EMPLOYEE ID], [FIRST NAME], [MIDDLE NAME], [SURNAME], [BIRTHDATE] FROM [PERSONAL INFO]");
    //    while (1) {
    //            if (query.next()){

    //            }
    //            else {
    //                query.first();
    //            }
    //            QString employeeid = query.value(0).toString();
    //            QString firsName = query.value(1).toString();
    //            QString middleName = query.value(2).toString();
    //            QString lastName = query.value(3).toString();
    //            QString birthdate = query.value(4).toString();
    //            birthdayEdit->setDate(QDate::fromString(birthdate));
    //            qDebug() << employeeid << " " << firsName << " " << middleName << " " << lastName;
    //    }


    //    bool employeeidcreated = false;
    //    char c[5];
    //    generateRandStr(c, 5);
    //    QString genemployeeid = QString::fromStdString(string(c));

    //    QSqlQuery (datab)query;
    //    query.exec("SELECT [EMPLOYEE ID] FROM [PERSONAL INFO]");


    //    while (query.next()) {
    //           QString employeeid = query.value(0).toString();
    //           if (genemployeeid == employeeid) employeeidcreated = true;
    //    }

    ui->employeesListTable->setRowCount(0);
    employeeIDMap.clear();

    QSqlQuery query(datab);
    query.exec("SELECT [EMPLOYEE ID], [FIRST NAME], [MIDDLE NAME], [SURNAME], [PERM ADDR], [EMAIL], [CELL NO], [LAST UPDATE] FROM [PERSONAL INFO]");
    while (query.next()) {
        QString employeeID = query.value(0).toString();
        QString firstName = query.value(1).toString();
        QString middleName = query.value(2).toString();
        QString lastName = query.value(3).toString();
        QString permAddr = query.value(4).toString();
        QString email = query.value(5).toString();
        QString cellNo = query.value(6).toString();
        QString lastUpdate = query.value(7).toString();

        QString middleInit = "";
        if (!middleName.isEmpty()){
            middleInit = middleName.at(0).toUpper();
            middleInit += ".";
        }
        QString fullName = firstName + " " + middleInit + " " + lastName;
        employeeIDMap[fullName] = employeeID;

        ui->employeesListTable->setRowCount(ui->employeesListTable->rowCount() + 1);

        QTableWidgetItem *fullNameItem = new QTableWidgetItem(fullName);
        fullNameItem->setTextAlignment(Qt::AlignCenter);
        fullNameItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *permAddrItem = new QTableWidgetItem(permAddr);
        permAddrItem->setTextAlignment(Qt::AlignCenter);
        permAddrItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *emailItem = new QTableWidgetItem(email);
        emailItem->setTextAlignment(Qt::AlignCenter);
        emailItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *cellNoItem = new QTableWidgetItem(cellNo);
        cellNoItem->setTextAlignment(Qt::AlignCenter);
        cellNoItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *lastUpdateItem = new QTableWidgetItem(lastUpdate);
        lastUpdateItem->setTextAlignment(Qt::AlignCenter);
        lastUpdateItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->employeesListTable->setItem(ui->employeesListTable->rowCount() - 1, 0, fullNameItem);
        ui->employeesListTable->setItem(ui->employeesListTable->rowCount() - 1, 1, permAddrItem);
        ui->employeesListTable->setItem(ui->employeesListTable->rowCount() - 1, 2, emailItem);
        ui->employeesListTable->setItem(ui->employeesListTable->rowCount() - 1, 3, cellNoItem);
        ui->employeesListTable->setItem(ui->employeesListTable->rowCount() - 1, 4, lastUpdateItem);
    }
}


void ViewEmployees::on_nameSearch_textEdited(const QString name)
{
    int rowCount = ui->employeesListTable->rowCount();
    for (int i = 0; i < rowCount; i++){
        ui->employeesListTable->setRowHidden(i, false);
    }
    for (int i = 0; i < rowCount; i++){
        if (!ifStringHasSubstring(ui->employeesListTable->item(i, 0)->text().toLower().toStdString(), name.toLower().toStdString())){
            ui->employeesListTable->setRowHidden(i, true);
        }
    }
}

void ViewEmployees::on_editB_clicked()
{
    if (!selectedFullName.isEmpty()){
        NewEmployee *newEmployee = (NewEmployee*)(stackWidget->widget(0));
        newEmployee->setMode(2);
        newEmployee->clearAll();
        newEmployee->updateFormsWithID(employeeIDMap[selectedFullName]);
        stackWidget->setCurrentIndex(0);
    }
}

void ViewEmployees::on_employeesListTable_cellPressed(int row, int column)
{
    QTableWidgetItem *item = ui->employeesListTable->item(row, 0);
    selectedFullName = item->text();
}

void ViewEmployees::on_refreshB_clicked()
{
    updateView();
}

void ViewEmployees::on_backB_clicked()
{
    stackWidget->setCurrentIndex(5);
}

void ViewEmployees::on_deleteB_clicked()
{
    if (!selectedFullName.isEmpty()){
        QString employeeID = employeeIDMap[selectedFullName];

        int rowNum = -1;
        QModelIndexList indexes = ui->employeesListTable->selectionModel()->selection().indexes();
        for (int i = 0; i < indexes.count(); ++i){
            QModelIndex index = indexes.at(i);
            rowNum = index.row();
        }
        if (rowNum != -1){
            ui->employeesListTable->removeRow(rowNum);
        }

        QSqlQuery query(datab);
        query.exec("DELETE FROM [PERSONAL INFO] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [FAMILY BGD] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [CHILDREN] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [EDU BGD] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [CIVIL SERV] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [SERVICE REC] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [VOLUNTARY WORK] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [TRAINING PROM] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [SKILL HOBBY] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [NON ACADEMIC] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [ORG MEM] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [REFERENCES] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [OTHER INFO I] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [OTHER INFO II] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [PLT CASUAL APPT] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("DELETE FROM [PLT PERSONNEL] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        employeeIDMap.remove(selectedFullName);
        updateView();
    }
}
void ViewEmployees::setDatab(const QSqlDatabase &value)
{
    datab = value;
}

