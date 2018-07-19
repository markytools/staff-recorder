#include "viewplantillacasualappt.h"
#include "ui_viewplantillacasualappt.h"

ViewPlantillaCasualAppt::ViewPlantillaCasualAppt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewPlantillaCasualAppt)
{
    ui->setupUi(this);

    QFont f1("Segoe UI", 11);
    f1.setBold(true);

    QTableWidgetItem *nameHeader = new QTableWidgetItem("Department/Division");
    nameHeader->setTextAlignment(Qt::AlignCenter);
    nameHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    nameHeader->setFont(f1);
    QTableWidgetItem *addrHeader = new QTableWidgetItem("Source of Funds");
    addrHeader->setTextAlignment(Qt::AlignCenter);
    addrHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    addrHeader->setFont(f1);
    QTableWidgetItem *emailHeader = new QTableWidgetItem("Date Prepared by HRMO");
    emailHeader->setTextAlignment(Qt::AlignCenter);
    emailHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    emailHeader->setFont(f1);
    QTableWidgetItem *lastUpdated = new QTableWidgetItem("Last Updated");
    lastUpdated->setTextAlignment(Qt::AlignCenter);
    lastUpdated->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    lastUpdated->setFont(f1);

    ui->plantillaCAppointmentsTable->setColumnCount(4);
    ui->plantillaCAppointmentsTable->setHorizontalHeaderItem(0, nameHeader);
    ui->plantillaCAppointmentsTable->setHorizontalHeaderItem(1, addrHeader);
    ui->plantillaCAppointmentsTable->setHorizontalHeaderItem(2, emailHeader);
    ui->plantillaCAppointmentsTable->setHorizontalHeaderItem(3, lastUpdated);

    ui->plantillaCAppointmentsTable->setColumnWidth(0, 400);
    ui->plantillaCAppointmentsTable->setColumnWidth(1, 250);
    ui->plantillaCAppointmentsTable->setColumnWidth(2, 400);
    ui->plantillaCAppointmentsTable->setColumnWidth(3, 300);
    ui->plantillaCAppointmentsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
}

ViewPlantillaCasualAppt::~ViewPlantillaCasualAppt()
{
    delete ui;
}

void ViewPlantillaCasualAppt::updateView()
{
    ui->plantillaCAppointmentsTable->setRowCount(0);
    pltIDMap.clear();

    QSqlQuery query(datab);
    query.exec("SELECT [PLT KEY], [DEPT], [SOURCE FUND], [DATE PREPARED], [LAST UPDATED] FROM [LST PLT CASUAL APPT]");
    while (query.next()){
        QString pltKey = query.value(0).toString();
        QString deptDiv = query.value(1).toString();
        QString sourceFund = query.value(2).toString();
        QString datePrepared = query.value(3).toString();
        QString lastUpdated = query.value(4).toString();

        pltIDMap[deptDiv] = pltKey;
        ui->plantillaCAppointmentsTable->setRowCount(ui->plantillaCAppointmentsTable->rowCount() + 1);

        QTableWidgetItem *deptDivItem = new QTableWidgetItem(deptDiv);
        deptDivItem->setTextAlignment(Qt::AlignCenter);
        deptDivItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *sourceFundItem = new QTableWidgetItem(sourceFund);
        sourceFundItem->setTextAlignment(Qt::AlignCenter);
        sourceFundItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *datePrepareddItem = new QTableWidgetItem(datePrepared);
        datePrepareddItem->setTextAlignment(Qt::AlignCenter);
        datePrepareddItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *lastUpdatedItem = new QTableWidgetItem(lastUpdated);
        lastUpdatedItem->setTextAlignment(Qt::AlignCenter);
        lastUpdatedItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->plantillaCAppointmentsTable->setItem(ui->plantillaCAppointmentsTable->rowCount() - 1, 0, deptDivItem);
        ui->plantillaCAppointmentsTable->setItem(ui->plantillaCAppointmentsTable->rowCount() - 1, 1, sourceFundItem);
        ui->plantillaCAppointmentsTable->setItem(ui->plantillaCAppointmentsTable->rowCount() - 1, 2, datePrepareddItem);
        ui->plantillaCAppointmentsTable->setItem(ui->plantillaCAppointmentsTable->rowCount() - 1, 3, lastUpdatedItem);
    }
}


void ViewPlantillaCasualAppt::on_backB_clicked()
{
    stackWidget->setCurrentIndex(5);
}

void ViewPlantillaCasualAppt::on_nameSearch_textEdited(const QString name)
{
    int rowCount = ui->plantillaCAppointmentsTable->rowCount();
    for (int i = 0; i < rowCount; i++){
        ui->plantillaCAppointmentsTable->setRowHidden(i, false);
    }
    for (int i = 0; i < rowCount; i++){
        if (!ifStringHasSubstring(ui->plantillaCAppointmentsTable->item(i, 0)->text().toLower().toStdString(), name.toLower().toStdString())){
            ui->plantillaCAppointmentsTable->setRowHidden(i, true);
        }
    }
}

void ViewPlantillaCasualAppt::on_refreshB_clicked()
{
    updateView();
}

void ViewPlantillaCasualAppt::on_deleteB_clicked()
{
    if (!selectedDivName.isEmpty()){
        QString pltID = pltIDMap[selectedDivName];

        int rowNum = -1;
        QModelIndexList indexes = ui->plantillaCAppointmentsTable->selectionModel()->selection().indexes();
        for (int i = 0; i < indexes.count(); ++i){
            QModelIndex index = indexes.at(i);
            rowNum = index.row();
        }
        if (rowNum != -1){
            ui->plantillaCAppointmentsTable->removeRow(rowNum);
        }

        QSqlQuery query(datab);
        query.exec("DELETE FROM [LST PLT CASUAL APPT] WHERE [PLT KEY] = '" + pltID + "'");
        query.exec("DELETE FROM [PLT CASUAL APPT] WHERE [PLT KEY] = '" + pltID + "'");
        pltIDMap.remove(selectedDivName);
        updateView();
    }
}

void ViewPlantillaCasualAppt::on_plantillaCAppointmentsTable_cellPressed(int row, int column)
{
    QTableWidgetItem *item = ui->plantillaCAppointmentsTable->item(row, 0);
    selectedDivName = item->text();
    QTableWidgetItem *item2 = ui->plantillaCAppointmentsTable->item(row, 1);
    selectedSourceFunds = item2->text();
    QTableWidgetItem *item3 = ui->plantillaCAppointmentsTable->item(row, 2);
    selectedDatePrep = item3->text();
}

void ViewPlantillaCasualAppt::on_editB_clicked()
{
    if (!selectedDivName.isEmpty()){
        PlantillaCasual *pCasual = (PlantillaCasual*)(stackWidget->widget(2));
        pCasual->setMode(2);
        pCasual->on_clearFieldsB_clicked();
        pCasual->on_clearTableB_clicked();
        pCasual->updateView();
        pCasual->setFieldsWithID(pltIDMap[selectedDivName], selectedDivName, selectedSourceFunds, selectedDatePrep);
        stackWidget->setCurrentIndex(2);
        stackWidget->window()->showMaximized();
    }
}
void ViewPlantillaCasualAppt::setDatab(const QSqlDatabase &value)
{
    datab = value;
}

