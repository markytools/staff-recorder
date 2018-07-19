#include "plantillapersonnel.h"
#include "ui_plantillapersonnel.h"

PlantillaPersonnel::PlantillaPersonnel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlantillaPersonnel)
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
    messageLabel->setWordWrap(true);

    ui->messageForm->addRow(messageLabel);
    messageLabel->setText("");

    ui->employeesTable->setColumnWidth(0, 220);
    ui->plantillaPersonnelTable->setColumnWidth(0, 100);
    ui->plantillaPersonnelTable->setColumnWidth(1, 300);
    ui->plantillaPersonnelTable->setColumnWidth(2, 100);
    ui->plantillaPersonnelTable->setColumnWidth(3, 100);
    ui->plantillaPersonnelTable->setColumnWidth(4, 300);
    ui->plantillaPersonnelTable->setColumnWidth(5, 150);
    ui->plantillaPersonnelTable->setColumnWidth(6, 200);
    ui->plantillaPersonnelTable->setColumnWidth(7, 200);
    ui->plantillaPersonnelTable->setColumnWidth(8, 200);
    ui->plantillaPersonnelTable->setColumnWidth(9, 200);
    ui->plantillaPersonnelTable->setColumnWidth(10, 250);
    ui->plantillaPersonnelTable->setColumnWidth(11, 250);
    ui->employeesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->plantillaPersonnelTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->itemNoEdit->setValidator(new QDoubleValidator(0, 9999999999999999999, 100, this));






    //
    //a
    //database excel

//    datab = new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));
//    QString databasename = "EmployeeManagerChannel";
//    datab->setDatabaseNameaz(databasename);
//    datab->open();
//    if (datab->isOpen()){a
//        cout << "Connection Success" << endl;
//    }a

//    QXlsx::Document xfile("excelfiles/PlantillaPersonnelTest.xlsx");
//    xfile.sheet("2011");
//    xfile.write("B9", "data");
//    xfile.save();







//       string databasefilename = removeLastOccurrenceStr(getCurrentFileDirector(), '\\') + "\\plantillapersonnel.ls";

//       QDate date = QDate::currentDate();
//       string certifiedDate = date.toString().toStdString();
//       string approvedByName = "approvedn";
//       string approvedByPos = "approvedpos";
//       string signatureByName = "signatureName";
//       string signatureByPos = "signaturePos";

//       fstream outfile;
//       outfile.open(databasefilename.data(), ios::out);
//       if (outfile.is_open()){
//           outfile << certifiedDate << endl;
//           outfile << approvedByName << endl;
//           outfile << approvedByPos << endl;
//           outfile << signatureByName << endl;
//           outfile << signatureByPos;
//       }
//       else {
//           cerr << "Error opening item info files." << endl;
//           exit(1);
//       }
//       outfile.close();








//       QDate date = QDate::currentDate();
//       string certifiedDate;
//       string approvedByName;
//       string approvedByPos;
//       string signatureByName;
//       string signatureByPos;

//       fstream infile;
//       infile.open(databasefilename.data());
//       if (infile.is_open()){
//           getline(infile >> ws, certifiedDate);
//           getline(infile >> ws, approvedByName);
//           getline(infile >> ws, approvedByPos);
//           getline(infile >> ws, signatureByName);
//           getline(infile >> ws, signatureByPos);
//       }
//       else {
//           cerr << "Error opening item info files." << endl;
//           exit(1);
//       }
//       infile.close();

//       cout << certifiedDate << endl;
//       cout << approvedByName << endl;
//       cout << approvedByPos << endl;
//       cout << signatureByName << endl;
//       cout << signatureByPos << endl;


//    string original = "asdfgsdfg:ijtij ijdfgh ija::saf 1999 bp";

//    size_t s = original.find(":");
//    size_t e = original.find_last_of("bp");
//    string sub = original.substr(s + 1, e - s - 2);
//    cout << sub << endl;


//    PlantillaPersonnelRowData pRowData;
//    pRowData.position = "Admin. Officer II (Supply Officer I)";
//    if (pRowData.doublePositionLayer()){
//        qDebug() << pRowData.position << endl;
//        qDebug() << pRowData.position2 << endl;
//    }
//    pRowData.dateOfBirth = QDate::currentDate().toString("d-MMM-yy");
//    qDebug() << pRowData.dateOfBirth << endl;



//    string filename = removeLastOccurrenceStr(getCurrentFileDirector(), '\\');
//    auto pos = filename.rfind("\\");
//    if (pos != std::string::npos) {
//        filename.erase(pos);
//    }
//    cout << filename << endl;


}

PlantillaPersonnel::~PlantillaPersonnel()
{
    delete ui;
}

void PlantillaPersonnel::updateViews()
{
    ui->employeesTable->setRowCount(0);
    ui->itemNoEdit->setText("0");
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

//0 - normal/delete, 1 - add, 2 - edit
void PlantillaPersonnel::setMode(int value)
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

void PlantillaPersonnel::displayTimedMessage(QString message, int countdown)
{
    messageLabel->setText(message);
    messageTimer->start(countdown);
}

void PlantillaPersonnel::setFieldsWithID(QString pltID, QString officeName, QString dateCorrected)
{
    currentPltID = pltID;
    ui->officeEdit->setText(officeName);
    ui->certifiedCorrectDateEdit->setDate(QDate::fromString(dateCorrected));

    string databasefilename = removeLastOccurrenceStr(getCurrentFileDirector(), '\\') + "\\plantillapersonnel.ls";
    string certifiedDate;
    string approvedByName;
    string approvedByPos;
    string signatureByName;
    string signatureByPos;

    fstream infile;
    infile.open(databasefilename.data());
    if (infile.is_open()){
        getline(infile >> ws, certifiedDate);
        getline(infile >> ws, approvedByName);
        getline(infile >> ws, approvedByPos);
        getline(infile >> ws, signatureByName);
        getline(infile >> ws, signatureByPos);
    }
    else {
        cerr << "Error opening item info files." << endl;
//        exit(1);
    }
    infile.close();

    certifiedDate.erase(0, 1);
    approvedByName.erase(0, 1);
    approvedByPos.erase(0, 1);
    signatureByName.erase(0, 1);
    signatureByPos.erase(0, 1);

    ui->certifiedCorrectDateEdit->setDate(QDate::fromString(QString::fromStdString(certifiedDate)));
    ui->approvedByNameEdit->setText(QString::fromStdString(approvedByName));
    ui->approvedByPosEdit->setText(QString::fromStdString(approvedByPos));
    ui->signatureByNameEdit->setText(QString::fromStdString(signatureByName));
    ui->signatureByPosEdit->setText(QString::fromStdString(signatureByPos));


    QSqlQuery origquery(datab);
    origquery.exec("SELECT [EMPLOYEE ID], [ITEM NO], [POSITION], [LEVEL], [SG], [NAME INCUMBENT], [GENDER], [DATE BIRTH], [DATE ORIG APPT], "
               "[DATE LAST PROM], [EMP STATUS], [EDU], [ELIG] FROM [PLT PERSONNEL] where [PLT KEY] = '" + currentPltID + "'");
    while (origquery.next()){
        qDebug() << "safa" << endl;
        QString employeeID = origquery.value(0).toString();
        QString level = origquery.value(3).toString();
        QString sg = origquery.value(4).toString();
        QString nameOfIncum = origquery.value(5).toString();
        QString itemNo = origquery.value(1).toString();
        QString gender = origquery.value(6).toString();
        QString birthDate = origquery.value(7).toString();
        QString dateOrigAppt;
        QString dateLastProm;
        QString status;
        QString designation;
        QVector<QString> education;
        QVector<QString> eligibility;
        QString eduFullStr = "";
        QString eligFullStr = "";

        if (employeeID != "NONE"){
            QSqlQuery query2(datab);
            query2.exec("SELECT [INC DATE FROM], [INC DATE TO], [STATUS], [DESIGNATION] FROM [SERVICE REC] WHERE "
                       "[EMPLOYEE ID] = '" + employeeID + "'");
            QVector<ServiceRecData> serviceData;
            while (query2.next()) {
                ServiceRecData sData;
                sData.dateFrom = query2.value(0).toString();
                sData.dateTo = query2.value(1).toString();
                sData.status = query2.value(2).toString();
                sData.designation = query2.value(3).toString();

                serviceData.push_back(sData);
            }

            for (ServiceRecData sData : serviceData){
                if (dateOrigAppt.isEmpty()){
                    dateOrigAppt = sData.dateFrom;
                    continue;
                }
                if (QDate::fromString(dateOrigAppt) > QDate::fromString(sData.dateFrom)) dateOrigAppt = sData.dateFrom;
            }

            for (ServiceRecData sData : serviceData){
                if (sData.dateTo == "PRESENT"){
                    dateLastProm = sData.dateFrom;
                    status = sData.status;
                    designation = sData.designation;
                    break;
                }
            }

            query2.clear();
            query2.exec("SELECT [DEGREE COURSE] FROM [EDU BGD] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
            while (query2.next()) {
                QString degree = query2.value(0).toString();
                string stdStr = degree.toStdString();
                if (stdStr.size() > 4 && ifStringHasSubstring(stdStr, "(") && ifStringHasSubstring(stdStr, ")"))
                    education.push_back(QString::fromStdString(getStringBetweenStrings(stdStr, "(", ")")));
            }

            query2.clear();
            query2.exec("SELECT [CAREER SERVICE] FROM [CIVIL SERV] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
            while (query2.next()) {
                QString examPassed = query2.value(0).toString();
                string stdStr = examPassed.toStdString();
                if (stdStr.size() > 4 && ifStringHasSubstring(stdStr, "(") && ifStringHasSubstring(stdStr, ")"))
                    eligibility.push_back(QString::fromStdString(getStringBetweenStrings(stdStr, "(", ")")));
            }
        }
        else {
            dateOrigAppt = origquery.value(8).toString();
            dateLastProm = origquery.value(9).toString();
            status = origquery.value(10).toString();
            designation = origquery.value(2).toString();
        }

        for (QString str : education){
            if (eduFullStr.isEmpty()) eduFullStr += str;
            else eduFullStr += ", " + str;
        }

        for (QString str : eligibility){
            if (eligFullStr.isEmpty()) eligFullStr += str;
            else eligFullStr += ", " + str;
        }

        ui->plantillaPersonnelTable->setRowCount(ui->plantillaPersonnelTable->rowCount() + 1);

        QTableWidgetItem *itemNoItem = new QTableWidgetItem(itemNo);
        itemNoItem->setTextAlignment(Qt::AlignCenter);
        itemNoItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *posItem = new QTableWidgetItem(designation);
        posItem->setTextAlignment(Qt::AlignCenter);
        posItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *levelItem = new QTableWidgetItem(level);
        levelItem->setTextAlignment(Qt::AlignCenter);
        levelItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *sgItem = new QTableWidgetItem(sg);
        sgItem->setTextAlignment(Qt::AlignCenter);
        sgItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *nameItem = new QTableWidgetItem(nameOfIncum);
        nameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *genderItem = new QTableWidgetItem(gender);
        genderItem->setTextAlignment(Qt::AlignCenter);
        genderItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *dateOfBirthItem = new QTableWidgetItem(birthDate);
        dateOfBirthItem->setTextAlignment(Qt::AlignCenter);
        dateOfBirthItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *dateOrigApptItem = new QTableWidgetItem(dateOrigAppt);
        dateOrigApptItem->setTextAlignment(Qt::AlignCenter);
        dateOrigApptItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *dateLastPromItem = new QTableWidgetItem(dateLastProm);
        dateLastPromItem->setTextAlignment(Qt::AlignCenter);
        dateLastPromItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *empStatusItem = new QTableWidgetItem(status);
        empStatusItem->setTextAlignment(Qt::AlignCenter);
        empStatusItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *educItem = new QTableWidgetItem(eduFullStr);
        educItem->setTextAlignment(Qt::AlignCenter);
        educItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *eligItem = new QTableWidgetItem(eligFullStr);
        eligItem->setTextAlignment(Qt::AlignCenter);
        eligItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 0, itemNoItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 1, posItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 2, levelItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 3, sgItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 4, nameItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 5, genderItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 6, dateOfBirthItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 7, dateOrigApptItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 8, dateLastPromItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 9, empStatusItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 10, educItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 11, eligItem);
    }
}

void PlantillaPersonnel::clearAll()
{
    on_clearB_clicked();
    on_clearFields_clicked();
    ui->officeEdit->clear();
    ui->certifiedCorrectDateEdit->setDate(QDate::currentDate());
}

void PlantillaPersonnel::refreshData()
{
    QSqlQuery empQuery(datab);
    empQuery.exec("SELECT [EMPLOYEE ID] FROM [PLT PERSONNEL] WHERE [EMPLOYEE ID] <> 'NONE'");
    while (empQuery.next()){
        QString employeeID = empQuery.value(0).toString();

        QString firstName;
        QString middleName;
        QString lastName;
        QString gender;
        QString birthDate;
        QString dateOrigAppt;
        QString dateLastProm;
        QString status;
        QString designation;
        QVector<QString> education;
        QVector<QString> eligibility;

        QSqlQuery query(datab);
        query.exec("SELECT [FIRST NAME], [MIDDLE NAME], [SURNAME], [SEX], [BIRTHDATE] FROM [PERSONAL INFO] WHERE "
                   "[EMPLOYEE ID] = '" + employeeID + "'");
        while (query.next()) {
            firstName = query.value(0).toString();
            middleName = query.value(1).toString();
            lastName = query.value(2).toString();
            int sex = query.value(3).toInt();
            if (sex == 1) gender = "Male";
            else if (sex == 2) gender = "Female";
            birthDate = query.value(4).toString();
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
            if (dateOrigAppt.isEmpty()){
                dateOrigAppt = sData.dateFrom;
                continue;
            }
            if (QDate::fromString(dateOrigAppt) > QDate::fromString(sData.dateFrom)) dateOrigAppt = sData.dateFrom;
        }

        for (ServiceRecData sData : serviceData){
            if (sData.dateTo == "PRESENT"){
                dateLastProm = sData.dateFrom;
                status = sData.status;
                designation = sData.designation;
                break;
            }
        }

        query.clear();
        query.exec("SELECT [DEGREE COURSE] FROM [EDU BGD] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        while (query.next()) {
            QString degree = query.value(0).toString();
            string stdStr = degree.toStdString();
            if (stdStr.size() > 4 && ifStringHasSubstring(stdStr, "(") && ifStringHasSubstring(stdStr, ")"))
                education.push_back(QString::fromStdString(getStringBetweenStrings(stdStr, "(", ")")));
        }

        query.clear();
        query.exec("SELECT [CAREER SERVICE] FROM [CIVIL SERV] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        while (query.next()) {
            QString examPassed = query.value(0).toString();
            string stdStr = examPassed.toStdString();
            if (stdStr.size() > 4 && ifStringHasSubstring(stdStr, "(") && ifStringHasSubstring(stdStr, ")"))
                eligibility.push_back(QString::fromStdString(getStringBetweenStrings(stdStr, "(", ")")));
        }

        QString middleInit = "";
        if (!middleName.isEmpty()){
            middleInit = middleName.at(0).toUpper();
            middleInit += ".";
        }
        QString fullName = firstName + " " + middleInit + " " + lastName;


        ui->empStatusEdit->setText(status);
        QString eduStr = "";
        for (QString edu : education){
            if (eduStr.isEmpty()) eduStr += edu;
            else eduStr += ", " + edu;
        }
        ui->educationEdit->setText(eduStr);
        QString eligStr = "";
        for (QString elig : eligibility){
            if (eligStr.isEmpty()) eligStr += elig;
            else eligStr += ", " + elig;
        }
        ui->eligEdit->setText(eligStr);

        query.exec("UPDATE [PLT PERSONNEL] SET [NAME INCUMBENT] = '" + fullName + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("UPDATE [PLT PERSONNEL] SET [POSITION] = '" + designation + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("UPDATE [PLT PERSONNEL] SET [GENDER] = '" + gender + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("UPDATE [PLT PERSONNEL] SET [DATE BIRTH] = '" + birthDate + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("UPDATE [PLT PERSONNEL] SET [DATE ORIG APPT] = '" + dateOrigAppt + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("UPDATE [PLT PERSONNEL] SET [DATE LAST PROM] = '" + dateLastProm + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("UPDATE [PLT PERSONNEL] SET [EMP STATUS] = '" + status + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("UPDATE [PLT PERSONNEL] SET [EDU] = '" + eduStr + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        query.exec("UPDATE [PLT PERSONNEL] SET [ELIG] = '" + eligStr + "' WHERE [EMPLOYEE ID] = '" + employeeID + "'");
    }
}

void PlantillaPersonnel::setPrintedOfficeName(QString officeName)
{
    ui->printedOfficeEdit->setText(officeName);
}

void PlantillaPersonnel::on_setEmployeeID_clicked()
{
    if (!selectedEmployeeFullName.isEmpty()){
        QString employeeID = employeeIDMap[selectedEmployeeFullName];

        QString firstName;
        QString middleName;
        QString lastName;
        QString gender;
        QString birthDate;
        QString dateOrigAppt;
        QString dateLastProm;
        QString status;
        QString designation;
        QVector<QString> education;
        QVector<QString> eligibility;

        QSqlQuery query(datab);
        query.exec("SELECT [FIRST NAME], [MIDDLE NAME], [SURNAME], [SEX], [BIRTHDATE] FROM [PERSONAL INFO] WHERE "
                   "[EMPLOYEE ID] = '" + employeeID + "'");
        while (query.next()) {
            firstName = query.value(0).toString();
            middleName = query.value(1).toString();
            lastName = query.value(2).toString();
            int sex = query.value(3).toInt();
            if (sex == 1) gender = "Male";
            else if (sex == 2) gender = "Female";
            birthDate = query.value(4).toString();
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
            if (dateOrigAppt.isEmpty()){
                dateOrigAppt = sData.dateFrom;
                continue;
            }
            if (QDate::fromString(dateOrigAppt) > QDate::fromString(sData.dateFrom)) dateOrigAppt = sData.dateFrom;
        }

        for (ServiceRecData sData : serviceData){
            if (sData.dateTo == "PRESENT"){
                dateLastProm = sData.dateFrom;
                status = sData.status;
                designation = sData.designation;
                break;
            }
        }

        query.clear();
        query.exec("SELECT [DEGREE COURSE] FROM [EDU BGD] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        while (query.next()) {
            QString degree = query.value(0).toString();
            string stdStr = degree.toStdString();
            if (stdStr.size() > 4 && ifStringHasSubstring(stdStr, "(") && ifStringHasSubstring(stdStr, ")"))
                education.push_back(QString::fromStdString(getStringBetweenStrings(stdStr, "(", ")")));
        }

        query.clear();
        query.exec("SELECT [CAREER SERVICE] FROM [CIVIL SERV] WHERE [EMPLOYEE ID] = '" + employeeID + "'");
        while (query.next()) {
            QString examPassed = query.value(0).toString();
            string stdStr = examPassed.toStdString();
            if (stdStr.size() > 4 && ifStringHasSubstring(stdStr, "(") && ifStringHasSubstring(stdStr, ")"))
                eligibility.push_back(QString::fromStdString(getStringBetweenStrings(stdStr, "(", ")")));
        }

        ui->positionEdit->setText(designation);
        ui->nameOfIncumEdit->setText(selectedEmployeeFullName);
        ui->genderEdit->setText(gender);
        ui->dateOfBirthEdit->setDate(QDate::fromString(birthDate));
        ui->dateOrigApptEdit->setDate(QDate::fromString(dateOrigAppt));
        ui->dateLastPromEdit->setDate(QDate::fromString(dateLastProm));
        ui->empStatusEdit->setText(status);
        QString eduStr = "";
        for (QString edu : education){
            if (eduStr.isEmpty()) eduStr += edu;
            else eduStr += ", " + edu;
        }
        ui->educationEdit->setText(eduStr);
        QString eligStr = "";
        for (QString elig : eligibility){
            if (eligStr.isEmpty()) eligStr += elig;
            else eligStr += ", " + elig;
        }
        ui->eligEdit->setText(eligStr);
    }
}

void PlantillaPersonnel::on_employeesTable_cellPressed(int row, int column)
{
    QTableWidgetItem *item = ui->employeesTable->item(row, 0);
    selectedEmployeeFullName = item->text();
}

void PlantillaPersonnel::on_addB_clicked()
{
    for (int i = 0; i < ui->plantillaPersonnelTable->rowCount(); i++){
        QTableWidgetItem *item = ui->plantillaPersonnelTable->item(i, 4);
        if (item->text().toUpper() != QString("vacant").toUpper() && item->text() == ui->nameOfIncumEdit->text()){
            displayTimedMessage("Employee\nalready in\nlist!", 3000);
            return;
        }
    }
    if (!ui->itemNoEdit->text().isEmpty()){
        ui->plantillaPersonnelTable->setRowCount(ui->plantillaPersonnelTable->rowCount() + 1);

        QTableWidgetItem *itemNoItem = new QTableWidgetItem(ui->itemNoEdit->text());
        itemNoItem->setTextAlignment(Qt::AlignCenter);
        itemNoItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *posItem = new QTableWidgetItem(ui->positionEdit->text());
        posItem->setTextAlignment(Qt::AlignCenter);
        posItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *levelItem = new QTableWidgetItem(ui->levelEdit->currentText());
        levelItem->setTextAlignment(Qt::AlignCenter);
        levelItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *sgItem = new QTableWidgetItem(ui->sgEdit->text());
        sgItem->setTextAlignment(Qt::AlignCenter);
        sgItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *nameItem = new QTableWidgetItem(ui->nameOfIncumEdit->text());
        nameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *genderItem = new QTableWidgetItem(ui->genderEdit->text());
        genderItem->setTextAlignment(Qt::AlignCenter);
        genderItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *dateOfBirthItem = new QTableWidgetItem(ui->dateOfBirthEdit->date().toString());
        dateOfBirthItem->setTextAlignment(Qt::AlignCenter);
        dateOfBirthItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *dateOrigApptItem = new QTableWidgetItem(ui->dateOrigApptEdit->date().toString());
        dateOrigApptItem->setTextAlignment(Qt::AlignCenter);
        dateOrigApptItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *dateLastPromItem = new QTableWidgetItem(ui->dateLastPromEdit->date().toString());
        dateLastPromItem->setTextAlignment(Qt::AlignCenter);
        dateLastPromItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *empStatusItem = new QTableWidgetItem(ui->empStatusEdit->text());
        empStatusItem->setTextAlignment(Qt::AlignCenter);
        empStatusItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *educItem = new QTableWidgetItem(ui->educationEdit->text());
        educItem->setTextAlignment(Qt::AlignCenter);
        educItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *eligItem = new QTableWidgetItem(ui->eligEdit->text());
        eligItem->setTextAlignment(Qt::AlignCenter);
        eligItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 0, itemNoItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 1, posItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 2, levelItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 3, sgItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 4, nameItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 5, genderItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 6, dateOfBirthItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 7, dateOrigApptItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 8, dateLastPromItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 9, empStatusItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 10, educItem);
        ui->plantillaPersonnelTable->setItem(ui->plantillaPersonnelTable->rowCount() - 1, 11, eligItem);
    }
    updateItemNumbers();
}

void PlantillaPersonnel::on_deleteB_clicked()
{
    int rowNum = -1;
    QModelIndexList indexes = ui->plantillaPersonnelTable->selectionModel()->selection().indexes();
    for (int i = 0; i < indexes.count(); ++i){
        QModelIndex index = indexes.at(i);
        rowNum = index.row();
    }
    if (rowNum != -1){
        ui->plantillaPersonnelTable->removeRow(rowNum);
        updateItemNumbers();
    }
}

void PlantillaPersonnel::on_searchEmployeeEdit_textEdited(const QString name)
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

void PlantillaPersonnel::on_searchPlantillaEdit_textEdited(const QString name)
{
    int rowCount = ui->plantillaPersonnelTable->rowCount();
    for (int i = 0; i < rowCount; i++){
        ui->plantillaPersonnelTable->setRowHidden(i, false);
    }
    for (int i = 0; i < rowCount; i++){
        if (!ifStringHasSubstring(ui->plantillaPersonnelTable->item(i, 4)->text().toLower().toStdString(), name.toLower().toStdString())){
            ui->plantillaPersonnelTable->setRowHidden(i, true);
        }
    }
}

void PlantillaPersonnel::on_editB_clicked()
{
    int rowNum = -1;
    QModelIndexList indexes = ui->plantillaPersonnelTable->selectionModel()->selection().indexes();
    for (int i = 0; i < indexes.count(); ++i){
        QModelIndex index = indexes.at(i);
        rowNum = index.row();
    }
    if (rowNum != -1){
        ui->itemNoEdit->setText(ui->plantillaPersonnelTable->item(rowNum, 0)->text());
        ui->positionEdit->setText(ui->plantillaPersonnelTable->item(rowNum, 1)->text());
        ui->levelEdit->setCurrentText(ui->plantillaPersonnelTable->item(rowNum, 2)->text());
        ui->sgEdit->setText(ui->plantillaPersonnelTable->item(rowNum, 3)->text());
        ui->nameOfIncumEdit->setText(ui->plantillaPersonnelTable->item(rowNum, 4)->text());
        ui->genderEdit->setText(ui->plantillaPersonnelTable->item(rowNum, 5)->text());
        ui->dateOfBirthEdit->setDate(QDate::fromString(ui->plantillaPersonnelTable->item(rowNum, 6)->text()));
        ui->dateOrigApptEdit->setDate(QDate::fromString(ui->plantillaPersonnelTable->item(rowNum, 7)->text()));
        ui->dateLastPromEdit->setDate(QDate::fromString(ui->plantillaPersonnelTable->item(rowNum, 8)->text()));
        ui->empStatusEdit->setText(ui->plantillaPersonnelTable->item(rowNum, 9)->text());
        ui->educationEdit->setText(ui->plantillaPersonnelTable->item(rowNum, 10)->text());
        ui->eligEdit->setText(ui->plantillaPersonnelTable->item(rowNum, 11)->text());
    }
}

void PlantillaPersonnel::on_updateB_clicked()
{
    if (ui->itemNoEdit->text().isEmpty()){
        displayTimedMessage("No\nitem no.", 2000);
        return;
    }
    int rowNum = -1;
    QModelIndexList indexes = ui->plantillaPersonnelTable->selectionModel()->selection().indexes();
    for (int i = 0; i < indexes.count(); ++i){
        QModelIndex index = indexes.at(i);
        rowNum = index.row();
    }
    if (rowNum != -1){
        ui->plantillaPersonnelTable->item(rowNum, 0)->setText(ui->itemNoEdit->text());
        ui->plantillaPersonnelTable->item(rowNum, 1)->setText(ui->positionEdit->text());
        ui->plantillaPersonnelTable->item(rowNum, 2)->setText(ui->levelEdit->currentText());
        ui->plantillaPersonnelTable->item(rowNum, 3)->setText(ui->sgEdit->text());
        ui->plantillaPersonnelTable->item(rowNum, 4)->setText(ui->nameOfIncumEdit->text());
        ui->plantillaPersonnelTable->item(rowNum, 5)->setText(ui->genderEdit->text());
        ui->plantillaPersonnelTable->item(rowNum, 6)->setText(ui->dateOfBirthEdit->date().toString());
        ui->plantillaPersonnelTable->item(rowNum, 7)->setText(ui->dateOrigApptEdit->date().toString());
        ui->plantillaPersonnelTable->item(rowNum, 8)->setText(ui->dateLastPromEdit->date().toString());
        ui->plantillaPersonnelTable->item(rowNum, 9)->setText(ui->empStatusEdit->text());
        ui->plantillaPersonnelTable->item(rowNum, 10)->setText(ui->educationEdit->text());
        ui->plantillaPersonnelTable->item(rowNum, 11)->setText(ui->eligEdit->text());

        updateItemNumbers();
    }
}

void PlantillaPersonnel::on_clearB_clicked()
{
    ui->plantillaPersonnelTable->setRowCount(0);
}

void PlantillaPersonnel::on_clearFields_clicked()
{
    ui->itemNoEdit->clear();
    ui->positionEdit->clear();
    ui->sgEdit->clear();
    ui->sgEdit->clear();
    ui->nameOfIncumEdit->clear();
    ui->genderEdit->clear();
    ui->dateOfBirthEdit->setDate(QDate::currentDate());
    ui->dateOrigApptEdit->setDate(QDate::currentDate());
    ui->dateLastPromEdit->setDate(QDate::currentDate());
    ui->empStatusEdit->clear();
    ui->educationEdit->clear();
    ui->eligEdit->clear();
}
void PlantillaPersonnel::setDatab(const QSqlDatabase &value)
{
    datab = value;
}

void PlantillaPersonnel::updateItemNumbers()
{
//    double pi = 3.14159265359;
//    stringstream stream;
//    stream << fixed << setprecision(2) << pi;
//    string s = stream.str();


    if (ui->plantillaPersonnelTable->rowCount() > 1){
        double currentDouble = 0;
        double numToAdd = 0.1;
        int precision = 1;
        QString currentItemStr = "0";
        QString firstItemNo = ui->plantillaPersonnelTable->item(0, 0)->text();
        if (!(firstItemNo.isEmpty() || firstItemNo == ".")){
            currentItemStr = firstItemNo;
            int tempStrSize = currentItemStr.toStdString().substr(currentItemStr.toStdString().find(".") + 1).size();
            precision = tempStrSize;
            for (int i = 1; i < tempStrSize; i++) numToAdd *= 0.1;
            currentDouble = stof(currentItemStr.toStdString());
        }

        for (int i = 1; i < ui->plantillaPersonnelTable->rowCount(); i++){
            QString a = QString::number(currentDouble + numToAdd);
            QString b = QString::number(ceil(currentDouble));
            cout << currentDouble << " " << numToAdd << " " << currentDouble + numToAdd << " " << ceil(currentDouble) << endl;
            if (a == b){
                precision++;
                currentDouble += (numToAdd * 2) - 1;
                numToAdd *= 0.1;

                stringstream stream;
                stream << fixed << setprecision(precision) << currentDouble;
                string s = stream.str();
                ui->plantillaPersonnelTable->item(i, 0)->setText(QString::fromStdString(s));
            }
            else {
                currentDouble += numToAdd;
                stringstream stream;
                stream << fixed << setprecision(precision) << currentDouble;
                string s = stream.str();
                ui->plantillaPersonnelTable->item(i, 0)->setText(QString::fromStdString(s));
            }
        }
    }
}



void PlantillaPersonnel::on_saveB_clicked()
{
    savePlantillaPersonnel(true);
}

void PlantillaPersonnel::terminateTimedMessage()
{
    messageLabel->setText("");
}

QString PlantillaPersonnel::generateValidPltID()
{
    char c[15];
    generateRandStr(c, 15);
    QString employeeid = QString::fromStdString(string(c));

    int size = 0;
    QSqlQuery query(datab);
    query.exec("SELECT * FROM [LST PLT PERSONNEL] WHERE [PLT KEY] LIKE '" + employeeid + "'");

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
            query.exec("SELECT * FROM [LST PLT PERSONNEL] WHERE [PLT KEY] LIKE '" + employeeid + "'");
            size = 0;
        }
    }

    return employeeid;
}

//continue if false
bool PlantillaPersonnel::plantillaPersonnelOfficeExist(QString officeName)
{
    QSqlQuery query(datab);
    query.exec("SELECT * FROM [LST PLT PERSONNEL] WHERE [OFFICE] LIKE '" + officeName + "'");

    while (query.next()){
        return true;
    }
    return false;
}

void PlantillaPersonnel::updatePltPersonnelDetails(string certifiedDate, string approvedByName, string approvedByPos,
                                                   string signatureByName, string signatureByPos)
{
    string databasefilename = removeLastOccurrenceStr(getCurrentFileDirector(), '\\') + "\\plantillapersonnel.ls";

    fstream outfile;
    outfile.open(databasefilename.data(), ios::out);
    if (outfile.is_open()){
        outfile << "-" + certifiedDate << endl;
        outfile << "-" + approvedByName << endl;
        outfile << "-" + approvedByPos << endl;
        outfile << "-" + signatureByName << endl;
        outfile << "-" + signatureByPos;
    }
    else {
        cerr << "Error opening item info files." << endl;
        exit(1);
    }
    outfile.close();
}

void PlantillaPersonnel::savePlantillaPersonnel(bool goBackToViewPltPersonnel)
{
    updateItemNumbers();

    QString pltID;
    QString pltPersonnelOffice = ui->officeEdit->text();
    QString certifiedDate = ui->certifiedCorrectDateEdit->date().toString();
    QString lastUpdate = QDate::currentDate().toString();
    QString printOfficeName = ui->printedOfficeEdit->text();

    BoolQuery bQuery;
    if (mode == 0) bQuery.addQuery(!plantillaPersonnelOfficeExist(pltPersonnelOffice), "Plantilla Personnel\nSheet already exists.");
    bQuery.addQuery(!pltPersonnelOffice.isEmpty(), "Type in\nthe name of\nthe sheet.");

    if (bQuery.earliestQuery().empty()){
        pltID = generateValidPltID();
        if (mode == 2) pltID = currentPltID;

        QSqlQuery query(datab);
        query.exec("DELETE FROM [LST PLT PERSONNEL] WHERE [PLT KEY] = '" + pltID + "'");
        query.prepare("INSERT INTO [LST PLT PERSONNEL] ([PLT KEY], [OFFICE], [PRINTED OFFICE], [CERTIFIED DATE], [LAST UPDATED]) "
                   "VALUES (:PLTKEY, :OFFICE, :PRINTEDOFFICE, :CERTIFIEDDATE, :LASTUPDATED)");
        query.bindValue(":PLTKEY", pltID);
        query.bindValue(":OFFICE", pltPersonnelOffice);
        query.bindValue(":PRINTEDOFFICE", printOfficeName);
        query.bindValue(":CERTIFIEDDATE", certifiedDate);
        query.bindValue(":LASTUPDATED", lastUpdate);
        query.exec();

        query.clear();
        query.exec("DELETE FROM [PLT PERSONNEL] WHERE [PLT KEY] = '" + pltID + "'");

        for (int i = 0; i < ui->plantillaPersonnelTable->rowCount(); i++){
            QString employeeID;
            QString fullName = ui->plantillaPersonnelTable->item(i, 4)->text();
            if (employeeIDMap.contains(fullName)) employeeID = employeeIDMap[fullName];
            else employeeID = "NONE";
            QString itemNo = ui->plantillaPersonnelTable->item(i, 0)->text();
            QString position = ui->plantillaPersonnelTable->item(i, 1)->text();
            QString level = ui->plantillaPersonnelTable->item(i, 2)->text();
            QString sg = ui->plantillaPersonnelTable->item(i, 3)->text();
            QString nameOfIncum = fullName;
            QString gender = ui->plantillaPersonnelTable->item(i, 5)->text();
            QString dateOfBirth = ui->plantillaPersonnelTable->item(i, 6)->text();
            QString dateOrigAppt = ui->plantillaPersonnelTable->item(i, 7)->text();
            QString dateLastProm = ui->plantillaPersonnelTable->item(i, 8)->text();
            QString empStatus = ui->plantillaPersonnelTable->item(i, 9)->text();
            QString edu = ui->plantillaPersonnelTable->item(i, 10)->text();
            QString elig = ui->plantillaPersonnelTable->item(i, 11)->text();

            query.clear();
            query.prepare("INSERT INTO [PLT PERSONNEL] ([PLT KEY], [EMPLOYEE ID], [ITEM NO], [POSITION], [LEVEL], [SG], [NAME INCUMBENT], [GENDER], "
                          "[DATE BIRTH], [DATE ORIG APPT], [DATE LAST PROM], [EMP STATUS], [EDU], [ELIG]) "
                       "VALUES (:PLTKEY, :EMPLOYEEID, :ITEMNO, :POSITION, :LEVEL, :SG, :NAMEINCUMBENT, :GENDER, :DATEBIRTH, :DATEORIGAPPT, "
                          ":DATELASTPROM, :EMPSTATUS, :EDU, :ELIG)");
            query.bindValue(":PLTKEY", pltID);
            query.bindValue(":EMPLOYEEID", employeeID);
            query.bindValue(":ITEMNO", itemNo);
            query.bindValue(":POSITION", position);
            query.bindValue(":LEVEL", level);
            query.bindValue(":SG", sg);
            query.bindValue(":NAMEINCUMBENT", nameOfIncum);
            query.bindValue(":GENDER", gender);
            query.bindValue(":DATEBIRTH", dateOfBirth);
            query.bindValue(":DATEORIGAPPT", dateOrigAppt);
            query.bindValue(":DATELASTPROM", dateLastProm);
            query.bindValue(":EMPSTATUS", empStatus);
            query.bindValue(":EDU", edu);
            query.bindValue(":ELIG", elig);
            query.exec();
        }

        updatePltPersonnelDetails(ui->certifiedCorrectDateEdit->date().toString().toStdString(),
                                  ui->approvedByNameEdit->text().toStdString(),
                                  ui->approvedByPosEdit->text().toStdString(),
                                  ui->signatureByNameEdit->text().toStdString(),
                                  ui->signatureByPosEdit->text().toStdString());
        if (goBackToViewPltPersonnel) on_backB_clicked();
    }
    else {
        displayTimedMessage(QString::fromStdString(bQuery.earliestQuery()), 3000);
    }
}

void PlantillaPersonnel::on_backB_clicked()
{
    EmployeeManagerHome *empManHome = (EmployeeManagerHome*)(stackWidget->widget(5));
    ViewPlantillaPersonnels *pPersonnel = (ViewPlantillaPersonnels*)(stackWidget->widget(6));
    switch (mode){
    case 0: {
        stackWidget->setCurrentIndex(5);
        empManHome->window()->showNormal();
    }; break;
    case 1: {
        pPersonnel->updateView();
        pPersonnel->window()->showNormal();
        stackWidget->setCurrentIndex(6);
    }; break;
    case 2: {
        pPersonnel->updateView();
        pPersonnel->window()->showNormal();
        stackWidget->setCurrentIndex(6);
    }; break;
    default: break;
    }
}

//true if successful
bool PlantillaPersonnelRowData::doublePositionLayer()
{
    if (ifStringHasSubstring(position.toStdString(), "(") && ifStringHasSubstring(position.toStdString(), ")") && position.size() > 4){
        string stdStrValue = position.toStdString();
        string internalStr = getStringBetweenStrings(stdStrValue, "(", ")");
        string firstStr = stdStrValue.substr(0, stdStrValue.find("(", 0) - 1);

        position = QString::fromStdString(firstStr);
        position2 = QString::fromStdString(internalStr);

        return true;
    }
    return false;
}
//set with ui.combobox
void PlantillaPersonnelRowData::setLevel(QString level)
{
    if (level == "None"){
        this->level = "-";
    }
    else if (level == "First Level"){
        this->level = "1st";
    }
    else if (level == "Second Level"){
        this->level = "2nd";
    }
    else if (level == "Non-Career"){
        this->level = "Non-Career";
    }
}

void PlantillaPersonnelRowData::setDateOfBirth(QDate date)
{
    if (!date.isValid()){
        dateOfBirth = "-";
    }
    else {
        dateOfBirth = date.toString("d-MMM-yy");
    }
}

void PlantillaPersonnelRowData::setDateOfAppt(QDate date)
{
    if (!date.isValid()){
        dateOfAppt = "-";
    }
    else {
        dateOfAppt = date.toString("d-MMM-yy");
    }
}

void PlantillaPersonnelRowData::setDateOfProm(QDate date)
{
    if (!date.isValid()){
        dateOfProm = "-";
    }
    else {
        dateOfProm = date.toString("d-MMM-yy");
    }
}

void PlantillaPersonnelRowData::adjustForRealAndVacantIncum()
{
    if (nameOfIncumbent.toUpper() == QString("Vacant").toUpper()){
        if (sg.isEmpty()) sg = "-";
        if (position.isEmpty()) position = "-";
        gender = "-";
        dateOfBirth = "-";
        dateOfAppt = "-";
        dateOfProm = "-";
        empStatus = "-";
        edu = "-";
        elig = "-";
    }
    else {
        if (sg.isEmpty()) sg = "-";
        if (position.isEmpty()) position = "None";
        if (gender.isEmpty()) gender = "Other";
        if (sg.isEmpty()) sg = "-";
        if (edu.isEmpty()) edu = "None";
        if (elig.isEmpty()) elig = "None";
    }
}

PlantillaPersonnelRowData::PlantillaPersonnelRowData()
{
    isDoubleLayered = false;
}

void PlantillaPersonnel::on_openExcelB_clicked()
{

    savePlantillaPersonnel(false);
//    string origFileName = removeLastOccurrenceStr(getCurrentFileDirector(), '\\') + "\\PlantillaPersonnelTest.xlsx";
    string origFileName = removeLastOccurrenceStr(getCurrentFileDirector(), '\\') + "\\PlantillaPersonnelTest.xlsx";
    string destFileName = removeLastOccurrenceStr(getCurrentFileDirector(), '\\') +
            "\\excelfiles\\PlantillaPersonnelTest.xlsx";

//    displayTimedMessage(QString::fromStdString(destFileName), 10000);

    if (ui->plantillaPersonnelTable->rowCount() != 0){
        if (fileExists(destFileName)) deleteFileOnly(destFileName);
        copyFileToDest(origFileName, destFileName);

        int rowLeft = 26;
        int rowNum = 9;
        QVector<PlantillaPersonnelRowData> pltPersonnelDataVec;
        QXlsx::Document xfile("excelfiles/PlantillaPersonnelTest.xlsx");    //TODO MODIFY
        xfile.sheet("2011");
        for (int i = 0; i < ui->plantillaPersonnelTable->rowCount(); i++){
            PlantillaPersonnelRowData pRowData;
            pRowData.itemNo = ui->plantillaPersonnelTable->item(i, 0)->text();
            pRowData.position = ui->plantillaPersonnelTable->item(i, 1)->text();
            pRowData.setLevel(ui->plantillaPersonnelTable->item(i, 2)->text());
            pRowData.sg = ui->plantillaPersonnelTable->item(i, 3)->text();
            pRowData.nameOfIncumbent = ui->plantillaPersonnelTable->item(i, 4)->text();
            pRowData.gender = ui->plantillaPersonnelTable->item(i, 5)->text();
            pRowData.setDateOfBirth(QDate::fromString(ui->plantillaPersonnelTable->item(i, 6)->text()));
            pRowData.setDateOfAppt(QDate::fromString(ui->plantillaPersonnelTable->item(i, 7)->text()));
            pRowData.setDateOfProm(QDate::fromString(ui->plantillaPersonnelTable->item(i, 8)->text()));
            pRowData.empStatus = ui->plantillaPersonnelTable->item(i, 9)->text();
            pRowData.edu = ui->plantillaPersonnelTable->item(i, 10)->text();
            pRowData.elig = ui->plantillaPersonnelTable->item(i, 11)->text();
            pRowData.adjustForRealAndVacantIncum();
            pRowData.excelRowNum = rowNum + i;
            pRowData.isDoubleLayered = false;
            pltPersonnelDataVec.push_back(pRowData);
            rowLeft--;
        }
        while (rowLeft > 0){
            if (pltPersonnelDataVec.last().isDoubleLayered) break;
            for (int i = 0; i < pltPersonnelDataVec.size(); i++){
                PlantillaPersonnelRowData rowData = pltPersonnelDataVec.at(i);
                string stdStrPos = rowData.position.toStdString();
                rowLeft--;
                if (rowLeft <= 0) break;
                if (!rowData.isDoubleLayered && stdStrPos.size() > 13 && ifStringHasSubstring(stdStrPos, "(")
                        && ifStringHasSubstring(stdStrPos, ")")){
                    rowData.doublePositionLayer();
                    rowData.isDoubleLayered = true;
                    pltPersonnelDataVec.replace(i, rowData);
                    for (int i2 = i + 1; i2 < pltPersonnelDataVec.size(); i2++){
                        PlantillaPersonnelRowData rowData2 = pltPersonnelDataVec.at(i2);
                        rowData2.excelRowNum++;
                        pltPersonnelDataVec.replace(i2, rowData2);
                    }
                }
            }
        }

        int vecIndex = 0;
        int rowCount = 0;
        while (rowCount < 26){
            if (vecIndex >= pltPersonnelDataVec.size()) break;
            PlantillaPersonnelRowData rowData = pltPersonnelDataVec.at(vecIndex);
            qDebug() << "index: " << vecIndex << endl;
            if (rowData.isDoubleLayered){
                rowCount += 2;
                if (rowCount >= 26) break;
                xfile.write("C" + QString::number(rowData.excelRowNum + 1), "(" + rowData.position2 + ")");
            }
            else rowCount++;
            if (rowCount >= 26) break;
            xfile.write("B" + QString::number(rowData.excelRowNum), rowData.itemNo);
            xfile.write("C" + QString::number(rowData.excelRowNum), rowData.position);
            xfile.write("D" + QString::number(rowData.excelRowNum), rowData.level);
            xfile.write("E" + QString::number(rowData.excelRowNum), rowData.sg);
            xfile.write("F" + QString::number(rowData.excelRowNum), rowData.nameOfIncumbent);
            xfile.write("G" + QString::number(rowData.excelRowNum), rowData.gender);
            xfile.write("H" + QString::number(rowData.excelRowNum), rowData.dateOfBirth);
            xfile.write("I" + QString::number(rowData.excelRowNum), rowData.dateOfAppt);
            xfile.write("J" + QString::number(rowData.excelRowNum), rowData.dateOfProm);
            xfile.write("K" + QString::number(rowData.excelRowNum), rowData.empStatus);
            xfile.write("L" + QString::number(rowData.excelRowNum), rowData.edu);
            xfile.write("M" + QString::number(rowData.excelRowNum), rowData.elig);
            vecIndex++;
        }
        QString officeStr = "Office of the " + ui->printedOfficeEdit->text();
        QXlsx::Format format;
        format.setFont(QFont("Arial"));
        format.setFontSize(11);
        QXlsx::Format format2;
        format2.setFont(QFont("Arial"));
        format2.setFontSize(11);
        format2.setFontUnderline(QXlsx::Format::FontUnderlineSingle);

        QXlsx::RichString rich;
        rich.addFragment("Office of the ", format);
        rich.addFragment(ui->printedOfficeEdit->text(), format2);
        xfile.write("A3", rich);
        xfile.write("A6", "As of " + ui->certifiedCorrectDateEdit->date().toString("MMMM d, yyyy"));
        xfile.write("I35", "CERTIFIED CORRECT as of " + ui->certifiedCorrectDateEdit->date().toString("MMMM d, yyyy"));
        xfile.write("C38", ui->approvedByNameEdit->text());
        xfile.write("C39", ui->approvedByPosEdit->text());
        xfile.write("H37", ui->signatureByNameEdit->text());
        xfile.write("H39", ui->signatureByPosEdit->text());
        xfile.save();
        launchFileWIthDefaultProg(destFileName);
    }
    else {
        displayTimedMessage("Table has no data.", 3000);
    }
}

void PlantillaPersonnel::messageReceived()
{

}
