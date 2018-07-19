#include "numplantillavacpos.h"
#include "ui_numplantillavacpos.h"



NumPlantillaVacPos::NumPlantillaVacPos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumPlantillaVacPos)
{
    ui->setupUi(this);

//    ui->numPlantillaVacPosTable->setColumnCount(13);
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("No."), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("Name of Agency/\nOffices"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(2, new QTableWidgetItem(QString("No. of Plantilla Positions\n(1st Level)"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(3, new QTableWidgetItem(QString("No. of Plantilla Positions\n(2nd Level)"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(4, new QTableWidgetItem(QString("TOTAL"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(5, new QTableWidgetItem(QString("No. of Vacant Plantilla\nPositions(1st Level)"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(6, new QTableWidgetItem(QString("No. of Vacant Plantilla\nPositions(2nd Level)"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(7, new QTableWidgetItem(QString("TOTAL"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(8, new QTableWidgetItem(QString("Non-Career Employees\n(Coterminous)"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(9, new QTableWidgetItem(QString("Non-Career Employees\n(Casual)"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(10, new QTableWidgetItem(QString("Non-Career Employees\n(Contract of Service)"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(11, new QTableWidgetItem(QString("Non-Career Employees\n(Job Orders)"), QTableWidgetItem::Type));
//    ui->numPlantillaVacPosTable->setHorizontalHeaderItem(12, new QTableWidgetItem(QString("TOTAL"), QTableWidgetItem::Type));

//    ui->numPlantillaVacPosTable->setColumnWidth(0, 100);
//    ui->numPlantillaVacPosTable->setColumnWidth(1, 300);
//    ui->numPlantillaVacPosTable->setColumnWidth(2, 200);
//    ui->numPlantillaVacPosTable->setColumnWidth(3, 200);
//    ui->numPlantillaVacPosTable->setColumnWidth(4, 150);
//    ui->numPlantillaVacPosTable->setColumnWidth(5, 200);
//    ui->numPlantillaVacPosTable->setColumnWidth(6, 200);
//    ui->numPlantillaVacPosTable->setColumnWidth(7, 150);
//    ui->numPlantillaVacPosTable->setColumnWidth(8, 200);
//    ui->numPlantillaVacPosTable->setColumnWidth(9, 200);
//    ui->numPlantillaVacPosTable->setColumnWidth(10, 200);
//    ui->numPlantillaVacPosTable->setColumnWidth(11, 200);
//    ui->numPlantillaVacPosTable->setColumnWidth(12, 150);


    ui->noPltPosFirstLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->noPltPosSecondLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->pltPosTotal->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->vanPltPosFirstLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->vanPltPosSecondLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->vacPltPosTotal->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->coterminous->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->casual->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->contractOfService->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->jobOrders->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));

    ui->permMaleFirstLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->permMaleSecondLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->permFemaleFirstLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->permFemaleSecondLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->totalMale->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->totalFemale->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->totalFirstLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->totalSecondLvl->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
    ui->totalPlantillaPersonnel->setValidator( new QDoubleValidator(0, 99999999999999999999999999999, 0, this));
}

NumPlantillaVacPos::~NumPlantillaVacPos()
{
    delete ui;
}


void NumPlantillaVacPos::on_updateB_clicked()
{
    int tempsize = 0;

    ui->nameOFAgency->setText("LGU, Municipality of Sibulan");
    QSqlQuery origquery(datab);

    origquery.exec("SELECT * FROM [PLT PERSONNEL] WHERE [LEVEL] Like 'First Level' AND UCASE([NAME INCUMBENT]) <> UCASE('vacant')");
    while (origquery.next()) tempsize++;
    ui->noPltPosFirstLvl->setText(QString::number(tempsize));

    tempsize = 0;
    origquery.clear();
    origquery.exec("SELECT * FROM [PLT PERSONNEL] WHERE [LEVEL] Like 'Second Level' AND UCASE([NAME INCUMBENT]) <> UCASE('vacant');");
    while (origquery.next()) tempsize++;
    ui->noPltPosSecondLvl->setText(QString::number(tempsize));

    ui->pltPosTotal->setText(QString::number(ui->noPltPosFirstLvl->text().toInt() + ui->noPltPosSecondLvl->text().toInt()));

    tempsize = 0;
    origquery.clear();
    origquery.exec("SELECT * FROM [PLT PERSONNEL] WHERE [LEVEL] Like 'First Level' AND UCASE([NAME INCUMBENT]) = UCASE('vacant');");
    while (origquery.next()) tempsize++;
    ui->vanPltPosFirstLvl->setText(QString::number(tempsize));

    tempsize = 0;
    origquery.clear();
    origquery.exec("SELECT * FROM [PLT PERSONNEL] WHERE [LEVEL] Like 'Second Level' AND UCASE([NAME INCUMBENT]) = UCASE('vacant');");
    while (origquery.next()) tempsize++;
    ui->vanPltPosSecondLvl->setText(QString::number(tempsize));

    ui->vacPltPosTotal->setText(QString::number(ui->vanPltPosFirstLvl->text().toInt() + ui->vanPltPosSecondLvl->text().toInt()));


    tempsize = 0;
    origquery.clear();
    origquery.exec("SELECT * FROM [PLT CASUAL APPT];");
    while (origquery.next()) tempsize++;
    ui->casual->setText(QString::number(tempsize));
    on_casual_textEdited(ui->casual->text());

    ui->coterminous->setText(QString::number(0));
    ui->contractOfService->setText(QString::number(0));
    ui->jobOrders->setText(QString::number(0));
    on_coterminous_textEdited(ui->coterminous->text());


    tempsize = 0;
    origquery.clear();
    origquery.exec("SELECT * FROM [PLT PERSONNEL] WHERE [LEVEL] Like 'First Level' AND UCASE([EMP STATUS]) = UCASE('permanent') "
                   "AND UCASE([NAME INCUMBENT]) <> UCASE('vacant') AND UCASE([GENDER]) = UCASE('male');");
    while (origquery.next()) tempsize++;
    ui->permMaleFirstLvl->setText(QString::number(tempsize));
    on_permMaleFirstLvl_textEdited(ui->permMaleFirstLvl->text());

    tempsize = 0;
    origquery.clear();
    origquery.exec("SELECT * FROM [PLT PERSONNEL] WHERE [LEVEL] Like 'Second Level' AND UCASE([EMP STATUS]) = UCASE('permanent') "
                   "AND UCASE([NAME INCUMBENT]) <> UCASE('vacant') AND UCASE([GENDER]) = UCASE('male');");
    while (origquery.next()) tempsize++;
    ui->permMaleSecondLvl->setText(QString::number(tempsize));
    on_permMaleSecondLvl_textEdited(ui->permMaleSecondLvl->text());

    tempsize = 0;
    origquery.clear();
    origquery.exec("SELECT * FROM [PLT PERSONNEL] WHERE [LEVEL] Like 'First Level' AND UCASE([EMP STATUS]) = UCASE('permanent') "
                   "AND UCASE([NAME INCUMBENT]) <> UCASE('vacant') AND UCASE([GENDER]) = UCASE('female');");
    while (origquery.next()) tempsize++;
    ui->permFemaleFirstLvl->setText(QString::number(tempsize));
    on_permFemaleFirstLvl_textEdited(ui->permFemaleFirstLvl->text());

    tempsize = 0;
    origquery.clear();
    origquery.exec("SELECT * FROM [PLT PERSONNEL] WHERE [LEVEL] Like 'Second Level' AND UCASE([EMP STATUS]) = UCASE('permanent') "
                   "AND UCASE([NAME INCUMBENT]) <> UCASE('vacant') AND UCASE([GENDER]) = UCASE('female');");
    while (origquery.next()) tempsize++;
    ui->permFemaleSecondLvl->setText(QString::number(tempsize));
    on_permFemaleSecondLvl_textEdited(ui->permFemaleSecondLvl->text());
}

void NumPlantillaVacPos::on_noPltPosFirstLvl_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    if (str.size() != 0) value1 = str.toInt();
    if (ui->noPltPosSecondLvl->text().size() != 0) value2 = ui->noPltPosSecondLvl->text().toInt();
    ui->pltPosTotal->setText(QString::number(value1 + value2));
}

void NumPlantillaVacPos::on_noPltPosSecondLvl_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    if (ui->noPltPosFirstLvl->text().size() != 0) value1 = ui->noPltPosFirstLvl->text().toInt();
    if (str.size() != 0) value2 = str.toInt();
    ui->pltPosTotal->setText(QString::number(value1 + value2));
}

void NumPlantillaVacPos::on_vanPltPosFirstLvl_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    if (str.size() != 0) value1 = str.toInt();
    if (ui->vanPltPosSecondLvl->text().size() != 0) value2 = ui->vanPltPosSecondLvl->text().toInt();
    ui->vacPltPosTotal->setText(QString::number(value1 + value2));
}

void NumPlantillaVacPos::on_vanPltPosSecondLvl_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    if (ui->vanPltPosFirstLvl->text().size() != 0) value1 = ui->vanPltPosFirstLvl->text().toInt();
    if (str.size() != 0) value2 = str.toInt();
    ui->vacPltPosTotal->setText(QString::number(value1 + value2));
}

void NumPlantillaVacPos::on_coterminous_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int value4 = 0;
    if (str.size() != 0) value1 = str.toInt();
    if (ui->casual->text().size() != 0) value2 = ui->casual->text().toInt();
    if (ui->contractOfService->text().size() != 0) value3 = ui->contractOfService->text().toInt();
    if (ui->jobOrders->text().size() != 0) value4 = ui->jobOrders->text().toInt();
    ui->nonCareerTotal->setText(QString::number(value1 + value2 + value3 + value4));
}

void NumPlantillaVacPos::on_casual_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int value4 = 0;
    if (ui->coterminous->text().size() != 0) value1 = ui->coterminous->text().toInt();
    if (str.size() != 0) value2 = str.toInt();
    if (ui->contractOfService->text().size() != 0) value3 = ui->contractOfService->text().toInt();
    if (ui->jobOrders->text().size() != 0) value4 = ui->jobOrders->text().toInt();
    ui->nonCareerTotal->setText(QString::number(value1 + value2 + value3 + value4));
}

void NumPlantillaVacPos::on_contractOfService_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int value4 = 0;
    if (ui->coterminous->text().size() != 0) value1 = ui->coterminous->text().toInt();
    if (ui->casual->text().size() != 0) value2 = ui->casual->text().toInt();
    if (str.size() != 0) value3 = str.toInt();
    if (ui->jobOrders->text().size() != 0) value4 = ui->jobOrders->text().toInt();
    ui->nonCareerTotal->setText(QString::number(value1 + value2 + value3 + value4));
}

void NumPlantillaVacPos::on_jobOrders_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int value4 = 0;
    if (ui->coterminous->text().size() != 0) value1 = ui->coterminous->text().toInt();
    if (ui->casual->text().size() != 0) value2 = ui->casual->text().toInt();
    if (ui->contractOfService->text().size() != 0) value3 = ui->contractOfService->text().toInt();
    if (str.size() != 0) value4 = str.toInt();
    ui->nonCareerTotal->setText(QString::number(value1 + value2 + value3 + value4));
}

void NumPlantillaVacPos::on_backB_clicked()
{
    stackWidget->setCurrentIndex(5);
}

void NumPlantillaVacPos::on_permMaleFirstLvl_textEdited(const QString str)
{

//    int value1 = 0;
//    int value2 = 0;
//    if (ui->permMaleFirstLvl->text().size() != 0) value1 = ui->permMaleFirstLvl->text().toInt();
//    if (ui->permFemaleFirstLvl->text().size() != 0) value2 = ui->permFemaleFirstLvl->text().toInt();
//    ui->totalFirstLvl->setText(QString::number(value1 + value2));

//    int value3 = 0;
//    int value4 = 0;
//    if (ui->permMaleFirstLvl->text().size() != 0) value3 = ui->permMaleFirstLvl->text().toInt();
//    if (ui->permMaleSecondLvl->text().size() != 0) value4 = ui->permMaleSecondLvl->text().toInt();
//    ui->totalMale->setText(QString::number(value3 + value4));

//    int value5 = 0;
//    int value6 = 0;
//    int value7 = 0;
//    int value8 = 0;
//    if (ui->permMaleFirstLvl->text().size() != 0) value5 = ui->permMaleFirstLvl->text().toInt();
//    if (ui->permMaleSecondLvl->text().size() != 0) value6 = ui->permMaleSecondLvl->text().toInt();
//    if (ui->permFemaleFirstLvl->text().size() != 0) value7 = ui->permFemaleFirstLvl->text().toInt();
//    if (ui->permFemaleSecondLvl->text().size() != 0) value8 = ui->permFemaleSecondLvl->text().toInt();
//    ui->totalPlantillaPersonnel->setText(QString::number(value5 + value6 + value7 + value8));



    int value1 = 0;
    int value2 = 0;
    if (str.size() != 0) value1 = str.toInt();
    if (ui->permFemaleFirstLvl->text().size() != 0) value2 = ui->permFemaleFirstLvl->text().toInt();
    ui->totalFirstLvl->setText(QString::number(value1 + value2));

    int value3 = 0;
    int value4 = 0;
    if (str.size() != 0) value3 = str.toInt();
    if (ui->permMaleSecondLvl->text().size() != 0) value4 = ui->permMaleSecondLvl->text().toInt();
    ui->totalMale->setText(QString::number(value3 + value4));

    int value5 = 0;
    int value6 = 0;
    int value7 = 0;
    int value8 = 0;
    if (str.size() != 0) value5 = str.toInt();
    if (ui->permMaleSecondLvl->text().size() != 0) value6 = ui->permMaleSecondLvl->text().toInt();
    if (ui->permFemaleFirstLvl->text().size() != 0) value7 = ui->permFemaleFirstLvl->text().toInt();
    if (ui->permFemaleSecondLvl->text().size() != 0) value8 = ui->permFemaleSecondLvl->text().toInt();
    ui->totalPlantillaPersonnel->setText(QString::number(value5 + value6 + value7 + value8));
}

void NumPlantillaVacPos::on_permMaleSecondLvl_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    if (str.size() != 0) value1 = str.toInt();
    if (ui->permFemaleSecondLvl->text().size() != 0) value2 = ui->permFemaleSecondLvl->text().toInt();
    ui->totalSecondLvl->setText(QString::number(value1 + value2));

    int value3 = 0;
    int value4 = 0;
    if (ui->permMaleFirstLvl->text().size() != 0) value3 = ui->permMaleFirstLvl->text().toInt();
    if (str.size() != 0) value4 = str.toInt();
    ui->totalMale->setText(QString::number(value3 + value4));

    int value5 = 0;
    int value6 = 0;
    int value7 = 0;
    int value8 = 0;
    if (ui->permMaleFirstLvl->text().size() != 0) value5 = ui->permMaleFirstLvl->text().toInt();
    if (str.size() != 0) value6 = str.toInt();
    if (ui->permFemaleFirstLvl->text().size() != 0) value7 = ui->permFemaleFirstLvl->text().toInt();
    if (ui->permFemaleSecondLvl->text().size() != 0) value8 = ui->permFemaleSecondLvl->text().toInt();
    ui->totalPlantillaPersonnel->setText(QString::number(value5 + value6 + value7 + value8));
}

void NumPlantillaVacPos::on_permFemaleFirstLvl_textEdited(const QString str)
{
//        int value1 = 0;
//        int value2 = 0;
//        if (ui->permMaleFirstLvl->text().size() != 0) value1 = ui->permMaleFirstLvl->text().toInt();
//        if (ui->permFemaleFirstLvl->text().size() != 0) value2 = ui->permFemaleFirstLvl->text().toInt();
//        ui->totalFirstLvl->setText(QString::number(value1 + value2));

//        int value3 = 0;
//        int value4 = 0;
//        if (ui->permFemaleFirstLvl->text().size() != 0) value3 = ui->permFemaleFirstLvl->text().toInt();
//        if (ui->permFemaleSecondLvl->text().size() != 0) value4 = ui->permFemaleSecondLvl->text().toInt();
//        ui->totalFemale->setText(QString::number(value3 + value4));

//        int value5 = 0;
//        int value6 = 0;
//        int value7 = 0;
//        int value8 = 0;
//        if (ui->permMaleFirstLvl->text().size() != 0) value5 = ui->permMaleFirstLvl->text().toInt();
//        if (ui->permMaleSecondLvl->text().size() != 0) value6 = ui->permMaleSecondLvl->text().toInt();
//        if (ui->permFemaleFirstLvl->text().size() != 0) value7 = ui->permFemaleFirstLvl->text().toInt();
//        if (ui->permFemaleSecondLvl->text().size() != 0) value8 = ui->permFemaleSecondLvl->text().toInt();
//        ui->totalPlantillaPersonnel->setText(QString::number(value5 + value6 + value7 + value8));


    int value1 = 0;
    int value2 = 0;
    if (ui->permMaleFirstLvl->text().size() != 0) value1 = ui->permMaleFirstLvl->text().toInt();
    if (str.size() != 0) value2 = str.toInt();
    ui->totalFirstLvl->setText(QString::number(value1 + value2));

    int value3 = 0;
    int value4 = 0;
    if (str.size() != 0) value3 = str.toInt();
    if (ui->permFemaleSecondLvl->text().size() != 0) value4 = ui->permFemaleSecondLvl->text().toInt();
    ui->totalFemale->setText(QString::number(value3 + value4));

    int value5 = 0;
    int value6 = 0;
    int value7 = 0;
    int value8 = 0;
    if (ui->permMaleFirstLvl->text().size() != 0) value5 = ui->permMaleFirstLvl->text().toInt();
    if (ui->permMaleSecondLvl->text().size() != 0) value6 = ui->permMaleSecondLvl->text().toInt();
    if (str.size() != 0) value7 = str.toInt();
    if (ui->permFemaleSecondLvl->text().size() != 0) value8 = ui->permFemaleSecondLvl->text().toInt();
    ui->totalPlantillaPersonnel->setText(QString::number(value5 + value6 + value7 + value8));
}

void NumPlantillaVacPos::on_permFemaleSecondLvl_textEdited(const QString str)
{
    int value1 = 0;
    int value2 = 0;
    if (ui->permMaleSecondLvl->text().size() != 0) value1 = ui->permMaleSecondLvl->text().toInt();
    if (str.size() != 0) value2 = str.toInt();
    ui->totalSecondLvl->setText(QString::number(value1 + value2));

    int value3 = 0;
    int value4 = 0;
    if (ui->permFemaleFirstLvl->text().size() != 0) value3 = ui->permFemaleFirstLvl->text().toInt();
    if (str.size() != 0) value4 = str.toInt();
    ui->totalFemale->setText(QString::number(value3 + value4));

    int value5 = 0;
    int value6 = 0;
    int value7 = 0;
    int value8 = 0;
    if (ui->permMaleFirstLvl->text().size() != 0) value5 = ui->permMaleFirstLvl->text().toInt();
    if (ui->permMaleSecondLvl->text().size() != 0) value6 = ui->permMaleSecondLvl->text().toInt();
    if (ui->permFemaleFirstLvl->text().size() != 0) value7 = ui->permFemaleFirstLvl->text().toInt();
    if (str.size() != 0) value8 = str.toInt();
    ui->totalPlantillaPersonnel->setText(QString::number(value5 + value6 + value7 + value8));
}
void NumPlantillaVacPos::setDatab(const QSqlDatabase &value)
{
    datab = value;
}

