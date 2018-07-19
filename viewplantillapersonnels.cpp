#include "viewplantillapersonnels.h"
#include "ui_viewplantillapersonnels.h"

ViewPlantillaPersonnels::ViewPlantillaPersonnels(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewPlantillaPersonnels)
{
    ui->setupUi(this);

    QFont f1("Segoe UI", 11);
    f1.setBold(true);

    QTableWidgetItem *nameHeader = new QTableWidgetItem("Office");
    nameHeader->setTextAlignment(Qt::AlignCenter);
    nameHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    nameHeader->setFont(f1);
    QTableWidgetItem *addrHeader = new QTableWidgetItem("Certified Date");
    addrHeader->setTextAlignment(Qt::AlignCenter);
    addrHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    addrHeader->setFont(f1);
    QTableWidgetItem *emailHeader = new QTableWidgetItem("Last Updated");
    emailHeader->setTextAlignment(Qt::AlignCenter);
    emailHeader->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    emailHeader->setFont(f1);

    ui->plantillaPersonnelsTable->setColumnCount(3);
    ui->plantillaPersonnelsTable->setHorizontalHeaderItem(0, nameHeader);
    ui->plantillaPersonnelsTable->setHorizontalHeaderItem(1, addrHeader);
    ui->plantillaPersonnelsTable->setHorizontalHeaderItem(2, emailHeader);

    ui->plantillaPersonnelsTable->setColumnWidth(0, 300);
    ui->plantillaPersonnelsTable->setColumnWidth(1, 300);
    ui->plantillaPersonnelsTable->setColumnWidth(2, 300);
    ui->plantillaPersonnelsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
}

ViewPlantillaPersonnels::~ViewPlantillaPersonnels()
{
    delete ui;
}

void ViewPlantillaPersonnels::updateView()
{
    ui->plantillaPersonnelsTable->setRowCount(0);
    pltIDMap.clear();

    QSqlQuery query(datab);
    query.exec("SELECT [PLT KEY], [OFFICE], [CERTIFIED DATE], [LAST UPDATED] FROM [LST PLT PERSONNEL]");
    while (query.next()){
        QString pltKey = query.value(0).toString();
        QString office = query.value(1).toString();
        QString certifiedDate = query.value(2).toString();
        QString lastUpdated = query.value(3).toString();

        pltIDMap[office] = pltKey;
        ui->plantillaPersonnelsTable->setRowCount(ui->plantillaPersonnelsTable->rowCount() + 1);

        QTableWidgetItem *officeItem = new QTableWidgetItem(office);
        officeItem->setTextAlignment(Qt::AlignCenter);
        officeItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *certifiedDateItem = new QTableWidgetItem(certifiedDate);
        certifiedDateItem->setTextAlignment(Qt::AlignCenter);
        certifiedDateItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QTableWidgetItem *lastUpdatedItem = new QTableWidgetItem(lastUpdated);
        lastUpdatedItem->setTextAlignment(Qt::AlignCenter);
        lastUpdatedItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->plantillaPersonnelsTable->setItem(ui->plantillaPersonnelsTable->rowCount() - 1, 0, officeItem);
        ui->plantillaPersonnelsTable->setItem(ui->plantillaPersonnelsTable->rowCount() - 1, 1, certifiedDateItem);
        ui->plantillaPersonnelsTable->setItem(ui->plantillaPersonnelsTable->rowCount() - 1, 2, lastUpdatedItem);
    }
}


void ViewPlantillaPersonnels::on_backB_clicked()
{
    stackWidget->setCurrentIndex(5);
}

void ViewPlantillaPersonnels::on_officeSearch_textEdited(const QString name)
{
    int rowCount = ui->plantillaPersonnelsTable->rowCount();
    for (int i = 0; i < rowCount; i++){
        ui->plantillaPersonnelsTable->setRowHidden(i, false);
    }
    for (int i = 0; i < rowCount; i++){
        if (!ifStringHasSubstring(ui->plantillaPersonnelsTable->item(i, 0)->text().toLower().toStdString(), name.toLower().toStdString())){
            ui->plantillaPersonnelsTable->setRowHidden(i, true);
        }
    }
}

void ViewPlantillaPersonnels::on_editB_clicked()
{
    if (!selectedOfficeName.isEmpty()){
        PlantillaPersonnel *pPersonnel = (PlantillaPersonnel*)(stackWidget->widget(1));
        pPersonnel->setMode(2);
        pPersonnel->on_clearB_clicked();
        pPersonnel->on_clearFields_clicked();
        pPersonnel->updateViews();
        pPersonnel->setFieldsWithID(pltIDMap[selectedOfficeName], selectedOfficeName, selectedCertDate);

        QSqlQuery query(datab);
        QString printedOffice = "";
        query.exec("SELECT [PRINTED OFFICE] FROM [LST PLT PERSONNEL] WHERE [OFFICE] = '" + selectedOfficeName + "'");
        while (query.next()){
            printedOffice = query.value(0).toString();
        }
        pPersonnel->setPrintedOfficeName(printedOffice);
        pPersonnel->updateItemNumbers();

        stackWidget->setCurrentIndex(1);
        stackWidget->window()->showMaximized();
    }
}

void ViewPlantillaPersonnels::on_plantillaPersonnelsTable_cellPressed(int row, int column)
{
    QTableWidgetItem *item = ui->plantillaPersonnelsTable->item(row, 0);
    selectedOfficeName = item->text();
    QTableWidgetItem *item2 = ui->plantillaPersonnelsTable->item(row, 1);
    selectedCertDate = item2->text();
}

void ViewPlantillaPersonnels::on_refreshB_clicked()
{
    updateView();
}

void ViewPlantillaPersonnels::on_deleteB_clicked()
{
    if (!selectedOfficeName.isEmpty()){
        QString pltID = pltIDMap[selectedOfficeName];

        int rowNum = -1;
        QModelIndexList indexes = ui->plantillaPersonnelsTable->selectionModel()->selection().indexes();
        for (int i = 0; i < indexes.count(); ++i){
            QModelIndex index = indexes.at(i);
            rowNum = index.row();
        }
        if (rowNum != -1){
            ui->plantillaPersonnelsTable->removeRow(rowNum);
        }

        QSqlQuery query(datab);
        query.exec("DELETE FROM [LST PLT PERSONNEL] WHERE [PLT KEY] = '" + pltID + "'");
        query.exec("DELETE FROM [PLT PERSONNEL] WHERE [PLT KEY] = '" + pltID + "'");
        pltIDMap.remove(selectedOfficeName);
        updateView();
    }
}
void ViewPlantillaPersonnels::setDatab(const QSqlDatabase &value)
{
    datab = value;
}

