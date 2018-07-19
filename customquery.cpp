#include "customquery.h"
#include "ui_customquery.h"

CustomQuery::CustomQuery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomQuery)
{
    ui->setupUi(this);
}

CustomQuery::~CustomQuery()
{
    delete ui;
}


void CustomQuery::on_executeB_clicked()
{
    QSqlQuery origquery(datab);

    origquery.exec(ui->sqlquery->text());

    int size = 0;
    while (origquery.next()) size++;
    if (ui->resultBox->toPlainText().size() == 0) ui->resultBox->setText(ui->resultBox->toPlainText() + "Query Size: " + QString::number(size));
    else ui->resultBox->setText(ui->resultBox->toPlainText() + "\nQuery Size: " + QString::number(size));

    origquery.clear();
    origquery.exec(ui->sqlquery->text());

    int queryInd = 0;
    while (origquery.next()){
        ui->resultBox->setText(ui->resultBox->toPlainText() + "\n" + origquery.value(queryInd).toString());
        queryInd++;
    }
}

void CustomQuery::on_clearB_clicked()
{
    ui->resultBox->clear();
    ui->sqlquery->clear();
}
void CustomQuery::setDatab(const QSqlDatabase &value)
{
    datab = value;
}


void CustomQuery::on_backB_clicked()
{
    stackWidget->setCurrentIndex(5);
}
