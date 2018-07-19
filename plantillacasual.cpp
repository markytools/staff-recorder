#include "plantillacasual.h"
#include "ui_plantillacasual.h"

PlantillaCasual::PlantillaCasual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlantillaCasual)
{
    ui->setupUi(this);


    messageTimer = new QTimer(this);
    connect(messageTimer, SIGNAL(timeout()), this, SLOT(terminateTimedMessage()));

    const QFont f1("Segoe UI", 14);
    messageLabel = new QLabel(this);
    QPalette palette = messageLabel->palette();
    palette.setColor(messageLabel->foregroundRole(), QColor("#016700"));
    messageLabel->setFont(f1);
    messageLabel->setText("");
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setPalette(palette);
    messageLabel->setWordWrap(true);

    ui->messageForm->addRow(messageLabel);
    messageLabel->setText("");

    ui->employeesTable->setColumnWidth(0, 200);
    ui->plantillaCasualTable->setColumnWidth(0, 200);
    ui->plantillaCasualTable->setColumnWidth(1, 200);
    ui->plantillaCasualTable->setColumnWidth(2, 100);
    ui->plantillaCasualTable->setColumnWidth(3, 100);
    ui->plantillaCasualTable->setColumnWidth(4, 150);
    ui->plantillaCasualTable->setColumnWidth(5, 300);
    ui->plantillaCasualTable->setColumnWidth(6, 300);
    ui->plantillaCasualTable->setColumnWidth(7, 500);
    ui->employeesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->plantillaCasualTable->setSelectionBehavior(QAbstractItemView::SelectRows);


    ui->dailyWageEdit->setValidator( new QDoubleValidator(0, 10000, 2, this));

    connect(ui->presentEmpToCB, SIGNAL(stateChanged(int)), this, SLOT(presentEmpToCBChanged(int)));
    connect(ui->noRenewalCB, SIGNAL(stateChanged(int)), this, SLOT(renewalCBChanged(int)));
}

PlantillaCasual::~PlantillaCasual()
{
    delete ui;
}

void PlantillaCasual::updateView()
{

    ui->employeesTable->setRowCount(0);
    employeeIDMap.clear();

//    QString employeeID;
//    QString firstName;
//    QString middleName;
//    QString lastName;
//    QString gender;
//    QString birthDate;
//    QString dateOrigAppt;
//    QString dateLastProm;
//    QString status;
//    QVector<QString> education;
//    QVector<QString> eligibility;

    QSqlQuery query(datab);
    query.exec("SELECT [EMPLOYEE ID], [FIRST NAME], [MIDDLE NAME], [SURNAME] FROM [PERSONAL INFO]");
    while (query.next()) {
        QString employeeID = query.value(0).toString();
        QString firstName = query.value(1).toString();
        QString middleName = query.value(2).toString();
        QString lastName = query.value(3).toString();

        QString middleInit = "";
        if (!middleName.isEmpty()){
            middleInit = middleName.at(0).toUpper();
            middleInit += ".";
        }
        QString fullName = firstName + " " + middleInit + " " + lastName;
        employeeIDMap[fullName] = employeeID;

        ui->employeesTable->setRowCount(ui->employeesTable->rowCount() + 1);

        QTableWidgetItem *fullNameItem = new QTableWidgetItem(fullName);
        fullNameItem->setTextAlignment(Qt::AlignCenter);
        fullNameItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->employeesTable->setItem(ui->employeesTable->rowCount() - 1, 0, fullNameItem);
    }
}

void PlantillaCasual::displayTimedMessage(QString message, int countdown)
{
    messageLabel->setText(message);
    messageTimer->start(countdown);
}


void PlantillaCasual::on_addB_clicked()
{
    for (int i = 0; i < ui->plantillaCasualTable->rowCount(); i++){
        QTableWidgetItem *item = ui->plantillaCasualTable->item(i, 0);
        if (item->text().toUpper() != QString("vacant").toUpper() && item->text() == ui->nameAppointeeEdit->text()){
            displayTimedMessage("Employee\nalready in\nlist!", 3000);
            return;
        }
    }
    if (!ui->nameAppointeeEdit->text().isEmpty()){
        ui->plantillaCasualTable->setRowCount(ui->plantillaCasualTable->rowCount() + 1);

        QTableWidgetItem *posItem = new QTableWidgetItem(ui->positionEdit->text());
        posItem->setTextAlignment(Qt::AlignCenter);
        posItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *levelItem = new QTableWidgetItem(ui->levelEdit->currentText());
        levelItem->setTextAlignment(Qt::AlignCenter);
        levelItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *sgItem = new QTableWidgetItem(ui->sgEdit->text());
        sgItem->setTextAlignment(Qt::AlignCenter);
        sgItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *nameItem = new QTableWidgetItem(ui->nameAppointeeEdit->text());
        nameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *dailyWagesItem = new QTableWidgetItem(ui->dailyWageEdit->text());
        dailyWagesItem->setTextAlignment(Qt::AlignCenter);
        dailyWagesItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *empFromItem = new QTableWidgetItem(ui->empFromEdit->date().toString());
        empFromItem->setTextAlignment(Qt::AlignCenter);
        empFromItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *empToItem = new QTableWidgetItem(ui->presentEmpToCB->isChecked() ? "PRESENT" : ui->empToEdit->date().toString());
        empToItem->setTextAlignment(Qt::AlignCenter);
        empToItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *renewalItem = new QTableWidgetItem(ui->noRenewalCB->isChecked() ? "NONE" : ui->renewalEdit->date().toString());
        renewalItem->setTextAlignment(Qt::AlignCenter);
        renewalItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 0, nameItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 1, posItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 2, levelItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 3, sgItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 4, dailyWagesItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 5, empFromItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 6, empToItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 7, renewalItem);
    }
}

void PlantillaCasual::on_setEmpDataB_clicked()
{
    if (!selectedEmployeeFullName.isEmpty()){
        QString employeeID = employeeIDMap[selectedEmployeeFullName];

        QString firstName;
        QString middleName;
        QString lastName;
        QString position;
        QString level;
        QString sg;
        float dailyWage;
        QString empFrom;
        QString empTo;
        QString renewalDate;

        QSqlQuery query(datab);
        query.exec("SELECT [FIRST NAME], [MIDDLE NAME], [SURNAME] FROM [PERSONAL INFO] WHERE "
                   "[EMPLOYEE ID] = '" + employeeID + "'");
        while (query.next()) {
            firstName = query.value(0).toString();
            middleName = query.value(1).toString();
            lastName = query.value(2).toString();
        }

        query.clear();
        query.exec("SELECT [INC DATE FROM], [INC DATE TO], [STATUS], [DESIGNATION] FROM [SERVICE REC] WHERE "
                   "[EMPLOYEE ID] = '" + employeeID + "'");
        QVector<ServiceRecData> serviceData;
        while (query.next()) {
            ServiceRecData sData;
            sData.dateFrom = query.value(0).toString();
            sData.dateTo = query.value(1).toString();
            sData.status = query.value(2).toString();
            sData.designation = query.value(3).toString();

            serviceData.push_back(sData);
        }

        for (ServiceRecData sData : serviceData){
            if (sData.dateTo == "PRESENT"){
                position = sData.designation;
                break;
            }
        }

        ui->nameAppointeeEdit->setText(selectedEmployeeFullName);
        ui->positionEdit->setText(position);
    }
}

void PlantillaCasual::on_employeesTable_cellPressed(int row, int column)
{
    QTableWidgetItem *item = ui->employeesTable->item(row, 0);
    selectedEmployeeFullName = item->text();
}

void PlantillaCasual::presentEmpToCBChanged(int state)
{
    if (state == Qt::Unchecked){
        ui->empToEdit->setDisabled(false);
    }
    else if (state == Qt::Checked){
        ui->empToEdit->setDisabled(true);
    }
}

void PlantillaCasual::renewalCBChanged(int state)
{
    if (state == Qt::Unchecked){
        ui->renewalEdit->setDisabled(false);
    }
    else if (state == Qt::Checked){
        ui->renewalEdit->setDisabled(true);
    }
}

void PlantillaCasual::on_editB_clicked()
{
    int rowNum = -1;
    QModelIndexList indexes = ui->plantillaCasualTable->selectionModel()->selection().indexes();
    for (int i = 0; i < indexes.count(); ++i){
        QModelIndex index = indexes.at(i);
        rowNum = index.row();
    }
    if (rowNum != -1){
        ui->nameAppointeeEdit->setText(ui->plantillaCasualTable->item(rowNum, 0)->text());
        ui->positionEdit->setText(ui->plantillaCasualTable->item(rowNum, 1)->text());
        ui->levelEdit->setCurrentText(ui->plantillaCasualTable->item(rowNum, 2)->text());
        ui->sgEdit->setText(ui->plantillaCasualTable->item(rowNum, 3)->text());
        ui->dailyWageEdit->setText(ui->plantillaCasualTable->item(rowNum, 4)->text());
        ui->empFromEdit->setDate(QDate::fromString(ui->plantillaCasualTable->item(rowNum, 5)->text()));

        QString empToStr = ui->plantillaCasualTable->item(rowNum, 6)->text();
        if (empToStr == "PRESENT"){
            ui->presentEmpToCB->setChecked(true);
        }
        else {
            ui->empToEdit->setDate(QDate::fromString(empToStr));
            ui->presentEmpToCB->setChecked(false);
        }
        presentEmpToCBChanged(ui->presentEmpToCB->isChecked());

        QString renewalStr = ui->plantillaCasualTable->item(rowNum, 7)->text();
        if (renewalStr == "NONE"){
            ui->noRenewalCB->setChecked(true);
        }
        else {
            ui->renewalEdit->setDate(QDate::fromString(renewalStr));
            ui->noRenewalCB->setChecked(false);
        }
        renewalCBChanged(ui->noRenewalCB->isChecked());
    }
}

void PlantillaCasual::on_clearFieldsB_clicked()
{
    ui->nameAppointeeEdit->clear();
    ui->positionEdit->clear();
    ui->sgEdit->clear();
    ui->dailyWageEdit->clear();
    ui->empFromEdit->setDate(QDate::currentDate());
    ui->empToEdit->setDate(QDate::currentDate());
    ui->renewalEdit->setDate(QDate::currentDate());
}

void PlantillaCasual::on_clearTableB_clicked()
{
    ui->plantillaCasualTable->setRowCount(0);
}
void PlantillaCasual::setDatab(const QSqlDatabase &value)
{
    datab = value;
}



void PlantillaCasual::on_updateB_clicked()
{
    int rowNum = -1;
    QModelIndexList indexes = ui->plantillaCasualTable->selectionModel()->selection().indexes();
     for (int i = 0; i < indexes.count(); ++i){
         QModelIndex index = indexes.at(i);
         rowNum = index.row();
     }
     if (rowNum != -1 && !ui->nameAppointeeEdit->text().isEmpty()){
         ui->plantillaCasualTable->item(rowNum, 0)->setText(ui->nameAppointeeEdit->text());
         ui->plantillaCasualTable->item(rowNum, 1)->setText(ui->positionEdit->text());
         ui->plantillaCasualTable->item(rowNum, 2)->setText(ui->levelEdit->currentText());
         ui->plantillaCasualTable->item(rowNum, 3)->setText(ui->sgEdit->text());
         ui->plantillaCasualTable->item(rowNum, 4)->setText(ui->dailyWageEdit->text());
         ui->plantillaCasualTable->item(rowNum, 5)->setText(ui->empFromEdit->date().toString());
         if (ui->presentEmpToCB->isChecked()) ui->plantillaCasualTable->item(rowNum, 6)->setText("PRESENT");
         else ui->plantillaCasualTable->item(rowNum, 6)->setText(ui->empToEdit->date().toString());
         if (ui->noRenewalCB->isChecked()) ui->plantillaCasualTable->item(rowNum, 7)->setText("NONE");
         else ui->plantillaCasualTable->item(rowNum, 7)->setText(ui->renewalEdit->date().toString());
     }
}

void PlantillaCasual::on_deleteB_clicked()
{
    int rowNum = -1;
    QModelIndexList indexes = ui->plantillaCasualTable->selectionModel()->selection().indexes();
    for (int i = 0; i < indexes.count(); ++i){
        QModelIndex index = indexes.at(i);
        rowNum = index.row();
    }
    if (rowNum != -1) ui->plantillaCasualTable->removeRow(rowNum);
}

void PlantillaCasual::terminateTimedMessage()
{
    messageLabel->setText("");
}

void PlantillaCasual::on_searcEmployeeEdit_textEdited(const QString name)
{
    int rowCount = ui->employeesTable->rowCount();
    for (int i = 0; i < rowCount; i++){
        ui->employeesTable->setRowHidden(i, false);
    }
    for (int i = 0; i < rowCount; i++){
        if (!ifStringHasSubstring(ui->employeesTable->item(i, 0)->text().toLower().toStdString(), name.toLower().toStdString())){
            ui->employeesTable->setRowHidden(i, true);
        }
    }
}

void PlantillaCasual::on_searchPlantillaEdit_textEdited(const QString name)
{
    int rowCount = ui->plantillaCasualTable->rowCount();
    for (int i = 0; i < rowCount; i++){
        ui->plantillaCasualTable->setRowHidden(i, false);
    }
    for (int i = 0; i < rowCount; i++){
        if (!ifStringHasSubstring(ui->plantillaCasualTable->item(i, 0)->text().toLower().toStdString(), name.toLower().toStdString())){
            ui->plantillaCasualTable->setRowHidden(i, true);
        }
    }
}

void PlantillaCasual::refreshData()
{
}

void PlantillaCasual::on_saveB_clicked()
{
    QString pltID;
    QString deptDiv = ui->deptDivEdit->text();
    QString sourceFunds = ui->sourceFundsEdit->text();
    QString datePrepared = ui->datePreparedEdit->date().toString();

    BoolQuery bQuery;
    if (mode == 0) bQuery.addQuery(!plantillaCasualDeptExist(deptDiv), "Plantilla Casual\nDept/Div already exists.");
    bQuery.addQuery(!deptDiv.isEmpty(), "Type in\nthe name of\nthe dept/div name.");

    if (bQuery.earliestQuery().empty()){
        pltID = generateValidPltID();
        if (mode == 2) pltID = currentPltID;

        QSqlQuery query(datab);
        query.exec("DELETE FROM [LST PLT CASUAL APPT] WHERE [PLT KEY] = '" + pltID + "'");
        query.prepare("INSERT INTO [LST PLT CASUAL APPT] ([PLT KEY], [DEPT], [SOURCE FUND], [DATE PREPARED], [LAST UPDATED]) "
                   "VALUES (:PLTKEY, :DEPT, :SOURCEFUND, :DATEPREPARED, :LASTUPDATED)");
        query.bindValue(":PLTKEY", pltID);
        query.bindValue(":DEPT", deptDiv);
        query.bindValue(":SOURCEFUND", sourceFunds);
        query.bindValue(":DATEPREPARED", datePrepared);
        query.bindValue(":LASTUPDATED", QDate::currentDate().toString());
        query.exec();

        query.clear();
        query.exec("DELETE FROM [PLT CASUAL APPT] WHERE [PLT KEY] = '" + pltID + "'");

        for (int i = 0; i < ui->plantillaCasualTable->rowCount(); i++){
            QString employeeID;
            QString name = ui->plantillaCasualTable->item(i, 0)->text();
            QString position = ui->plantillaCasualTable->item(i, 1)->text();
            QString level = ui->plantillaCasualTable->item(i, 2)->text();
            QString sg = ui->plantillaCasualTable->item(i, 3)->text();
            QString dailyWag = ui->plantillaCasualTable->item(i, 4)->text();
            QString empFrom = ui->plantillaCasualTable->item(i, 5)->text();
            QString empTo = ui->plantillaCasualTable->item(i, 6)->text();
            QString renewal = ui->plantillaCasualTable->item(i, 7)->text();

            if (employeeIDMap.contains(name)) employeeID = employeeIDMap[name];
            else employeeID = "NONE";

            query.clear();
            query.prepare("INSERT INTO [PLT CASUAL APPT] ([PLT KEY], [EMPLOYEE ID], [APPOINTEE NAME], [POSITION], [LEVEL], [SG], [DAILY WAGE], "
                          "[PERIOD EMP FROM], [PERIOD EMP TO], [RENEWAL DATE]) "
                       "VALUES (:PLTKEY, :EMPLOYEEID, :APPOINTEENAME, :POSITION, :LEVEL, :SG, :DAILYWAGE, :PERIODEMPFROM, :PERIODEMPTO, "
                          ":RENEWALDATE)");
            query.bindValue(":PLTKEY", pltID);
            query.bindValue(":EMPLOYEEID", employeeID);
            query.bindValue(":APPOINTEENAME", name);
            query.bindValue(":POSITION", position);
            query.bindValue(":LEVEL", level);
            query.bindValue(":SG", sg);
            query.bindValue(":DAILYWAGE", dailyWag);
            query.bindValue(":PERIODEMPFROM", empFrom);
            query.bindValue(":PERIODEMPTO", empTo);
            query.bindValue(":RENEWALDATE", renewal);
            query.exec();
        }

        on_backB_clicked();
    }
    else {
        displayTimedMessage(QString::fromStdString(bQuery.earliestQuery()), 3000);
    }
}

void PlantillaCasual::setFieldsWithID(QString pltID, QString deptDiv, QString sourceFunds, QString datePrep)
{
    currentPltID = pltID;
    ui->deptDivEdit->setText(deptDiv);
    ui->sourceFundsEdit->setText(sourceFunds);
    ui->datePreparedEdit->setDate(QDate::fromString(datePrep));

    QSqlQuery origquery(datab);
    origquery.exec("SELECT [EMPLOYEE ID], [APPOINTEE NAME], [POSITION], [LEVEL], [SG], [DAILY WAGE], [PERIOD EMP FROM], [PERIOD EMP TO], "
                   "[RENEWAL DATE] FROM [PLT CASUAL APPT] where [PLT KEY] = '" + currentPltID + "'");
    while (origquery.next()){
        QString employeeID = origquery.value(0).toString();
        QString name = origquery.value(1).toString();
        QString position = origquery.value(2).toString();
        QString level = origquery.value(3).toString();
        QString sg = origquery.value(4).toString();
        QString dailyWage = origquery.value(5).toString();
        QString empFrom = origquery.value(6).toString();
        QString empTo = origquery.value(7).toString();
        QString renewal = origquery.value(8).toString();

        ui->plantillaCasualTable->setRowCount(ui->plantillaCasualTable->rowCount() + 1);

        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        nameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *positionItem = new QTableWidgetItem(position);
        positionItem->setTextAlignment(Qt::AlignCenter);
        positionItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *levelItem = new QTableWidgetItem(level);
        levelItem->setTextAlignment(Qt::AlignCenter);
        levelItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *sgItem = new QTableWidgetItem(sg);
        sgItem->setTextAlignment(Qt::AlignCenter);
        sgItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *dailyWageItem = new QTableWidgetItem(dailyWage);
        dailyWageItem->setTextAlignment(Qt::AlignCenter);
        dailyWageItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *empFromItem = new QTableWidgetItem(empFrom);
        empFromItem->setTextAlignment(Qt::AlignCenter);
        empFromItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *empToItem = new QTableWidgetItem(empTo);
        empToItem->setTextAlignment(Qt::AlignCenter);
        empToItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *renewalItem = new QTableWidgetItem(renewal);
        renewalItem->setTextAlignment(Qt::AlignCenter);
        renewalItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 0, nameItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 1, positionItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 2, levelItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 3, sgItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 4, dailyWageItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 5, empFromItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 6, empToItem);
        ui->plantillaCasualTable->setItem(ui->plantillaCasualTable->rowCount() - 1, 7, renewalItem);
    }
}

void PlantillaCasual::clearAll()
{
    on_clearFieldsB_clicked();
    on_clearTableB_clicked();
    ui->deptDivEdit->clear();
    ui->sourceFundsEdit->clear();
    ui->datePreparedEdit->setDate(QDate::currentDate());
}

QString PlantillaCasual::generateValidPltID()
{
    char c[15];
    generateRandStr(c, 15);
    QString employeeid = QString::fromStdString(string(c));

    int size = 0;
    QSqlQuery query(datab);
    query.exec("SELECT * FROM [LST PLT CASUAL APPT] WHERE [PLT KEY] LIKE '" + employeeid + "'");

    while (1){
        while (1){
            if (query.next()){
                size++;
            }
            else {
                break;
            }
        }

        cout << "size: " << size << endl;

        if (size == 0){
            break;
        }
        else {
            c[15] = NULL;
            generateRandStr(c, 15);
            employeeid = QString::fromStdString(string(c));
            query.clear();
            query.exec("SELECT * FROM [LST PLT CASUAL APPT] WHERE [PLT KEY] LIKE '" + employeeid + "'");
            size = 0;
        }
    }

    return employeeid;
}

bool PlantillaCasual::plantillaCasualDeptExist(QString deptName)
{
    QSqlQuery query(datab);
    query.exec("SELECT * FROM [LST PLT CASUAL APPT] WHERE [DEPT] LIKE '" + deptName + "'");

    while (query.next()){
        return true;
    }
    return false;
}

void PlantillaCasual::setMode(int value)
{
    mode = value;

    switch (mode){
    case 0: {

    }; break;
    case 1: {

    }; break;
    case 2: {

    }; break;
    default: break;
    }
}


void PlantillaCasual::on_backB_clicked()
{
    EmployeeManagerHome *empManHome = (EmployeeManagerHome*)(stackWidget->widget(5));
    ViewPlantillaCasualAppt *pCasual = (ViewPlantillaCasualAppt*)(stackWidget->widget(7));
    switch (mode){
    case 0: {
        stackWidget->setCurrentIndex(5);
        empManHome->window()->showNormal();
    }; break;
    case 1: {
        pCasual->updateView();
        pCasual->window()->showNormal();
        stackWidget->setCurrentIndex(7);
    }; break;
    case 2: {
        pCasual->updateView();
        pCasual->window()->showNormal();
        stackWidget->setCurrentIndex(7);
    }; break;
    default: break;
    }
}
