#include "newemployee.h"
#include "ui_newemployee.h"

NewEmployee::NewEmployee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewEmployee)
{
    ui->setupUi(this);

    boolQuery = new BoolQuery();

    totalSpouses = 0;
    totalChildren = 0;
    totalEduBg = 0;
    totalCivilService = 0;
    totalServiceRecord = 0;
    totalVoluntaryWork = 0;
    totalTrainingProg = 0;
    totalNonAcademicRec = 0;
    totalReferences = 0;
    totalSkills = 0;
    totalOrgMembership = 0;

    ui->deleteSpouseB->setVisible(false);
    ui->deleteChild->setVisible(false);
    ui->deleteEduBg->setVisible(false);
    ui->deleteCivilServ->setVisible(false);
    ui->deleteServiceRecord->setVisible(false);
    ui->deleteVWorkB->setVisible(false);
    ui->deleteTrainingProgramB->setVisible(false);
    ui->deleteSkillHobbyB->setVisible(false);
    ui->deleteNonAcademicRecB->setVisible(false);
    ui->deleteOrgMembership->setVisible(false);
    ui->deleteReferenceB->setVisible(false);

    ui->otherCStatusEdit->setDisabled(true);
    ui->question1ATextEdit->setDisabled(true);
    ui->question1BTextEdit->setDisabled(true);
    ui->question2ATextEdit->setDisabled(true);
    ui->question2BTextEdit->setDisabled(true);
    ui->question3ATextEdit->setDisabled(true);
    ui->question4ATextEdit->setDisabled(true);
    ui->question5ATextEdit->setDisabled(true);
    ui->question6ATextEdit->setDisabled(true);
    ui->question6BTextEdit->setDisabled(true);
    ui->question6CTextEdit->setDisabled(true);


    ui->heightEdit->setValidator( new QDoubleValidator(0, 10000, 2, this));
    ui->feetEdit->setValidator( new QDoubleValidator(0, 10000, 2, this));
    ui->inchEdit->setValidator( new QDoubleValidator(0, 10000, 2, this));
    ui->weightEdit->setValidator( new QDoubleValidator(0, 10000, 2, this));


    QButtonGroup *genderBGroup = new QButtonGroup(this);
    genderBGroup->addButton(ui->maleCB);
    genderBGroup->addButton(ui->femaleCB);

    QButtonGroup *statusBGroup = new QButtonGroup(this);
    statusBGroup->addButton(ui->singleCB);
    statusBGroup->addButton(ui->marriedCB);
    statusBGroup->addButton(ui->annulledCB);
    statusBGroup->addButton(ui->widowedCB);
    statusBGroup->addButton(ui->separatedCB);
    statusBGroup->addButton(ui->otherCStatusCB);

    QButtonGroup *question1AGroup = new QButtonGroup(this);
    question1AGroup->addButton(ui->question1AYesCB);
    question1AGroup->addButton(ui->question1ANoCB);
    QButtonGroup *question1BGroup = new QButtonGroup(this);
    question1BGroup->addButton(ui->question1BYesCB);
    question1BGroup->addButton(ui->question1BNoCB);
    QButtonGroup *question2AGroup = new QButtonGroup(this);
    question2AGroup->addButton(ui->question2AYesCB);
    question2AGroup->addButton(ui->question2ANoCB);
    QButtonGroup *question2BGroup = new QButtonGroup(this);
    question2BGroup->addButton(ui->question2BYesCB);
    question2BGroup->addButton(ui->question2BNoCB);
    QButtonGroup *question3AGroup = new QButtonGroup(this);
    question3AGroup->addButton(ui->question3AYesCB);
    question3AGroup->addButton(ui->question3ANoCB);
    QButtonGroup *question4AGroup = new QButtonGroup(this);
    question4AGroup->addButton(ui->question4AYesCB);
    question4AGroup->addButton(ui->question4ANoCB);
    QButtonGroup *question5AGroup = new QButtonGroup(this);
    question5AGroup->addButton(ui->question5AYesCB);
    question5AGroup->addButton(ui->question5ANoCB);
    QButtonGroup *question6AGroup = new QButtonGroup(this);
    question6AGroup->addButton(ui->question6AYesCB);
    question6AGroup->addButton(ui->question6ANoCB);
    QButtonGroup *question6BGroup = new QButtonGroup(this);
    question6BGroup->addButton(ui->question6BYesCB);
    question6BGroup->addButton(ui->question6BNoCB);
    QButtonGroup *question6CGroup = new QButtonGroup(this);
    question6CGroup->addButton(ui->question6CYesCB);
    question6CGroup->addButton(ui->question6CNoCB);

    connect(ui->otherCStatusCB, SIGNAL(stateChanged(int)), this, SLOT(on_otherCivilStatusClicked(int)));
    connect(ui->question1AYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question1AYesCBClicked(int)));
    connect(ui->question1BYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question1BYesCBClicked(int)));
    connect(ui->question2AYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question2AYesCBClicked(int)));
    connect(ui->question2BYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question2BYesCBClicked(int)));
    connect(ui->question3AYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question3AYesCBClicked(int)));
    connect(ui->question4AYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question4AYesCBClicked(int)));
    connect(ui->question5AYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question5AYesCBClicked(int)));
    connect(ui->question6AYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question6AYesCBClicked(int)));
    connect(ui->question6BYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question6BYesCBClicked(int)));
    connect(ui->question6CYesCB, SIGNAL(stateChanged(int)), this, SLOT(on_question6CYesCBClicked(int)));



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

    ui->errorLayout->addRow(messageLabel);
    messageLabel->setText("");
}

NewEmployee::~NewEmployee()
{
    delete ui;
}


void NewEmployee::on_addSpouse_clicked()
{
    addSpouse("", "", "", "", "", "", "");
}

void NewEmployee::addSpouse(QString firstNameV, QString lastNameV, QString middleNameV, QString occupationV, QString employerNameV,
                            QString busAddrV, QString telNoV){
    totalSpouses++;

    QLabel *spouseLabel = new QLabel(this);
    const QFont f("Segoe UI", 15);
    spouseLabel->setFont(f);
    spouseLabel->setText("<u>Spouse " + QString::number(totalSpouses) + "</u>");
    spouseLabel->setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    spouseLabel->setSizePolicy(sizePolicy);
    spouseLabel->setSizeIncrement(0, 0);
    spouseLabel->setBaseSize(0, 0);

    const QFont f1("Segoe UI", 11);

    QLabel *firstNameLabel = new QLabel(this);
    firstNameLabel->setFont(f1);
    firstNameLabel->setText("First Name");
    firstNameLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *firstNameEdit = new QLineEdit(this);
    firstNameEdit->setFont(f1);
    firstNameEdit->setAlignment(Qt::AlignLeft);
    firstNameEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    firstNameEdit->setObjectName("spouseFirstName" + QString::number(totalSpouses));
    firstNameEdit->setText(firstNameV);

    QLabel *lastNameLabel = new QLabel(this);
    lastNameLabel->setFont(f1);
    lastNameLabel->setText("Last Name");
    lastNameLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *lastNameEdit = new QLineEdit(this);
    lastNameEdit->setFont(f1);
    lastNameEdit->setAlignment(Qt::AlignLeft);
    lastNameEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    lastNameEdit->setObjectName("spouseLastName" + QString::number(totalSpouses));
    lastNameEdit->setText(lastNameV);

    QLabel *middleNameLabel = new QLabel(this);
    middleNameLabel->setFont(f1);
    middleNameLabel->setText("Middle Name");
    middleNameLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *middleNameEdit = new QLineEdit(this);
    middleNameEdit->setFont(f1);
    middleNameEdit->setAlignment(Qt::AlignLeft);
    middleNameEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    middleNameEdit->setObjectName("spouseMiddleName" + QString::number(totalSpouses));
    middleNameEdit->setText(middleNameV);

    QLabel *occupationLabel = new QLabel(this);
    occupationLabel->setFont(f1);
    occupationLabel->setText("Occupation");
    occupationLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *occupationEdit = new QLineEdit(this);
    occupationEdit->setFont(f1);
    occupationEdit->setAlignment(Qt::AlignLeft);
    occupationEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    occupationEdit->setObjectName("spouseOccupation" + QString::number(totalSpouses));
    occupationEdit->setText(occupationV);

    QLabel *employerNameLabel = new QLabel(this);
    employerNameLabel->setFont(f1);
    employerNameLabel->setText("Employer/Bus Name");
    employerNameLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *employerNameEdit = new QLineEdit(this);
    employerNameEdit->setFont(f1);
    employerNameEdit->setAlignment(Qt::AlignLeft);
    employerNameEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    employerNameEdit->setObjectName("spouseEmployerName" + QString::number(totalSpouses));
    employerNameEdit->setText(employerNameV);

    QLabel *busAddrLabel = new QLabel(this);
    busAddrLabel->setFont(f1);
    busAddrLabel->setText("Business Address");
    busAddrLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *busAddrEdit = new QLineEdit(this);
    busAddrEdit->setFont(f1);
    busAddrEdit->setAlignment(Qt::AlignLeft);
    busAddrEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    busAddrEdit->setObjectName("spouseBusAddr" + QString::number(totalSpouses));
    busAddrEdit->setText(busAddrV);

    QLabel *telNoLabel = new QLabel(this);
    telNoLabel->setFont(f1);
    telNoLabel->setText("Telephone No.");
    telNoLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *telNoEdit = new QLineEdit(this);
    telNoEdit->setFont(f1);
    telNoEdit->setAlignment(Qt::AlignLeft);
    telNoEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    telNoEdit->setObjectName("spouseTelNo" + QString::number(totalSpouses));
    telNoEdit->setText(telNoV);


    ui->spouselayout->addRow(spouseLabel);
    ui->spouselayout->addRow(firstNameLabel, firstNameEdit);
    ui->spouselayout->addRow(lastNameLabel, lastNameEdit);
    ui->spouselayout->addRow(middleNameLabel, middleNameEdit);
    ui->spouselayout->addRow(occupationLabel, occupationEdit);
    ui->spouselayout->addRow(employerNameLabel, employerNameEdit);
    ui->spouselayout->addRow(busAddrLabel, busAddrEdit);
    ui->spouselayout->addRow(telNoLabel, telNoEdit);

    ui->anotherSpouseLabel->setText("Do you have another spouse?");
    ui->deleteSpouseB->setVisible(true);
}

void NewEmployee::on_deleteSpouseB_clicked()
{
    if (totalSpouses > 0){
        totalSpouses--;
        for (int i = 1; i <= 15; i++){
            QLayoutItem *item = ui->spouselayout->takeAt(ui->spouselayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalSpouses != 0) ui->anotherSpouseLabel->setText("Do you have another spouse?");
        else ui->anotherSpouseLabel->setText("Do you have a spouse?");
        if (totalSpouses == 0) ui->deleteSpouseB->setVisible(false);
    }
}

void NewEmployee::on_addChild_clicked()
{
    addChild("", QDate::currentDate().toString());
}

void NewEmployee::addChild(QString childNameV, QString bDayV){
    totalChildren++;

    QLabel *childLabel = new QLabel(this);
    const QFont f("Segoe UI", 15);
    childLabel->setFont(f);
    childLabel->setText("<u>Child " + QString::number(totalChildren) + "</u>");
    childLabel->setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    childLabel->setSizePolicy(sizePolicy);
    childLabel->setSizeIncrement(0, 0);
    childLabel->setBaseSize(0, 0);

    const QFont f1("Segoe UI", 11);

    QLabel *childNameLabel = new QLabel(this);
    childNameLabel->setFont(f1);
    childNameLabel->setText("Full Name");
    childNameLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *childNameEdit = new QLineEdit(this);
    childNameEdit->setFont(f1);
    childNameEdit->setAlignment(Qt::AlignLeft);
    childNameEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    childNameEdit->setObjectName("childName" + QString::number(totalChildren));
    childNameEdit->setText(childNameV);

    QLabel *birthdayLabel = new QLabel(this);
    birthdayLabel->setFont(f1);
    birthdayLabel->setText("Birthday");
    birthdayLabel->setAlignment(Qt::AlignLeft);
    QDateEdit *bDayEdit = new QDateEdit(this);
    bDayEdit->setFont(f1);
    bDayEdit->setAlignment(Qt::AlignCenter);
    bDayEdit->setStyleSheet("QDateEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    bDayEdit->setObjectName("bDayEdit" + QString::number(totalChildren));
    bDayEdit->setDate(QDate::fromString(bDayV));

    ui->childrenLayout->addRow(childLabel);
    ui->childrenLayout->addRow(childNameLabel, childNameEdit);
    ui->childrenLayout->addRow(birthdayLabel, bDayEdit);

    ui->anotherChild->setText("Do you have another child?");
    ui->deleteChild->setVisible(true);
}

void NewEmployee::on_deleteChild_clicked()
{
    if (totalChildren > 0){
        totalChildren--;
        for (int i = 1; i <= 5; i++){
            QLayoutItem *item = ui->childrenLayout->takeAt(ui->childrenLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalChildren != 0) ui->anotherChild->setText("Do you have another child?");
        else ui->anotherChild->setText("Do you have a child?");
        if (totalChildren == 0) ui->deleteChild->setVisible(false);
    }
}

void NewEmployee::on_addEduBg_clicked()
{
    addEducationBG("", "", "", "", "", "", "", "");
}

void NewEmployee::addEducationBG(QString levelV, QString schoolNameV, QString degreeV, QString yearGradV, QString unitsV,
                                 QString incDateFromV, QString incDateToV, QString scholarshipV){
    totalEduBg++;

    QLabel *eduLabel = new QLabel(this);
    const QFont f("Segoe UI", 15);
    eduLabel->setFont(f);
    eduLabel->setText("<u>Institution " + QString::number(totalEduBg) + "</u>");
    eduLabel->setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    eduLabel->setSizePolicy(sizePolicy);
    eduLabel->setSizeIncrement(0, 0);
    eduLabel->setBaseSize(0, 0);

    const QFont f1("Segoe UI", 11);

    QLabel *levelLabel = new QLabel(this);
    levelLabel->setFont(f1);
    levelLabel->setText("Level");
    levelLabel->setAlignment(Qt::AlignLeft);
    QComboBox *levelCBox = new QComboBox();
    levelCBox->addItems(QStringList() << "Elementary" << "Secondary" << "Vocation/Trade Course" << "College" << "Graduate Studies" << "Other");
    levelCBox->setFont(f1);
    levelCBox->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    levelCBox->setObjectName("levelCBox" + QString::number(totalEduBg));
    levelCBox->setCurrentText(levelV);

    QLabel *schoolNameLabel = new QLabel(this);
    schoolNameLabel->setFont(f1);
    schoolNameLabel->setText("Name of School (Full)");
    schoolNameLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *schoolNameEdit = new QLineEdit(this);
    schoolNameEdit->setFont(f1);
    schoolNameEdit->setAlignment(Qt::AlignLeft);
    schoolNameEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    schoolNameEdit->setObjectName("schoolNameEdit" + QString::number(totalEduBg));
    schoolNameEdit->setText(schoolNameV);

    QLabel *degreeLabel = new QLabel(this);
    degreeLabel->setFont(f1);
    degreeLabel->setText("Degree Course (Full)");
    degreeLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *degreeEdit = new QLineEdit(this);
    degreeEdit->setFont(f1);
    degreeEdit->setAlignment(Qt::AlignLeft);
    degreeEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    degreeEdit->setObjectName("degreeEdit" + QString::number(totalEduBg));
    degreeEdit->setText(degreeV);

    QLabel *yearGradLabel = new QLabel(this);
    yearGradLabel->setFont(f1);
    yearGradLabel->setText("Year Graduated (if graduated)");
    yearGradLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *yearGradEdit = new QLineEdit(this);
    yearGradEdit->setFont(f1);
    yearGradEdit->setAlignment(Qt::AlignLeft);
    yearGradEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    yearGradEdit->setObjectName("yearGradEdit" + QString::number(totalEduBg));
    yearGradEdit->setValidator( new QDoubleValidator(-9999999999999999999, 9999999999999999999, 100, this));
    yearGradEdit->setText(yearGradV);

    QLabel *unitsLabel = new QLabel(this);
    unitsLabel->setFont(f1);
    unitsLabel->setText("Highest Grade/Level/Units Earned (if not graduated)");
    unitsLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *unitsEdit = new QLineEdit(this);
    unitsEdit->setFont(f1);
    unitsEdit->setAlignment(Qt::AlignLeft);
    unitsEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    unitsEdit->setObjectName("unitsEdit" + QString::number(totalEduBg));
    unitsEdit->setText(unitsV);


    QLabel *incDateLabel = new QLabel(this);
    incDateLabel->setFont(f1);
    incDateLabel->setText("Inclusive Dates of Attendance");
    incDateLabel->setAlignment(Qt::AlignLeft);

    QLabel *incDateFromLabel = new QLabel(this);
    incDateFromLabel->setFont(f1);
    incDateFromLabel->setText("    from");
    incDateFromLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *incDateFromEdit = new QLineEdit(this);
    incDateFromEdit->setFont(f1);
    incDateFromEdit->setAlignment(Qt::AlignLeft);
    incDateFromEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateFromEdit->setObjectName("eduIncDateFromEdit" + QString::number(totalEduBg));
    incDateFromEdit->setValidator( new QDoubleValidator(-9999999999999999999, 9999999999999999999, 100, this));
    incDateFromEdit->setText(incDateFromV);

    QLabel *incDateToLabel = new QLabel(this);
    incDateToLabel->setFont(f1);
    incDateToLabel->setText("    to");
    incDateToLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *incDateToEdit = new QLineEdit(this);
    incDateToEdit->setFont(f1);
    incDateToEdit->setAlignment(Qt::AlignLeft);
    incDateToEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateToEdit->setObjectName("eduIncDateToEdit" + QString::number(totalEduBg));
    incDateToEdit->setValidator( new QDoubleValidator(-9999999999999999999, 9999999999999999999, 100, this));
    incDateToEdit->setText(incDateToV);

//    QCheckBox *incDateToPresentCB = new QCheckBox(this);
//    incDateToPresentCB->setFont(f1);
//    incDateToPresentCB->setText("Present");
//    incDateToPresentCB->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
//                                             "border-radius: 5px;}");
//    incDateToPresentCB->setObjectName("eduIncDateToPresentCB" + QString::number(totalEduBg));
//    incDateToPresentCB->setChecked(!toDate.isValid());
//    QSignalMapper *mapper = new QSignalMapper(this);
//    connect(incDateToPresentCB, SIGNAL(released()), mapper, SLOT(map()));
//    PresentDateData *dateData = new PresentDateData(incDateToEdit, incDateToPresentCB);
//    mapper->setMapping(incDateToPresentCB, dateData);
//    connect(mapper, SIGNAL(mapped(QObject*)), this, SLOT(enableQDateObject(QObject*)));

    QGridLayout *incDateGrid = new QGridLayout();
    incDateGrid->addWidget(incDateFromLabel, 0, 0);
    incDateGrid->addWidget(incDateFromEdit, 0, 1);
    incDateGrid->addWidget(incDateToLabel, 0, 2);
    incDateGrid->addWidget(incDateToEdit, 0, 3);

    QLabel *scholarshipLabel = new QLabel(this);
    scholarshipLabel->setFont(f1);
    scholarshipLabel->setText("Scholarship/Academic Honors Received");
    scholarshipLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *scholarshipEdit = new QLineEdit(this);
    scholarshipEdit->setFont(f1);
    scholarshipEdit->setAlignment(Qt::AlignLeft);
    scholarshipEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    scholarshipEdit->setObjectName("scholarshipEdit" + QString::number(totalEduBg));
    scholarshipEdit->setText(scholarshipV);


    ui->eduBgLayout->addRow(eduLabel);
    ui->eduBgLayout->addRow(levelLabel, levelCBox);
    ui->eduBgLayout->addRow(schoolNameLabel, schoolNameEdit);
    ui->eduBgLayout->addRow(degreeLabel, degreeEdit);
    ui->eduBgLayout->addRow(yearGradLabel, yearGradEdit);
    ui->eduBgLayout->addRow(unitsLabel, unitsEdit);
    ui->eduBgLayout->addRow(incDateLabel, incDateGrid);
    ui->eduBgLayout->addRow(scholarshipLabel, scholarshipEdit);


    ui->newEduBgLabel->setText("Add another educational background?");
    ui->deleteEduBg->setVisible(true);
}

void NewEmployee::on_deleteEduBg_clicked()
{
    if (totalEduBg > 0){
        totalEduBg--;
        for (int i = 1; i <= 15; i++){
            QLayoutItem *item = ui->eduBgLayout->takeAt(ui->eduBgLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalEduBg != 0) ui->newEduBgLabel->setText("Add another educational background?");
        else ui->newEduBgLabel->setText("Add a new educational background?");
        if (totalEduBg == 0) ui->deleteEduBg->setVisible(false);
    }
}

void NewEmployee::on_otherCivilStatusClicked(int state)
{
    if (state == Qt::Checked){
        ui->otherCStatusEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->otherCStatusEdit->setDisabled(true);
    }
}

void NewEmployee::on_addCivilServB_clicked()
{
    addCivilService("", "", "", "", "", QDate::currentDate().toString());
}

void NewEmployee::addCivilService(QString careerServiceV, QString ratingV, QString dateOfExamV, QString placeOfExamV,
                                  QString licenseNumberV, QString licenseDateV){
    totalCivilService++;

    QLabel *cServiceLabel = new QLabel(this);
    const QFont f("Segoe UI", 15);
    cServiceLabel->setFont(f);
    cServiceLabel->setText("<u>Service " + QString::number(totalCivilService) + "</u>");
    cServiceLabel->setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    cServiceLabel->setSizePolicy(sizePolicy);
    cServiceLabel->setSizeIncrement(0, 0);
    cServiceLabel->setBaseSize(0, 0);


    const QFont f1("Segoe UI", 11);

    QLabel *careerServiceLabel = new QLabel(this);
    careerServiceLabel->setFont(f1);
    careerServiceLabel->setText("Career Service/RA 1080 (Board/Bar) under Special Laws/CED/CSEE");
    careerServiceLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *careerServiceEdit = new QLineEdit(this);
    careerServiceEdit->setFont(f1);
    careerServiceEdit->setAlignment(Qt::AlignLeft);
    careerServiceEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    careerServiceEdit->setObjectName("careerServiceEdit" + QString::number(totalCivilService));
    careerServiceEdit->setText(careerServiceV);

    QLabel *ratingLabel = new QLabel(this);
    ratingLabel->setFont(f1);
    ratingLabel->setText("Rating");
    ratingLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *ratingEdit = new QLineEdit(this);
    ratingEdit->setFont(f1);
    ratingEdit->setAlignment(Qt::AlignRight);
    ratingEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    ratingEdit->setObjectName("ratingEdit" + QString::number(totalCivilService));
    ratingEdit->setValidator( new QDoubleValidator(-9999999999999999999, 9999999999999999999, 100, this));
    ratingEdit->setText(ratingV);
    QLabel *ratingPercLabel = new QLabel(this);
    ratingPercLabel->setFont(f1);
    ratingPercLabel->setText("%");
    ratingPercLabel->setAlignment(Qt::AlignRight);

    QLabel *dateOfExamLabel = new QLabel(this);
    dateOfExamLabel->setFont(f1);
    dateOfExamLabel->setText("    Date of Examination/Conferment");
    dateOfExamLabel->setAlignment(Qt::AlignRight);
    QDateEdit *dateOfExamEdit = new QDateEdit(this);
    dateOfExamEdit->setFont(f1);
    dateOfExamEdit->setAlignment(Qt::AlignCenter);
    dateOfExamEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    dateOfExamEdit->setObjectName("dateOfExamEdit" + QString::number(totalCivilService));
    dateOfExamEdit->setDate(QDate::fromString(dateOfExamV));

    QGridLayout *civiServRatingLayout = new QGridLayout(this);
    civiServRatingLayout->addWidget(ratingLabel, 0, 0);
    civiServRatingLayout->addWidget(ratingEdit, 0, 1);
    civiServRatingLayout->addWidget(ratingPercLabel, 0, 2);
    civiServRatingLayout->addWidget(dateOfExamLabel, 0, 3);
    civiServRatingLayout->addWidget(dateOfExamEdit, 0, 4);

    QLabel *placeOfExamLabel = new QLabel(this);
    placeOfExamLabel->setFont(f1);
    placeOfExamLabel->setText("Place of Examination/Conferment");
    placeOfExamLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *placeOfExamEdit = new QLineEdit(this);
    placeOfExamEdit->setFont(f1);
    placeOfExamEdit->setAlignment(Qt::AlignLeft);
    placeOfExamEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    placeOfExamEdit->setObjectName("placeOfExamEdit" + QString::number(totalCivilService));
    placeOfExamEdit->setText(placeOfExamV);

    QLabel *licenseLabel = new QLabel(this);
    licenseLabel->setFont(f1);
    licenseLabel->setText("License (if applicable)");
    licenseLabel->setAlignment(Qt::AlignLeft);
    QLabel *licenseNumberLabel = new QLabel(this);
    licenseNumberLabel->setFont(f1);
    licenseNumberLabel->setText("    Number");
    licenseNumberLabel->setAlignment(Qt::AlignRight);
    QLineEdit *licenseNumberEdit = new QLineEdit(this);
    licenseNumberEdit->setFont(f1);
    licenseNumberEdit->setAlignment(Qt::AlignLeft);
    licenseNumberEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    licenseNumberEdit->setObjectName("licenseNumberEdit" + QString::number(totalCivilService));
    licenseNumberEdit->setText(licenseNumberV);
    QLabel *licenseDateLabel = new QLabel(this);
    licenseDateLabel->setFont(f1);
    licenseDateLabel->setText("    Date of Release");
    licenseDateLabel->setAlignment(Qt::AlignRight);
    QDateEdit *licenseDateEdit = new QDateEdit(this);
    licenseDateEdit->setFont(f1);
    licenseDateEdit->setAlignment(Qt::AlignCenter);
    licenseDateEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    licenseDateEdit->setObjectName("licenseDateEdit" + QString::number(totalCivilService));
    licenseDateEdit->setDate(QDate::fromString(licenseDateV));
    QGridLayout *licenseGLayout = new QGridLayout(this);
    licenseGLayout->addWidget(licenseLabel, 0, 0);
    licenseGLayout->addWidget(licenseNumberLabel, 0, 1);
    licenseGLayout->addWidget(licenseNumberEdit, 0, 2);
    licenseGLayout->addWidget(licenseDateLabel, 0, 3);
    licenseGLayout->addWidget(licenseDateEdit, 0, 4);

    licenseDateEdit->hide();
    licenseDateLabel->hide();

    ui->civilServLayout->addRow(cServiceLabel);
    ui->civilServLayout->addRow(careerServiceLabel, careerServiceEdit);
    ui->civilServLayout->addRow(civiServRatingLayout);
    ui->civilServLayout->addRow(placeOfExamLabel, placeOfExamEdit);
    ui->civilServLayout->addRow(licenseGLayout);

    ui->otherCivilServLabel->setText("Add another civil service?");
    ui->deleteCivilServ->setVisible(true);
}

void NewEmployee::on_deleteCivilServ_clicked()
{
    if (totalCivilService > 0){
        totalCivilService--;
        for (int i = 1; i <= 7; i++){
            QLayoutItem *item = ui->civilServLayout->takeAt(ui->civilServLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalCivilService != 0) ui->otherCivilServLabel->setText("Add another civil service?");
        else ui->otherCivilServLabel->setText("Add a new civil service?");
        if (totalCivilService == 0) ui->deleteCivilServ->setVisible(false);
    }
}

void NewEmployee::on_addServiceRecordB_clicked()
{
    addServiceRecord(QDate::currentDate().toString(), QDate::currentDate().toString(), "", "", "", "", "", "",
                     QDate::currentDate().toString(), "");
}

void NewEmployee::addServiceRecord(QString incDateFromV, QString incDateToV, QString designationV, QString statusV, QString salaryV,
                                   QString stationV, QString branchV, QString lwPayV, QString separationDateFromV, QString separationCauseV){
    totalServiceRecord++;

    QLabel *serviceRecordLabel = new QLabel(this);
    const QFont f("Segoe UI", 15);
    serviceRecordLabel->setFont(f);
    serviceRecordLabel->setText("<u>Record " + QString::number(totalServiceRecord) + "</u>");
    serviceRecordLabel->setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    serviceRecordLabel->setSizePolicy(sizePolicy);
    serviceRecordLabel->setSizeIncrement(0, 0);
    serviceRecordLabel->setBaseSize(0, 0);


    const QFont f1("Segoe UI", 11);

    QLabel *incDateLabel = new QLabel(this);
    incDateLabel->setFont(f1);
    incDateLabel->setText("Inclusive Dates of Attendance");
    incDateLabel->setAlignment(Qt::AlignLeft);
    QLabel *incDateFromLabel = new QLabel(this);
    incDateFromLabel->setFont(f1);
    incDateFromLabel->setText("    from");
    incDateFromLabel->setAlignment(Qt::AlignRight);
    QDateEdit *incDateFromEdit = new QDateEdit(this);
    incDateFromEdit->setFont(f1);
    incDateFromEdit->setAlignment(Qt::AlignCenter);
    incDateFromEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateFromEdit->setObjectName("servRecIncDateFrom" + QString::number(totalServiceRecord));
    incDateFromEdit->setDate(QDate::fromString(incDateFromV));
    QLabel *incDateToLabel = new QLabel(this);
    incDateToLabel->setFont(f1);
    incDateToLabel->setText("    to");
    incDateToLabel->setAlignment(Qt::AlignRight);
    QDate toDate = QDate::fromString(incDateToV);
    QDateEdit *incDateToEdit = new QDateEdit(this);
    incDateToEdit->setFont(f1);
    incDateToEdit->setAlignment(Qt::AlignCenter);
    incDateToEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateToEdit->setObjectName("servRecIncDateTo" + QString::number(totalServiceRecord));
    incDateToEdit->setDate(toDate.isValid() ? toDate : QDate::currentDate());
    if (!toDate.isValid()) incDateToEdit->setDisabled(true);

    QCheckBox *incDateToPresentCB = new QCheckBox(this);
    incDateToPresentCB->setFont(f1);
    incDateToPresentCB->setText("Present");
    incDateToPresentCB->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateToPresentCB->setObjectName("servRecIncDateToPresentCB" + QString::number(totalServiceRecord));
    incDateToPresentCB->setChecked(!toDate.isValid());
    QSignalMapper *mapper = new QSignalMapper(this);
    connect(incDateToPresentCB, SIGNAL(released()), mapper, SLOT(map()));
    PresentDateData *dateData = new PresentDateData(incDateToEdit, incDateToPresentCB);
    mapper->setMapping(incDateToPresentCB, dateData);
    connect(mapper, SIGNAL(mapped(QObject*)), this, SLOT(enableQDateObject(QObject*)));

    QGridLayout *incDateGrid = new QGridLayout();
    incDateGrid->addWidget(incDateLabel, 0, 0);
    incDateGrid->addWidget(incDateFromLabel, 0, 1);
    incDateGrid->addWidget(incDateFromEdit, 0, 2);
    incDateGrid->addWidget(incDateToLabel, 0, 3);
    incDateGrid->addWidget(incDateToEdit, 0, 4);
    incDateGrid->addWidget(incDateToPresentCB, 0, 5);

    QLabel *designationLabel = new QLabel(this);
    designationLabel->setFont(f1);
    designationLabel->setText("Designation");
    designationLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *designationEdit = new QLineEdit(this);
    designationEdit->setFont(f1);
    designationEdit->setAlignment(Qt::AlignLeft);
    designationEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    designationEdit->setObjectName("designationEdit" + QString::number(totalServiceRecord));
    designationEdit->setText(designationV);

    QLabel *statusLabel = new QLabel(this);
    statusLabel->setFont(f1);
    statusLabel->setText("Status");
    statusLabel->setAlignment(Qt::AlignLeft);
    QComboBox *statusCBox = new QComboBox();
    statusCBox->addItems(QStringList() << "Permanent" << "Temporary" << "Coterminous" << "Elective" << "Casual" << "None");
    statusCBox->setFont(f1);
    statusCBox->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    statusCBox->setObjectName("statusCBox" + QString::number(totalServiceRecord));
    statusCBox->setCurrentText(statusV);
    QLabel *salaryLabel = new QLabel(this);
    salaryLabel->setFont(f1);
    salaryLabel->setText("    Salary/Annum (₱)");
    salaryLabel->setAlignment(Qt::AlignRight);
    QLineEdit *salaryEdit = new QLineEdit(this);
    salaryEdit->setFont(f1);
    salaryEdit->setAlignment(Qt::AlignLeft);
    salaryEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    salaryEdit->setObjectName("salaryEdit" + QString::number(totalServiceRecord));
    salaryEdit->setValidator( new QDoubleValidator(0, 9999999999999999999, 100, this));
    salaryEdit->setText(salaryV);

    QGridLayout *statusSalaryGrid = new QGridLayout();
    statusSalaryGrid->addWidget(statusLabel, 0, 0);
    statusSalaryGrid->addWidget(statusCBox, 0, 1);
    statusSalaryGrid->addWidget(salaryLabel, 0, 2);
    statusSalaryGrid->addWidget(salaryEdit, 0, 3);

    QLabel *stationLabel = new QLabel(this);
    stationLabel->setFont(f1);
    stationLabel->setText("Station/Place of Assignment");
    stationLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *stationEdit = new QLineEdit(this);
    stationEdit->setFont(f1);
    stationEdit->setAlignment(Qt::AlignLeft);
    stationEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    stationEdit->setObjectName("stationEdit" + QString::number(totalServiceRecord));
    stationEdit->setText(stationV);
    QLabel *branchLabel = new QLabel(this);
    branchLabel->setFont(f1);
    branchLabel->setText("    Branch");
    branchLabel->setAlignment(Qt::AlignRight);
    QLineEdit *branchEdit = new QLineEdit(this);
    branchEdit->setFont(f1);
    branchEdit->setAlignment(Qt::AlignLeft);
    branchEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    branchEdit->setObjectName("branchEdit" + QString::number(totalServiceRecord));
    branchEdit->setText(branchV);
    QGridLayout *stationBranchGrid = new QGridLayout();
    stationBranchGrid->addWidget(stationLabel, 0, 0);
    stationBranchGrid->addWidget(stationEdit, 0, 1);
    stationBranchGrid->addWidget(branchLabel, 0, 2);
    stationBranchGrid->addWidget(branchEdit, 0, 3);

    QLabel *lwPayLabel = new QLabel(this);
    lwPayLabel->setFont(f1);
    lwPayLabel->setText("L/W Pay or L/O Pay");
    lwPayLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *lwPayEdit = new QLineEdit(this);
    lwPayEdit->setFont(f1);
    lwPayEdit->setAlignment(Qt::AlignLeft);
    lwPayEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    lwPayEdit->setObjectName("lwPayEdit" + QString::number(totalServiceRecord));
    lwPayEdit->setText(lwPayV);


    QLabel *separationDateLabel = new QLabel(this);
    separationDateLabel->setFont(f1);
    separationDateLabel->setText("Separation date");
    separationDateLabel->setAlignment(Qt::AlignLeft);
    QDateEdit *separationDateFromEdit = new QDateEdit(this);
    separationDateFromEdit->setFont(f1);
    separationDateFromEdit->setAlignment(Qt::AlignCenter);
    separationDateFromEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    separationDateFromEdit->setObjectName("separationDateFrom" + QString::number(totalServiceRecord));
    separationDateFromEdit->setDate(QDate::fromString(separationDateFromV));
    QLabel *separationDateCauseLabel = new QLabel(this);
    separationDateCauseLabel->setFont(f1);
    separationDateCauseLabel->setText("Cause");
    separationDateCauseLabel->setAlignment(Qt::AlignRight);
    QLineEdit *separationDateCauseEdit = new QLineEdit(this);
    separationDateCauseEdit->setFont(f1);
    separationDateCauseEdit->setAlignment(Qt::AlignLeft);
    separationDateCauseEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    separationDateCauseEdit->setObjectName("separationDateCause" + QString::number(totalServiceRecord));
    separationDateCauseEdit->setText(separationCauseV);

    QGridLayout *separationDateGLayout = new QGridLayout();
    separationDateGLayout->addWidget(separationDateLabel, 0, 0);
    separationDateGLayout->addWidget(separationDateFromEdit, 0, 1);
    separationDateGLayout->addWidget(separationDateCauseLabel, 0, 2);
    separationDateGLayout->addWidget(separationDateCauseEdit, 0, 3);

    ui->serviceRecordLayout->addRow(serviceRecordLabel);
    ui->serviceRecordLayout->addRow(incDateGrid);
    ui->serviceRecordLayout->addRow(designationLabel, designationEdit);
    ui->serviceRecordLayout->addRow(statusSalaryGrid);
    ui->serviceRecordLayout->addRow(stationBranchGrid);
    ui->serviceRecordLayout->addRow(lwPayLabel, lwPayEdit);
    ui->serviceRecordLayout->addRow(separationDateGLayout);

    ui->otherServiceRecordLabel->setText("Add another service record?");
    ui->deleteServiceRecord->setVisible(true);
}

void NewEmployee::on_deleteServiceRecord_clicked()
{
    if (totalServiceRecord > 0){
        ui->servRecBox->findChild<QCheckBox*>("servRecIncDateToPresentCB" + QString::number(totalServiceRecord))->disconnect();
        totalServiceRecord--;
        for (int i = 1; i <= 9; i++){
            QLayoutItem *item = ui->serviceRecordLayout->takeAt(ui->serviceRecordLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalServiceRecord != 0) ui->otherServiceRecordLabel->setText("Add another service record?");
        else ui->otherServiceRecordLabel->setText("Add a new service record?");
        if (totalServiceRecord == 0) ui->deleteServiceRecord->setVisible(false);
    }
}

void NewEmployee::removeItem(QLayout *layout)
{
        QLayoutItem* child;
        while ( layout->count() != 0 ) {
            child = layout->takeAt ( 0 );
            if ( child->layout() != 0 ) {
                removeItem ( child->layout() );
            } else if ( child->widget() != 0 ) {
                delete child->widget();
            }

            delete child->widget();
        }
}
//0 - new, 1 - view, 2 - update
void NewEmployee::setMode(int value)
{
    mode = value;
    switch (value){
    case 0: {
        ui->registerB->setText("Register");
        ui->registerB->setVisible(true);
    }; break;
    case 1: {
        ui->registerB->setVisible(false);
    }; break;
    case 2: {
        ui->registerB->setText("Update");
        ui->registerB->setVisible(true);
    }; break;
    default: break;
    }
}

void NewEmployee::on_addVWorkB_clicked()
{
    addVoluntaryWork("", QDate::currentDate().toString(), QDate::currentDate().toString(), "", "");
}

void NewEmployee::addVoluntaryWork(QString nameAndAddrV, QString incDateFromV, QString incDateToV, QString numOfHoursV, QString posOfWorkV){
    totalVoluntaryWork++;

    QLabel *eduLabel = new QLabel(this);
    const QFont f("Segoe UI", 15);
    eduLabel->setFont(f);
    eduLabel->setText("<u>Voluntary " + QString::number(totalVoluntaryWork) + "</u>");
    eduLabel->setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    eduLabel->setSizePolicy(sizePolicy);
    eduLabel->setSizeIncrement(0, 0);
    eduLabel->setBaseSize(0, 0);

    const QFont f1("Segoe UI", 11);

    QLabel *nameAndAddrLabel = new QLabel(this);
    nameAndAddrLabel->setFont(f1);
    nameAndAddrLabel->setText("Name & Address of Organization (Full)");
    nameAndAddrLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *nameAndAddrEdit = new QLineEdit(this);
    nameAndAddrEdit->setFont(f1);
    nameAndAddrEdit->setAlignment(Qt::AlignLeft);
    nameAndAddrEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    nameAndAddrEdit->setObjectName("nameAndAddrEdit" + QString::number(totalVoluntaryWork));
    nameAndAddrEdit->setText(nameAndAddrV);

    QLabel *incDateLabel = new QLabel(this);
    incDateLabel->setFont(f1);
    incDateLabel->setText("Inclusive Dates of Attendance");
    incDateLabel->setAlignment(Qt::AlignLeft);
    QLabel *incDateFromLabel = new QLabel(this);
    incDateFromLabel->setFont(f1);
    incDateFromLabel->setText("    from");
    incDateFromLabel->setAlignment(Qt::AlignRight);
    QDateEdit *incDateFromEdit = new QDateEdit(this);
    incDateFromEdit->setFont(f1);
    incDateFromEdit->setAlignment(Qt::AlignCenter);
    incDateFromEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateFromEdit->setObjectName("volWorkIncDateFromEdit" + QString::number(totalVoluntaryWork));
    incDateFromEdit->setDate(QDate::fromString(incDateFromV));
    QLabel *incDateToLabel = new QLabel(this);
    incDateToLabel->setFont(f1);
    incDateToLabel->setText("    to");
    incDateToLabel->setAlignment(Qt::AlignRight);
    QDate toDate = QDate::fromString(incDateToV);
    QDateEdit *incDateToEdit = new QDateEdit(this);
    incDateToEdit->setFont(f1);
    incDateToEdit->setAlignment(Qt::AlignCenter);
    incDateToEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateToEdit->setObjectName("volWorkIncDateToEdit" + QString::number(totalVoluntaryWork));
    incDateToEdit->setDate(toDate.isValid() ? toDate : QDate::currentDate());
    if (!toDate.isValid()) incDateToEdit->setDisabled(true);

    QCheckBox *incDateToPresentCB = new QCheckBox(this);
    incDateToPresentCB->setFont(f1);
    incDateToPresentCB->setText("Present");
    incDateToPresentCB->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateToPresentCB->setObjectName("volWorkIncDateToPresentCB" + QString::number(totalVoluntaryWork));
    incDateToPresentCB->setChecked(!toDate.isValid());
    QSignalMapper *mapper = new QSignalMapper(this);
    connect(incDateToPresentCB, SIGNAL(released()), mapper, SLOT(map()));
    PresentDateData *dateData = new PresentDateData(incDateToEdit, incDateToPresentCB);
    mapper->setMapping(incDateToPresentCB, dateData);
    connect(mapper, SIGNAL(mapped(QObject*)), this, SLOT(enableQDateObject(QObject*)));

    QGridLayout *incDateGrid = new QGridLayout();
    incDateGrid->addWidget(incDateLabel, 0, 0);
    incDateGrid->addWidget(incDateFromLabel, 0, 1);
    incDateGrid->addWidget(incDateFromEdit, 0, 2);
    incDateGrid->addWidget(incDateToLabel, 0, 3);
    incDateGrid->addWidget(incDateToEdit, 0, 4);
    incDateGrid->addWidget(incDateToPresentCB, 0, 5);

    QLabel *numOfHoursLabel = new QLabel(this);
    numOfHoursLabel->setFont(f1);
    numOfHoursLabel->setText("Number of Hours");
    numOfHoursLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *numOfHoursEdit = new QLineEdit(this);
    numOfHoursEdit->setFont(f1);
    numOfHoursEdit->setAlignment(Qt::AlignLeft);
    numOfHoursEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    numOfHoursEdit->setObjectName("numOfHoursEdit" + QString::number(totalVoluntaryWork));
    numOfHoursEdit->setValidator( new QDoubleValidator(0, 9999999999999999999, 100, this));
    numOfHoursEdit->setText(numOfHoursV);
    QLabel *posOfWorkLabel = new QLabel(this);
    posOfWorkLabel->setFont(f1);
    posOfWorkLabel->setText("    Position/Nature of Work");
    posOfWorkLabel->setAlignment(Qt::AlignRight);
    QLineEdit *posOfWorkEdit = new QLineEdit(this);
    posOfWorkEdit->setFont(f1);
    posOfWorkEdit->setAlignment(Qt::AlignLeft);
    posOfWorkEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    posOfWorkEdit->setObjectName("posOfWorkEdit" + QString::number(totalVoluntaryWork));
    posOfWorkEdit->setText(posOfWorkV);

    QGridLayout *numWorkGrid = new QGridLayout();
    numWorkGrid->addWidget(numOfHoursLabel, 0, 0);
    numWorkGrid->addWidget(numOfHoursEdit, 0, 1);
    numWorkGrid->addWidget(posOfWorkLabel, 0, 2);
    numWorkGrid->addWidget(posOfWorkEdit, 0, 3);


    ui->voluntaryWorkLayout->addRow(eduLabel);
    ui->voluntaryWorkLayout->addRow(nameAndAddrLabel, nameAndAddrEdit);
    ui->voluntaryWorkLayout->addRow(incDateGrid);
    ui->voluntaryWorkLayout->addRow(numWorkGrid);

    ui->anotherVWorkLabel->setText("Add another voluntary work?");
    ui->deleteVWorkB->setVisible(true);
}

void NewEmployee::on_deleteVWorkB_clicked()
{
    if (totalVoluntaryWork > 0){
        ui->volWorkBox->findChild<QCheckBox*>("volWorkIncDateToPresentCB" + QString::number(totalVoluntaryWork))->disconnect();
        totalVoluntaryWork--;
        for (int i = 1; i <= 5; i++){
            QLayoutItem *item = ui->voluntaryWorkLayout->takeAt(ui->voluntaryWorkLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalVoluntaryWork != 0) ui->anotherVWorkLabel->setText("Add another voluntary work?");
        else ui->anotherVWorkLabel->setText("Add a new voluntary work?");
        if (totalVoluntaryWork == 0) ui->deleteVWorkB->setVisible(false);
    }
}

void NewEmployee::on_addTrainingProgramB_clicked()
{
    addTrainingProgram("", QDate::currentDate().toString(), QDate::currentDate().toString(), "", "");
}

void NewEmployee::addTrainingProgram(QString seminarNameV, QString incDateFromV, QString incDateToV, QString numOfHoursV, QString conductedV){
    totalTrainingProg++;

    QLabel *trainingProgLabel = new QLabel(this);
    const QFont f("Segoe UI", 15);
    trainingProgLabel->setFont(f);
    trainingProgLabel->setText("<u>Program " + QString::number(totalTrainingProg) + "</u>");
    trainingProgLabel->setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    trainingProgLabel->setSizePolicy(sizePolicy);
    trainingProgLabel->setSizeIncrement(0, 0);
    trainingProgLabel->setBaseSize(0, 0);

    const QFont f1("Segoe UI", 11);

    QLabel *seminarNameLabel = new QLabel(this);
    seminarNameLabel->setFont(f1);
    seminarNameLabel->setText("Title of Seminar/Conference/Workshop/Short Courses (Full)");
    seminarNameLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *seminarNameEdit = new QLineEdit(this);
    seminarNameEdit->setFont(f1);
    seminarNameEdit->setAlignment(Qt::AlignLeft);
    seminarNameEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    seminarNameEdit->setObjectName("seminarNameEdit" + QString::number(totalTrainingProg));
    seminarNameEdit->setText(seminarNameV);

    QLabel *incDateLabel = new QLabel(this);
    incDateLabel->setFont(f1);
    incDateLabel->setText("Inclusive Dates of Attendance");
    incDateLabel->setAlignment(Qt::AlignLeft);
    QLabel *incDateFromLabel = new QLabel(this);
    incDateFromLabel->setFont(f1);
    incDateFromLabel->setText("    from");
    incDateFromLabel->setAlignment(Qt::AlignRight);
    QDateEdit *incDateFromEdit = new QDateEdit(this);
    incDateFromEdit->setFont(f1);
    incDateFromEdit->setAlignment(Qt::AlignCenter);
    incDateFromEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateFromEdit->setObjectName("trainProgIncDateFromEdit" + QString::number(totalTrainingProg));
    incDateFromEdit->setDate(QDate::fromString(incDateFromV));
    QLabel *incDateToLabel = new QLabel(this);
    incDateToLabel->setFont(f1);
    incDateToLabel->setText("    to");
    incDateToLabel->setAlignment(Qt::AlignRight);
    QDate toDate = QDate::fromString(incDateToV);
    QDateEdit *incDateToEdit = new QDateEdit(this);
    incDateToEdit->setFont(f1);
    incDateToEdit->setAlignment(Qt::AlignCenter);
    incDateToEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateToEdit->setObjectName("trainProgIncDateToEdit" + QString::number(totalTrainingProg));
    incDateToEdit->setDate(toDate.isValid() ? toDate : QDate::currentDate());
    if (!toDate.isValid()) incDateToEdit->setDisabled(true);

    QCheckBox *incDateToPresentCB = new QCheckBox(this);
    incDateToPresentCB->setFont(f1);
    incDateToPresentCB->setText("Present");
    incDateToPresentCB->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    incDateToPresentCB->setObjectName("trainProgIncDateToPresentCB" + QString::number(totalTrainingProg));
    incDateToPresentCB->setChecked(!toDate.isValid());
    QSignalMapper *mapper = new QSignalMapper(this);
    connect(incDateToPresentCB, SIGNAL(released()), mapper, SLOT(map()));
    PresentDateData *dateData = new PresentDateData(incDateToEdit, incDateToPresentCB);
    mapper->setMapping(incDateToPresentCB, dateData);
    connect(mapper, SIGNAL(mapped(QObject*)), this, SLOT(enableQDateObject(QObject*)));

    QGridLayout *incDateGrid = new QGridLayout();
    incDateGrid->addWidget(incDateLabel, 0, 0);
    incDateGrid->addWidget(incDateFromLabel, 0, 1);
    incDateGrid->addWidget(incDateFromEdit, 0, 2);
    incDateGrid->addWidget(incDateToLabel, 0, 3);
    incDateGrid->addWidget(incDateToEdit, 0, 4);
    incDateGrid->addWidget(incDateToPresentCB, 0, 5);

    QLabel *numOfHoursLabel = new QLabel(this);
    numOfHoursLabel->setFont(f1);
    numOfHoursLabel->setText("Number of Hours");
    numOfHoursLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *numOfHoursEdit = new QLineEdit(this);
    numOfHoursEdit->setFont(f1);
    numOfHoursEdit->setAlignment(Qt::AlignLeft);
    numOfHoursEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    numOfHoursEdit->setObjectName("numOfHoursProgEdit" + QString::number(totalTrainingProg));
    numOfHoursEdit->setValidator( new QDoubleValidator(0, 9999999999999999999, 100, this));
    numOfHoursEdit->setText(numOfHoursV);
    QLabel *conductedLabel = new QLabel(this);
    conductedLabel->setFont(f1);
    conductedLabel->setText("    Conducted/Sponsored By (Full)");
    conductedLabel->setAlignment(Qt::AlignRight);
    QLineEdit *conductedEdit = new QLineEdit(this);
    conductedEdit->setFont(f1);
    conductedEdit->setAlignment(Qt::AlignLeft);
    conductedEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    conductedEdit->setObjectName("conductedEdit" + QString::number(totalTrainingProg));
    conductedEdit->setText(conductedV);
    QGridLayout *stationBranchGrid = new QGridLayout();
    stationBranchGrid->addWidget(numOfHoursLabel, 0, 0);
    stationBranchGrid->addWidget(numOfHoursEdit, 0, 1);
    stationBranchGrid->addWidget(conductedLabel, 0, 2);
    stationBranchGrid->addWidget(conductedEdit, 0, 3);

    ui->trainingProgramLayout->addRow(trainingProgLabel);
    ui->trainingProgramLayout->addRow(seminarNameLabel, seminarNameEdit);
    ui->trainingProgramLayout->addRow(incDateGrid);
    ui->trainingProgramLayout->addRow(stationBranchGrid);

    ui->newTrainingProgramLabel->setText("Add another training program?");
    ui->deleteTrainingProgramB->setVisible(true);
}

void NewEmployee::on_deleteTrainingProgramB_clicked()
{
    if (totalTrainingProg > 0){
        ui->trainProgBox->findChild<QCheckBox*>("trainProgIncDateToPresentCB" + QString::number(totalTrainingProg))->disconnect();
        totalTrainingProg--;
        for (int i = 1; i <= 5; i++){
            QLayoutItem *item = ui->trainingProgramLayout->takeAt(ui->trainingProgramLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalTrainingProg != 0) ui->newTrainingProgramLabel->setText("Add another training program?");
        else ui->newTrainingProgramLabel->setText("Add a new training program?");
        if (totalTrainingProg == 0) ui->deleteTrainingProgramB->setVisible(false);
    }
}

void NewEmployee::on_addNewSkillHobbyB_clicked()
{
    addNewSkillHobby("");
}

void NewEmployee::addNewSkillHobby(QString skillHobbyV){
    totalSkills++;

    const QFont f1("Segoe UI", 11);

    QLabel *skillHobbyLabel = new QLabel(this);
    skillHobbyLabel->setFont(f1);
    skillHobbyLabel->setText("Special Skills/Hobbies");
    skillHobbyLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *skillHobbyEdit = new QLineEdit(this);
    skillHobbyEdit->setFont(f1);
    skillHobbyEdit->setAlignment(Qt::AlignLeft);
    skillHobbyEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    skillHobbyEdit->setObjectName("skillHobbyEdit" + QString::number(totalSkills));
    skillHobbyEdit->setText(skillHobbyV);

    ui->specialSkillLayout->addRow(skillHobbyLabel, skillHobbyEdit);

    ui->newSkillHobbyLabel->setText("Add another skill/hobby?");
    ui->deleteSkillHobbyB->setVisible(true);
}

void NewEmployee::on_deleteSkillHobbyB_clicked()
{
    if (totalSkills > 0){
        totalSkills--;
        for (int i = 1; i <= 2; i++){
            QLayoutItem *item = ui->specialSkillLayout->takeAt(ui->specialSkillLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalSkills != 0) ui->newSkillHobbyLabel->setText("Add another skill/hobby?");
        else ui->newSkillHobbyLabel->setText("Add a new skill/hobby?");
        if (totalSkills == 0) ui->deleteSkillHobbyB->setVisible(false);
    }
}

void NewEmployee::on_addNonAcademicRecB_clicked()
{
    addNonAcademicRecognition("");
}

void NewEmployee::addNonAcademicRecognition(QString nonARec){
    totalNonAcademicRec++;

    const QFont f1("Segoe UI", 11);

    QLabel *nonAcademicOrgLabel = new QLabel(this);
    nonAcademicOrgLabel->setFont(f1);
    nonAcademicOrgLabel->setText("Non-Academic Distinctions/Recognition (Full)");
    nonAcademicOrgLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *nonAcademicOrgEdit = new QLineEdit(this);
    nonAcademicOrgEdit->setFont(f1);
    nonAcademicOrgEdit->setAlignment(Qt::AlignLeft);
    nonAcademicOrgEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    nonAcademicOrgEdit->setObjectName("nonAcademicOrgEdit" + QString::number(totalNonAcademicRec));
    nonAcademicOrgEdit->setText(nonARec);

    ui->nonAcademicDistinctionLayout->addRow(nonAcademicOrgLabel, nonAcademicOrgEdit);

    ui->newNonAcademicRecLabel->setText("Add another non-academic recognition?");
    ui->deleteNonAcademicRecB->setVisible(true);
}

void NewEmployee::on_deleteNonAcademicRecB_clicked()
{
    if (totalNonAcademicRec > 0){
        totalNonAcademicRec--;
        for (int i = 1; i <= 2; i++){
            QLayoutItem *item = ui->nonAcademicDistinctionLayout->takeAt(ui->nonAcademicDistinctionLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalNonAcademicRec != 0) ui->newNonAcademicRecLabel->setText("Add another non-academic recognition?");
        else ui->newNonAcademicRecLabel->setText("Add a new non-academic recognition?");
        if (totalNonAcademicRec == 0) ui->deleteNonAcademicRecB->setVisible(false);
    }
}

void NewEmployee::on_adOrgMembershipB_clicked()
{
    addOrgMembership("");
}

void NewEmployee::addOrgMembership(QString orgMembership){
    totalOrgMembership++;

    const QFont f1("Segoe UI", 11);

    QLabel *orgMembershipLabel = new QLabel(this);
    orgMembershipLabel->setFont(f1);
    orgMembershipLabel->setText("Membership in Association/Organization (Full)");
    orgMembershipLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *orgMembershipEdit = new QLineEdit(this);
    orgMembershipEdit->setFont(f1);
    orgMembershipEdit->setAlignment(Qt::AlignLeft);
    orgMembershipEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    orgMembershipEdit->setObjectName("orgMembershipEdit" + QString::number(totalOrgMembership));
    orgMembershipEdit->setText(orgMembership);

    ui->membershipOrgLayout->addRow(orgMembershipLabel, orgMembershipEdit);

    ui->newOrgMembershipLabel->setText("Add another org. membership?");
    ui->deleteOrgMembership->setVisible(true);
}

void NewEmployee::on_deleteOrgMembership_clicked()
{
    if (totalOrgMembership > 0){
        totalOrgMembership--;
        for (int i = 1; i <= 2; i++){
            QLayoutItem *item = ui->membershipOrgLayout->takeAt(ui->membershipOrgLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalOrgMembership != 0) ui->newOrgMembershipLabel->setText("Add another org. membership?");
        else ui->newOrgMembershipLabel->setText("Add a new org. membership?");
        if (totalOrgMembership == 0) ui->deleteOrgMembership->setVisible(false);
    }
}

void NewEmployee::on_newReferenceB_clicked()
{
    addReference("", "", "");
}

void NewEmployee::addReference(QString nameV, QString addressV, QString telNoV){
    totalReferences++;

    QLabel *referenceLabel = new QLabel(this);
    const QFont f("Segoe UI", 15);
    referenceLabel->setFont(f);
    referenceLabel->setText("<u>Reference " + QString::number(totalReferences) + "</u>");
    referenceLabel->setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    referenceLabel->setSizePolicy(sizePolicy);
    referenceLabel->setSizeIncrement(0, 0);
    referenceLabel->setBaseSize(0, 0);

    const QFont f1("Segoe UI", 11);

    QLabel *nameLabel = new QLabel(this);
    nameLabel->setFont(f1);
    nameLabel->setText("Full Name");
    nameLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *nameEdit = new QLineEdit(this);
    nameEdit->setFont(f1);
    nameEdit->setAlignment(Qt::AlignLeft);
    nameEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    nameEdit->setObjectName("nameRefEdit" + QString::number(totalReferences));
    nameEdit->setText(nameV);

    QLabel *addressLabel = new QLabel(this);
    addressLabel->setFont(f1);
    addressLabel->setText("Address");
    addressLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *addressEdit = new QLineEdit(this);
    addressEdit->setFont(f1);
    addressEdit->setAlignment(Qt::AlignLeft);
    addressEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    addressEdit->setObjectName("addressRefEdit" + QString::number(totalReferences));
    addressEdit->setText(addressV);

    QLabel *telNoLabel = new QLabel(this);
    telNoLabel->setFont(f1);
    telNoLabel->setText("Tel. No.");
    telNoLabel->setAlignment(Qt::AlignLeft);
    QLineEdit *telNoEdit = new QLineEdit(this);
    telNoEdit->setFont(f1);
    telNoEdit->setAlignment(Qt::AlignLeft);
    telNoEdit->setStyleSheet("QLineEdit {  border: 1px solid #7a7a7a;"
                                             "border-radius: 5px;}");
    telNoEdit->setObjectName("telNoRefEdit" + QString::number(totalReferences));
    telNoEdit->setText(telNoV);

    ui->referenceLayout->addRow(referenceLabel);
    ui->referenceLayout->addRow(nameLabel, nameEdit);
    ui->referenceLayout->addRow(addressLabel, addressEdit);
    ui->referenceLayout->addRow(telNoLabel, telNoEdit);

    ui->newReferenceLabel->setText("Add another reference?");
    ui->deleteReferenceB->setVisible(true);
}

bool NewEmployee::displayMsgAlertForRegUpdate(int mode)
{
    bool continueAction = false;
    const QFont msgFont("Segoe UI", 11);
    if (mode == 0){
        QMessageBox msgBox;
        msgBox.setFont(msgFont);
        msgBox.setText("Employee will now be added.");
        msgBox.setInformativeText("Continue?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();

        switch (ret) {
          case QMessageBox::Ok:
              continueAction = true; break;
          case QMessageBox::Cancel:
              break;
          default:
              // should never be reached
              break;
        }
    }
    else if (mode == 2){
        QMessageBox msgBox;
        msgBox.setFont(msgFont);
        msgBox.setText("Employee data will be updated.");
        msgBox.setInformativeText("Continue?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();

        switch (ret) {
          case QMessageBox::Ok:
              continueAction = true; break;
          case QMessageBox::Cancel:
              break;
          default:
              // should never be reached
              break;
        }
    }

    return continueAction;
}

void NewEmployee::on_deleteReferenceB_clicked()
{
    if (totalReferences > 0){
        totalReferences--;
        for (int i = 1; i <= 7; i++){
            QLayoutItem *item = ui->referenceLayout->takeAt(ui->referenceLayout->count() - 1);
            if ( item->layout() != 0) removeItem(item->layout());
            else {
                delete item->widget();
                delete item;
            }
        }
        if (totalReferences != 0) ui->newReferenceLabel->setText("Add another reference?");
        else ui->newReferenceLabel->setText("Add a new reference?");
        if (totalReferences == 0) ui->deleteReferenceB->setVisible(false);
    }
}

void NewEmployee::on_question1AYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question1ATextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question1ATextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question1BYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question1BTextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question1BTextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question2AYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question2ATextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question2ATextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question2BYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question2BTextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question2BTextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question3AYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question3ATextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question3ATextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question4AYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question4ATextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question4ATextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question5AYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question5ATextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question5ATextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question6AYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question6ATextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question6ATextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question6BYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question6BTextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question6BTextEdit->setDisabled(true);
    }
}

void NewEmployee::on_question6CYesCBClicked(int state)
{
    if (state == Qt::Checked){
        ui->question6CTextEdit->setDisabled(false);
    }
    else if (state == Qt::Unchecked){
        ui->question6CTextEdit->setDisabled(true);
    }
}

void NewEmployee::terminateTimedMessage()
{
    messageLabel->setText("");
}

void NewEmployee::on_registerB_clicked()
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








    QString firstName = ui->firstnameedit->text();
    QString lastName = ui->lastnameedit->text();
    QString middleName = ui->middlenameedit->text();
    QString nameExtension = ui->nameextedit->text();
    QString birthdate = ui->birthdateEdit->date().toString();
    QString placeOfBirth = ui->placeOfBirthEdit->text();

    int sex = 0;
    if (ui->maleCB->isChecked()) sex = 1;
    else if (ui->femaleCB->isChecked()) sex = 2;

    QString civilStatus = "";
    if (ui->singleCB->isChecked()) civilStatus = "single";
    else if (ui->marriedCB->isChecked()) civilStatus = "married";
    else if (ui->annulledCB->isChecked()) civilStatus = "annulled";
    else if (ui->widowedCB->isChecked()) civilStatus = "widowed";
    else if (ui->separatedCB->isChecked()) civilStatus = "separated";
    else if (ui->otherCStatusCB->isChecked()) civilStatus = ui->otherCStatusEdit->text();

    QString citizenship = ui->citizenshipEdit->text();
    double height = !ui->heightEdit->text().isEmpty() ? stod(ui->heightEdit->text().toStdString()) : 0;
    double weight = !ui->weightEdit->text().isEmpty() ? stod(ui->weightEdit->text().toStdString()) : 0;
    QString bloodtype = ui->bloodTypeEdit->text();
    QString gsisNo = ui->gsisNoEdit->text();
    QString pagibigNo = ui->pagibigNoEdit->text();
    QString philhealth = ui->philhealthNoEdit->text();
    QString sssNo = ui->sssNoEdit->text();
    QString resAddr = ui->residentAddrEdit->text();
    QString resTelNo = ui->telNoResAddrEdit->text();
    QString resZipCode = ui->zipCodeResAddrEdit->text();
    QString permAddr = ui->permAddrEdit->text();
    QString permTelNo = ui->telNoPermAddrEdit->text();
    QString permZipCode = ui->zipCodePermAddrEdit->text();
    QString email = ui->emailEdit->text();
    QString cellNo = ui->cellNoEdit->text();
    QString agencyEmpNo = ui->agencyNoEdit->text();
    QString tinNo = ui->tinNoEdit->text();

    QString fatherSurname = ui->fatherSurnameEdit->text();
    QString fatherFirstName = ui->fatherFirstNameEdit->text();
    QString fatherMiddleName = ui->fatherMiddleNameEdit->text();
    QString motherSurname = ui->motherSurnameEdit->text();
    QString motherFirstName = ui->motherFirstNameEdit->text();
    QString motherMiddleName = ui->motherMiddleNameEdit->text();

    int question1A;
    if (ui->question1AYesCB->isChecked()) question1A = -1;
    else question1A = 0;
    QString question1ADet = ui->question1ATextEdit->toHtml();
    int question1B;
    if (ui->question1BYesCB->isChecked()) question1B = -1;
    else question1B = 0;
    QString question1BDet = ui->question1BTextEdit->toHtml();
    int question2A;
    if (ui->question2AYesCB->isChecked()) question2A = -1;
    else question2A = 0;
    QString question2ADet = ui->question2ATextEdit->toHtml();
    int question2B;
    if (ui->question2BYesCB->isChecked()) question2B = -1;
    else question2B = 0;
    QString question2BDet = ui->question2BTextEdit->toHtml();
    int question3A;
    if (ui->question3AYesCB->isChecked()) question3A = -1;
    else question3A = 0;
    QString question3ADet = ui->question3ATextEdit->toHtml();
    int question4A;
    if (ui->question4AYesCB->isChecked()) question4A = -1;
    else question4A = 0;
    QString question4ADet = ui->question4ATextEdit->toHtml();
    int question5A;
    if (ui->question5AYesCB->isChecked()) question5A = -1;
    else question5A = 0;
    QString question5ADet = ui->question5ATextEdit->toHtml();
    int question6A;
    if (ui->question6AYesCB->isChecked()) question6A = -1;
    else question6A = 0;
    QString question6ADet = ui->question6ATextEdit->toHtml();
    int question6B;
    if (ui->question6BYesCB->isChecked()) question6B = -1;
    else question6B = 0;
    QString question6BDet = ui->question6BTextEdit->toHtml();
    int question6C;
    if (ui->question6CYesCB->isChecked()) question6C = -1;
    else question6C = 0;
    QString question6CDet = ui->question6CTextEdit->toHtml();

    QString commTaxNo = ui->commTaxNoEdit->text();
    QString issuedAt = ui->issuedAtEdit->text();
    QString issuedOn = ui->issuedOnEdit->date().toString();
    QString dateAccomp = ui->dateAccomplishEdit->date().toString();


    QSqlQuery query(datab);
    query.exec("SELECT * FROM [PERSONAL INFO] WHERE [FIRST NAME] "
               "LIKE '" + firstName + "' AND [MIDDLE NAME] LIKE"
                                      " '" + middleName + "' AND [SURNAME] LIKE '" + lastName + "'");
    int samenamesize = 0;\
    while (1){
        if (query.next()){
            samenamesize++;
        }
        else {
            break;
        }
    }

    boolQuery->clearQuery();
    boolQuery->addQuery(!firstName.isEmpty(), "No First Name");
    boolQuery->addQuery(!lastName.isEmpty(), "No Last Name");
    boolQuery->addQuery(!middleName.isEmpty(), "No Middle Name");
    if (mode == 0) boolQuery->addQuery(samenamesize == 0, "Employee already in database");
    boolQuery->addQuery(!birthdate.isEmpty(), "No birth date");
    boolQuery->addQuery(!placeOfBirth.isEmpty(), "No place of birth");
    boolQuery->addQuery(sex != 0, "Select a gender");
    boolQuery->addQuery(!civilStatus.isEmpty(), "Select a civil status");

    QString queryMessage = QString::fromStdString(boolQuery->earliestQuery());
    if (!queryMessage.isEmpty()){
        displayTimedMessage(queryMessage, 3000);
    }
    else {

        if (displayMsgAlertForRegUpdate(mode)){
            if (mode == 0){
                this->currentEmployeeID = generateValidEmployeeID();
            }
            QString lastProfUpdate = QDateTime::currentDateTime().toString();

            if (mode == 2) query.exec("DELETE FROM [PERSONAL INFO] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            query.clear();
            query.prepare("INSERT INTO [PERSONAL INFO] ([EMPLOYEE ID], [SURNAME], [FIRST NAME], [MIDDLE NAME], [NAME EXT], "
                       "[BIRTHDATE], [PLACE OF BIRTH], [SEX], [CIVIL STATUS], [CITIZENSHIP], [HEIGHT M], [WEIGHT KG], [BLOOD TYPE], "
                          "[GSIS ID NO], [PAG IBIG ID NO], [PHILHEALTH NO], [SSS NO], [RES ADDR], [RES ZIP CODE], [RES TEL NO], [PERM ADDR], "
                          "[PERM ZIP CODE], [PERM TEL NO], [EMAIL], [CELL NO], [AGENCY EMP NO], [TIN], [LAST UPDATE]) "
                       "VALUES (:EMPLOYEEID, :SURNAME, :FIRSTNAME, :MIDDLENAME, :NAMEEXT, "
                          ":BIRTHDATE, :PLACEOFBIRTH, :SEX, :CIVILSTATUS, :CITIZENSHIP, :HEIGHTM, :WEIGHTKG, :BLOODTYPE, "
                             ":GSISIDNO, :PAGIBIGIDNO, :PHILHEALTHNO, :SSSNO, :RESADDR, :RESZIPCODE, :RESTELNO, :PERMADDR, "
                             ":PERMZIPCODE, :PERMTELNO, :EMAIL, :CELLNO, :AGENCYEMPNO, :TIN, :LASTUPDATE)");
            query.bindValue(":EMPLOYEEID", currentEmployeeID);
            query.bindValue(":SURNAME", lastName);
            query.bindValue(":FIRSTNAME", firstName);
            query.bindValue(":MIDDLENAME", middleName);
            query.bindValue(":NAMEEXT", nameExtension);
            query.bindValue(":BIRTHDATE", birthdate);
            query.bindValue(":PLACEOFBIRTH", placeOfBirth);
            query.bindValue(":SEX", sex);
            query.bindValue(":CIVILSTATUS", civilStatus);
            query.bindValue(":CITIZENSHIP", citizenship);
            query.bindValue(":HEIGHTM", height);
            query.bindValue(":WEIGHTKG", weight);
            query.bindValue(":BLOODTYPE", bloodtype);
            query.bindValue(":GSISIDNO", gsisNo);
            query.bindValue(":PAGIBIGIDNO", pagibigNo);
            query.bindValue(":PHILHEALTHNO", philhealth);
            query.bindValue(":SSSNO", sssNo);
            query.bindValue(":RESADDR", resAddr);
            query.bindValue(":RESZIPCODE", resZipCode);
            query.bindValue(":RESTELNO", resTelNo);
            query.bindValue(":PERMADDR", permAddr);
            query.bindValue(":PERMZIPCODE", permZipCode);
            query.bindValue(":PERMTELNO", permTelNo);
            query.bindValue(":EMAIL", email);
            query.bindValue(":CELLNO", cellNo);
            query.bindValue(":AGENCYEMPNO", agencyEmpNo);
            query.bindValue(":TIN", tinNo);
            query.bindValue(":LASTUPDATE", lastProfUpdate);
            query.exec();

            if (mode == 2) query.exec("DELETE FROM [SPOUSES] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalSpouses > 0){
                for (int i = 1; i <= totalSpouses; i++){
                    QString spouseFirstName = ui->familyBgBox->findChild<QLineEdit*>("spouseFirstName" + QString::number(i))->text();
                    QString spouseLastName = ui->familyBgBox->findChild<QLineEdit*>("spouseLastName" + QString::number(i))->text();
                    QString spouseMiddleName = ui->familyBgBox->findChild<QLineEdit*>("spouseMiddleName" + QString::number(i))->text();
                    QString spouseOccupation = ui->familyBgBox->findChild<QLineEdit*>("spouseOccupation" + QString::number(i))->text();
                    QString spouseEmployerName = ui->familyBgBox->findChild<QLineEdit*>("spouseEmployerName" + QString::number(i))->text();
                    QString spouseBusAddr = ui->familyBgBox->findChild<QLineEdit*>("spouseBusAddr" + QString::number(i))->text();
                    QString spouseTelNo = ui->familyBgBox->findChild<QLineEdit*>("spouseTelNo" + QString::number(i))->text();

                    QSqlQuery query2(datab);
                    query2.prepare("INSERT INTO [SPOUSES] ([EMPLOYEE ID], [FIRST NAME], [LAST NAME], [MIDDLE NAME], [OCCUPATION], [EMPLOYER NAME], [BUS ADDR], [TEL NO]) "
                                 "VALUES (:EMPLOYEEID, :FIRSTNAME, :LASTNAME, :MIDDLENAME, :OCCUPATION, :EMPLOYERNAME, :BUSADDR, :TELNO)");
                    query2.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query2.bindValue(":FIRSTNAME", spouseFirstName);
                    query2.bindValue(":LASTNAME", spouseLastName);
                    query2.bindValue(":MIDDLENAME", spouseMiddleName);
                    query2.bindValue(":OCCUPATION", spouseOccupation);
                    query2.bindValue(":EMPLOYERNAME", spouseEmployerName);
                    query2.bindValue(":BUSADDR", spouseBusAddr);
                    query2.bindValue(":TELNO", spouseTelNo);
                    query2.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [FAMILY BGD] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            query.clear();
            query.prepare("INSERT INTO [FAMILY BGD] ([EMPLOYEE ID], [FATHER SURNAME], [FATHER FIRSTNAME], [FATHER MIDDLENAME], "
                          "[MOTHER SURNAME], [MOTHER FIRSTNAME], [MOTHER MIDDLENAME]) "
                       "VALUES (:EMPLOYEEID, :FATHERSURNAME, :FATHERFIRSTNAME, :FATHERMIDDLENAME, :MOTHERSURNAME, :MOTHERFIRSTNAME, "
                          ":MOTHERMIDDLENAME)");
            query.bindValue(":EMPLOYEEID", currentEmployeeID);
            query.bindValue(":FATHERSURNAME", fatherSurname);
            query.bindValue(":FATHERFIRSTNAME", fatherFirstName);
            query.bindValue(":FATHERMIDDLENAME", fatherMiddleName);
            query.bindValue(":MOTHERSURNAME", motherSurname);
            query.bindValue(":MOTHERFIRSTNAME", motherFirstName);
            query.bindValue(":MOTHERMIDDLENAME", motherMiddleName);
            query.exec();

            if (mode == 2) query.exec("DELETE FROM [CHILDREN] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalChildren > 0){
                for (int i = 1; i <= totalChildren; i++){
                    QString childName = ui->familyBgBox->findChild<QLineEdit*>("childName" + QString::number(i))->text();
                    QString bDay = ui->familyBgBox->findChild<QDateEdit*>("bDayEdit" + QString::number(i))->date().toString();

                    query.clear();
                    query.prepare("INSERT INTO [CHILDREN] ([EMPLOYEE ID], [CHILD NAME], [BIRTH DATE]) "
                                 "VALUES (:EMPLOYEEID, :CHILDNAME, :BIRTHDATE)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":CHILDNAME", childName);
                    query.bindValue(":BIRTHDATE", bDay);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [EDU BGD] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalEduBg > 0){
                for (int i = 1; i <= totalEduBg; i++){
                    QString level = ui->eduBgBox->findChild<QComboBox*>("levelCBox" + QString::number(i))->currentText();
                    QString schoolName = ui->eduBgBox->findChild<QLineEdit*>("schoolNameEdit" + QString::number(i))->text();
                    QString degree = ui->eduBgBox->findChild<QLineEdit*>("degreeEdit" + QString::number(i))->text();
                    QString yearGradStr = ui->eduBgBox->findChild<QLineEdit*>("yearGradEdit" + QString::number(i))->text();
                    int yearGrad = !yearGradStr.isEmpty() ? stoi(yearGradStr.toStdString()) : 0;
                    QString units = ui->eduBgBox->findChild<QLineEdit*>("unitsEdit" + QString::number(i))->text();
                    QString incDateFrom = ui->eduBgBox->findChild<QLineEdit*>("eduIncDateFromEdit" + QString::number(i))->text();
                    QString incDateTo = ui->eduBgBox->findChild<QLineEdit*>("eduIncDateToEdit" + QString::number(i))->text();
                    QString scholarship = ui->eduBgBox->findChild<QLineEdit*>("scholarshipEdit" + QString::number(i))->text();

                    query.clear();
                    query.prepare("INSERT INTO [EDU BGD] ([EMPLOYEE ID], [LEVEL], [NAME OF SCHOOL], [DEGREE COURSE], [YEAR GRAD], "
                                  "[HIGH GRADE LEVEL UNITS EARNED], [DATE OF ATTENDANCE FROM], [DATE OF ATTENDANCE TO], [SCHOLARSHIP ACADEMIC HONOR]) "
                                 "VALUES (:EMPLOYEEID, :LEVEL, :NAMEOFSCHOOL, :DEGREECOURSE, :YEARGRAD, :HIGHGRADELEVELUNITSEARNED,"
                                  " :DATEOFATTENDANCEFROM, :DATEOFATTENDANCETO, :SCHOLARSHIPACADEMICHONOR)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":LEVEL", level);
                    query.bindValue(":NAMEOFSCHOOL", schoolName);
                    query.bindValue(":DEGREECOURSE", degree);
                    query.bindValue(":YEARGRAD", yearGrad);
                    query.bindValue(":HIGHGRADELEVELUNITSEARNED", units);
                    query.bindValue(":DATEOFATTENDANCEFROM", incDateFrom);
                    query.bindValue(":DATEOFATTENDANCETO", incDateTo);
                    query.bindValue(":SCHOLARSHIPACADEMICHONOR", scholarship);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [CIVIL SERV] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalCivilService > 0){
                for (int i = 1; i <= totalCivilService; i++){
                    QString careerService = ui->civilServElBox->findChild<QLineEdit*>("careerServiceEdit" + QString::number(i))->text();
                    QString rating = ui->civilServElBox->findChild<QLineEdit*>("ratingEdit" + QString::number(i))->text();
                    QString dateOfExam = ui->civilServElBox->findChild<QDateEdit*>("dateOfExamEdit" + QString::number(i))->date().toString();
                    QString placeOfExam = ui->civilServElBox->findChild<QLineEdit*>("placeOfExamEdit" + QString::number(i))->text();
                    QString licenseNumber = ui->civilServElBox->findChild<QLineEdit*>("licenseNumberEdit" + QString::number(i))->text();
                    QString licenseDate = ui->civilServElBox->findChild<QDateEdit*>("licenseDateEdit" + QString::number(i))->date().toString();

                    query.clear();
                    query.prepare("INSERT INTO [CIVIL SERV] ([EMPLOYEE ID], [CAREER SERVICE], [RATING], [EXAM DATE], [PLACE OF EXAM], [LIC NO], [LIC EXP]) "
                                 "VALUES (:EMPLOYEEID, :CAREERSERVICE, :RATING, :EXAMDATE, :PLACEOFEXAM, :LICNO, :LICEXP)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":CAREERSERVICE", careerService);
                    query.bindValue(":RATING", rating);
                    query.bindValue(":EXAMDATE", dateOfExam);
                    query.bindValue(":PLACEOFEXAM", placeOfExam);
                    query.bindValue(":LICNO", licenseNumber);
                    query.bindValue(":LICEXP", licenseDate);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [SERVICE REC] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalServiceRecord > 0){
                for (int i = 1; i <= totalServiceRecord; i++){
                    QString servRecIncDateFrom = ui->servRecBox->findChild<QDateEdit*>("servRecIncDateFrom" + QString::number(i))->date().toString();
                    QString servRecIncDateTo;
                    if (ui->servRecBox->findChild<QCheckBox*>("servRecIncDateToPresentCB" + QString::number(i))->isChecked()) servRecIncDateTo = "PRESENT";
                    else servRecIncDateTo = ui->servRecBox->findChild<QDateEdit*>("servRecIncDateTo" + QString::number(i))->date().toString();
                    QString designation = ui->servRecBox->findChild<QLineEdit*>("designationEdit" + QString::number(i))->text();
                    QString status = ui->servRecBox->findChild<QComboBox*>("statusCBox" + QString::number(i))->currentText();
                    string salaryStr = ui->servRecBox->findChild<QLineEdit*>("salaryEdit" + QString::number(i))->text().toStdString();
                    double salary = !salaryStr.empty() ? stod(salaryStr) : 0;
                    QString station = ui->servRecBox->findChild<QLineEdit*>("stationEdit" + QString::number(i))->text();
                    QString branch = ui->servRecBox->findChild<QLineEdit*>("branchEdit" + QString::number(i))->text();
                    QString lwPay = ui->servRecBox->findChild<QLineEdit*>("lwPayEdit" + QString::number(i))->text();
                    QString separationDateFrom = ui->servRecBox->findChild<QDateEdit*>("separationDateFrom" + QString::number(i))->date().toString();
                    QString separationDateCause = ui->servRecBox->findChild<QLineEdit*>("separationDateCause" + QString::number(i))->text();

                    query.clear();
                    query.prepare("INSERT INTO [SERVICE REC] ([EMPLOYEE ID], [INC DATE FROM], [INC DATE TO], [DESIGNATION], [STATUS], [ANNUAL SAL],"
                                  " [ASS STATION], [BRANCH], [LW PAY], [SEP DATE], [SEP CAUSE]) "
                                 "VALUES (:EMPLOYEEID, :INCDATEFROM, :INCDATETO, :DESIGNATION, :STATUS, :ANNUALSAL, :ASSSTATION, :BRANCH, "
                                  ":LWPAY, :SEPDATE, :SEPCAUSE)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":INCDATEFROM", servRecIncDateFrom);
                    query.bindValue(":INCDATETO", servRecIncDateTo);
                    query.bindValue(":DESIGNATION", designation);
                    query.bindValue(":STATUS", status);
                    query.bindValue(":ANNUALSAL", salary);
                    query.bindValue(":ASSSTATION", station);
                    query.bindValue(":BRANCH", branch);
                    query.bindValue(":LWPAY", lwPay);
                    query.bindValue(":separationDateFrom", separationDateFrom);
                    query.bindValue(":SEPCAUSE", separationDateCause);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [VOLUNTARY WORK] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalVoluntaryWork > 0){
                for (int i = 1; i <= totalVoluntaryWork; i++){
                    QString nameAndAddr = ui->volWorkBox->findChild<QLineEdit*>("nameAndAddrEdit" + QString::number(i))->text();
                    QString volWorkIncDateFrom = ui->volWorkBox->findChild<QDateEdit*>("volWorkIncDateFromEdit" + QString::number(i))->date().toString();
                    QString volWorkIncDateTo;
                    if (ui->volWorkBox->findChild<QCheckBox*>("volWorkIncDateToPresentCB" + QString::number(i))->isChecked()) volWorkIncDateTo = "PRESENT";
                    else volWorkIncDateTo = ui->volWorkBox->findChild<QDateEdit*>("volWorkIncDateToEdit" + QString::number(i))->date().toString();
                    string numOfHoursStr = ui->volWorkBox->findChild<QLineEdit*>("numOfHoursEdit" + QString::number(i))->text().toStdString();
                    double numOfHours = !numOfHoursStr.empty() ? stod(numOfHoursStr) : 0;
                    QString posOfWork = ui->volWorkBox->findChild<QLineEdit*>("posOfWorkEdit" + QString::number(i))->text();

                    query.clear();
                    query.prepare("INSERT INTO [VOLUNTARY WORK] ([EMPLOYEE ID], [NAME AND ADDR], [INC DATE FROM], [INC DATE TO], "
                                  "[NO OF HOURS], [POSITION]) "
                                 "VALUES (:EMPLOYEEID, :NAMEANDADDR, :INCDATEFROM, :INCDATETO, :NOOFHOURS, :POSITION)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":NAMEANDADDR", nameAndAddr);
                    query.bindValue(":INCDATEFROM", volWorkIncDateFrom);
                    query.bindValue(":INCDATETO", volWorkIncDateTo);
                    query.bindValue(":NOOFHOURS", numOfHours);
                    query.bindValue(":POSITION", posOfWork);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [TRAINING PROM] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalTrainingProg > 0){
                for (int i = 1; i <= totalTrainingProg; i++){
                    QString seminarName = ui->trainProgBox->findChild<QLineEdit*>("seminarNameEdit" + QString::number(i))->text();
                    QString trainProgIncDateFrom = ui->trainProgBox->findChild<QDateEdit*>("trainProgIncDateFromEdit" + QString::number(i))->date().toString();
                    QString trainProgIncDateTo;
                    if (ui->trainProgBox->findChild<QCheckBox*>("trainProgIncDateToPresentCB" + QString::number(i))->isChecked()) trainProgIncDateTo = "PRESENT";
                    else trainProgIncDateTo = ui->trainProgBox->findChild<QDateEdit*>("trainProgIncDateToEdit" + QString::number(i))->date().toString();
                    string numOfHoursStr = ui->trainProgBox->findChild<QLineEdit*>("numOfHoursProgEdit" + QString::number(i))->text().toStdString();
                    double numOfHoursProg = !numOfHoursStr.empty() ? stod(numOfHoursStr) : 0;
                    QString conducted = ui->trainProgBox->findChild<QLineEdit*>("conductedEdit" + QString::number(i))->text();

                    query.clear();
                    query.prepare("INSERT INTO [TRAINING PROM] ([EMPLOYEE ID], [SEMINAR TITLE], [INC DATE FROM], [INC DATE TO], "
                                  "[NO OF HOURS], [CONDUCTED BY]) "
                                 "VALUES (:EMPLOYEEID, :SEMINARTITLE, :INCDATEFROM, :INCDATETO, :NOOFHOURS, :CONDUCTEDBY)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":SEMINARTITLE", seminarName);
                    query.bindValue(":INCDATEFROM", trainProgIncDateFrom);
                    query.bindValue(":INCDATETO", trainProgIncDateTo);
                    query.bindValue(":NOOFHOURS", numOfHoursProg);
                    query.bindValue(":CONDUCTEDBY", conducted);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [SKILL HOBBY] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalSkills > 0){
                for (int i = 1; i <= totalSkills; i++){
                    QString skillHobbyEdit = ui->otherInfoBox->findChild<QLineEdit*>("skillHobbyEdit" + QString::number(i))->text();

                    query.clear();
                    query.prepare("INSERT INTO [SKILL HOBBY] ([EMPLOYEE ID], [SKILL HOBBY]) "
                                 "VALUES (:EMPLOYEEID, :SKILLHOBBY)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":SKILLHOBBY", skillHobbyEdit);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [NON ACADEMIC] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalNonAcademicRec > 0){
                for (int i = 1; i <= totalNonAcademicRec; i++){
                    QString nonAcademicOrg = ui->otherInfoBox->findChild<QLineEdit*>("nonAcademicOrgEdit" + QString::number(i))->text();

                    query.clear();
                    query.prepare("INSERT INTO [NON ACADEMIC] ([EMPLOYEE ID], [NON ACADEMIC ORG]) "
                                 "VALUES (:EMPLOYEEID, :NONACADEMICORG)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":NONACADEMICORG", nonAcademicOrg);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [ORG MEM] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalOrgMembership > 0){
                for (int i = 1; i <= totalOrgMembership; i++){
                    QString orgMembershipEdit = ui->otherInfoBox->findChild<QLineEdit*>("orgMembershipEdit" + QString::number(i))->text();

                    query.clear();
                    query.prepare("INSERT INTO [ORG MEM] ([EMPLOYEE ID], [ORG MEM]) "
                                 "VALUES (:EMPLOYEEID, :ORGMEM)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":ORGMEM", orgMembershipEdit);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [REFERENCES] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            if (totalReferences > 0){
                for (int i = 1; i <= totalReferences; i++){
                    QString nameRef = ui->otherInfoBox->findChild<QLineEdit*>("nameRefEdit" + QString::number(i))->text();
                    QString addressRef = ui->otherInfoBox->findChild<QLineEdit*>("addressRefEdit" + QString::number(i))->text();
                    QString telNoRef = ui->otherInfoBox->findChild<QLineEdit*>("telNoRefEdit" + QString::number(i))->text();

                    query.clear();
                    query.prepare("INSERT INTO [REFERENCES] ([EMPLOYEE ID], [FULL NAME], [ADDRESS], [TEL NO]) "
                                 "VALUES (:EMPLOYEEID, :FULLNAME, :ADDRESS, :TELNO)");
                    query.bindValue(":EMPLOYEEID", currentEmployeeID);
                    query.bindValue(":FULLNAME", nameRef);
                    query.bindValue(":ADDRESS", addressRef);
                    query.bindValue(":TELNO", telNoRef);
                    query.exec();
                }
            }

            if (mode == 2) query.exec("DELETE FROM [OTHER INFO I] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            query.clear();
            query.prepare("INSERT INTO [OTHER INFO I] ([EMPLOYEE ID], [Q36A], [Q36A DET], [Q36B], [Q36B DET], [Q37A], [Q37A DET], [Q37B], "
                          "[Q37B DET], [Q38], [Q38 DET], [Q39], [Q39 DET], [Q40], [Q40 DET], [Q41A], [Q41A DET], [Q41B], [Q41B DET], [Q41C], "
                          "[Q41C DET]) "
                         "VALUES (:EMPLOYEEID, :Q36A, :Q36ADET, :Q36B, :Q36BDET, :Q37A, :Q37ADET, :Q37B, :Q37BDET, :Q38, :Q38DET, :Q39, "
                          ":Q39DET, :Q40, :Q40DET, :Q41A, :Q41ADET, :Q41B, :Q41BDET, :Q41C, :Q41CDET)");
            query.bindValue(":EMPLOYEEID", currentEmployeeID);
            query.bindValue(":Q36A", question1A);
            query.bindValue(":Q36ADET", question1ADet);
            query.bindValue(":Q36B", question1B);
            query.bindValue(":Q36BDET", question1BDet);
            query.bindValue(":Q37A", question2A);
            query.bindValue(":Q37ADET", question2ADet);
            query.bindValue(":Q37B", question2B);
            query.bindValue(":Q37BDET", question2BDet);
            query.bindValue(":Q38", question3A);
            query.bindValue(":Q38DET", question3ADet);
            query.bindValue(":Q39", question4A);
            query.bindValue(":Q39DET", question4ADet);
            query.bindValue(":Q40", question5A);
            query.bindValue(":Q40DET", question5ADet);
            query.bindValue(":Q41A", question6A);
            query.bindValue(":Q41ADET", question6ADet);
            query.bindValue(":Q41B", question6B);
            query.bindValue(":Q41BDET", question6BDet);
            query.bindValue(":Q41C", question6C);
            query.bindValue(":Q41CDET", question6CDet);
            query.exec();

            if (mode == 2) query.exec("DELETE FROM [OTHER INFO II] WHERE [EMPLOYEE ID] = '" + currentEmployeeID + "'");
            query.clear();
            query.prepare("INSERT INTO [OTHER INFO II] ([EMPLOYEE ID], [COMM TAX NO], [ISSUED AT], [ISSUED ON], [DATE ACCOMP]) "
                         "VALUES (:EMPLOYEEID, :COMMTAXNO, :ISSUEDAT, :ISSUEDON, :DATEACCOMP)");
            query.bindValue(":EMPLOYEEID", currentEmployeeID);
            query.bindValue(":COMMTAXNO", commTaxNo);
            query.bindValue(":ISSUEDAT", issuedAt);
            query.bindValue(":ISSUEDON", issuedOn);
            query.bindValue(":DATEACCOMP", dateAccomp);
            query.exec();

            EmployeeManagerHome *empManHome = (EmployeeManagerHome*)(stackWidget->widget(5));
            if (mode == 0){
                empManHome->displayTimedMessage("New employee added.", 2000);
            }
            else if (mode == 2){
                PlantillaPersonnel *pPersonnel = (PlantillaPersonnel*)(stackWidget->widget(1));
                pPersonnel->refreshData();
                empManHome->displayTimedMessage("Employee updated.", 2000);
            }
            stackWidget->setCurrentIndex(5);
        }


    }
}

QString NewEmployee::generateValidEmployeeID()
{
    char c[20];
    generateRandStr(c, 20);
    QString employeeid = QString::fromStdString(string(c));

    int size = 0;
    QSqlQuery query(datab);
    query.exec("SELECT * FROM [PERSONAL INFO] WHERE [EMPLOYEE ID] LIKE '" + employeeid + "'");

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
            generateRandStr(c, 20);
            employeeid = QString::fromStdString(string(c));
            query.clear();
            query.exec("SELECT * FROM [PERSONAL INFO] WHERE [EMPLOYEE ID] LIKE '" + employeeid + "'");
            size = 0;
        }
    }

    return employeeid;
}
void NewEmployee::setDatab(const QSqlDatabase &value)
{
    datab = value;
}

void NewEmployee::displayTimedMessage(QString message, int countdown)
{
    messageLabel->setText(message);
    messageTimer->start(countdown);
}


void NewEmployee::on_feetEdit_textEdited(const QString str)
{
    float feet = str.toFloat();
    float inch = ui->inchEdit->text().toFloat();
    float inchFeet = inch / 12;
    float totalFeet = inchFeet + feet;
    float meters = totalFeet / 3.28f;
    ui->heightEdit->setText(QString::number(meters));
}

void NewEmployee::on_inchEdit_textEdited(const QString str)
{
    float feet = ui->feetEdit->text().toFloat();
    float inch = str.toFloat();
    float inchFeet = inch / 12;
    float totalFeet = inchFeet + feet;
    float meters = totalFeet / 3.28f;
    ui->heightEdit->setText(QString::number(meters));
}

void NewEmployee::on_heightEdit_textEdited(const QString str)
{
    float meters = str.toFloat();
    float feet = 3.28f * meters;
    float fractpart, intpart;
    fractpart = modf(feet , &intpart);
    float feetToInch = fractpart * 12;
    ui->feetEdit->setText(QString::number(intpart));
    ui->inchEdit->setText(QString::number(feetToInch));
}

void NewEmployee::enableQDateObject(QObject *dateDataObj)
{
    PresentDateData *dateData = (PresentDateData*)(dateDataObj);
    if (dateData->checkBox->isChecked()) dateData->dateEdit->setDisabled(true);
    else dateData->dateEdit->setDisabled(false);
}

void NewEmployee::updateFormsWithID(QString employeeID)
{
    this->currentEmployeeID = employeeID;

    QSqlQuery query(datab);
    query.exec("SELECT [SURNAME], [FIRST NAME], [MIDDLE NAME], [NAME EXT], [BIRTHDATE], [PLACE OF BIRTH], [SEX], [CIVIL STATUS], "
               "[CITIZENSHIP], [HEIGHT M], [WEIGHT KG], [BLOOD TYPE], [GSIS ID NO], [PAG IBIG ID NO], [PHILHEALTH NO], [SSS NO], "
               "[RES ADDR], [RES ZIP CODE], [RES TEL NO], [PERM ADDR], [PERM ZIP CODE], [PERM TEL NO], [EMAIL], [CELL NO], "
               "[AGENCY EMP NO], [TIN], [LAST UPDATE] FROM [PERSONAL INFO] where [EMPLOYEE ID] = '" + employeeID + "'");

    while (query.next()) {
           QString surname = query.value(0).toString();
           QString firstname = query.value(1).toString();
           QString middlename = query.value(2).toString();
           QString nameExt = query.value(3).toString();
           QString birthDate = query.value(4).toString();
           QString placeOfBirth = query.value(5).toString();
           int sex = query.value(6).toInt();
           QString civilStatus = query.value(7).toString();
           QString citizenship = query.value(8).toString();
           float height = query.value(9).toFloat();
           float weight = query.value(10).toFloat();
           QString bloodType = query.value(11).toString();
           QString gsisNo = query.value(12).toString();
           QString pagibigNo = query.value(13).toString();
           QString philhealth = query.value(14).toString();
           QString sssNo = query.value(15).toString();
           QString resAddr = query.value(16).toString();
           QString resZipCode = query.value(17).toString();
           QString resTelNo = query.value(18).toString();
           QString permAddr = query.value(19).toString();
           QString permZipCode = query.value(20).toString();
           QString permTelNo = query.value(21).toString();
           QString email = query.value(22).toString();
           QString celNo = query.value(23).toString();
           QString agencyEmpNo = query.value(24).toString();
           QString tin = query.value(25).toString();
           QString lastUpdate = query.value(26).toString();

           ui->lastnameedit->setText(surname);
           ui->firstnameedit->setText(firstname);
           ui->middlenameedit->setText(middlename);
           ui->nameextedit->setText(nameExt);
           ui->birthdateEdit->setDate(QDate::fromString(birthDate));
           ui->placeOfBirthEdit->setText(placeOfBirth);

           if (sex == 1) ui->maleCB->setChecked(true);
           else if (sex == 2) ui->femaleCB->setChecked(true);

           if (civilStatus.toLower() == "single") ui->singleCB->setChecked(true);
           else if (civilStatus.toLower() == "married") ui->marriedCB->setChecked(true);
           else if (civilStatus.toLower() == "annulled") ui->annulledCB->setChecked(true);
           else if (civilStatus.toLower() == "widowed") ui->widowedCB->setChecked(true);
           else if (civilStatus.toLower() == "separated") ui->separatedCB->setChecked(true);
           else {
               ui->otherCStatusCB->setChecked(true);
               ui->otherCStatusEdit->setText(civilStatus);
           }

           ui->citizenshipEdit->setText(citizenship);

           ui->heightEdit->setText(QString::number(height));
           float meters = ui->heightEdit->text().toFloat();
           float feet = 3.28f * meters;
           float fractpart, intpart;
           fractpart = modf(feet , &intpart);
           float feetToInch = fractpart * 12;
           ui->feetEdit->setText(QString::number(intpart));
           ui->inchEdit->setText(QString::number(feetToInch));

           ui->weightEdit->setText(QString::number(weight));
           ui->bloodTypeEdit->setText(bloodType);
           ui->gsisNoEdit->setText(gsisNo);
           ui->pagibigNoEdit->setText(pagibigNo);
           ui->philhealthNoEdit->setText(philhealth);
           ui->sssNoEdit->setText(sssNo);
           ui->residentAddrEdit->setText(resAddr);
           ui->zipCodeResAddrEdit->setText(resZipCode);
           ui->telNoResAddrEdit->setText(resTelNo);
           ui->permAddrEdit->setText(permAddr);
           ui->zipCodePermAddrEdit->setText(permZipCode);
           ui->telNoPermAddrEdit->setText(permTelNo);
           ui->emailEdit->setText(email);
           ui->cellNoEdit->setText(celNo);
           ui->agencyNoEdit->setText(agencyEmpNo);
           ui->tinNoEdit->setText(tin);
    }

    query.clear();
    query.exec("SELECT [FIRST NAME], [LAST NAME], [MIDDLE NAME], [OCCUPATION], [EMPLOYER NAME], [BUS ADDR], [TEL NO] "
               "FROM [SPOUSES] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString firstName = query.value(0).toString();
        QString lastName = query.value(1).toString();
        QString middleName = query.value(2).toString();
        QString occupation = query.value(3).toString();
        QString employerName = query.value(4).toString();
        QString busAddr = query.value(5).toString();
        QString telNo = query.value(6).toString();

        addSpouse(firstName, lastName, middleName, occupation, employerName, busAddr, telNo);
    }

    query.clear();
    query.exec("SELECT [FATHER SURNAME], [FATHER FIRSTNAME], [FATHER MIDDLENAME], [MOTHER SURNAME], [MOTHER FIRSTNAME], "
               "[MOTHER MIDDLENAME] FROM [FAMILY BGD] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString fatherSurname = query.value(0).toString();
        QString fatherFirstName = query.value(1).toString();
        QString fatherMiddleName = query.value(2).toString();
        QString motherSurname = query.value(3).toString();
        QString motherFirstName = query.value(4).toString();
        QString motherMiddleName = query.value(5).toString();

        ui->fatherSurnameEdit->setText(fatherSurname);
        ui->fatherFirstNameEdit->setText(fatherFirstName);
        ui->fatherMiddleNameEdit->setText(fatherMiddleName);
        ui->motherSurnameEdit->setText(motherSurname);
        ui->motherFirstNameEdit->setText(motherFirstName);
        ui->motherMiddleNameEdit->setText(motherMiddleName);
    }

    query.clear();
    query.exec("SELECT [CHILD NAME], [BIRTH DATE] FROM [CHILDREN] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString childName = query.value(0).toString();
        QString birthDate = query.value(1).toString();

        addChild(childName, birthDate);
    }

    query.clear();
    query.exec("SELECT [LEVEL], [NAME OF SCHOOL], [DEGREE COURSE], [YEAR GRAD], [HIGH GRADE LEVEL UNITS EARNED], [DATE OF ATTENDANCE FROM], "
               "[DATE OF ATTENDANCE TO], [SCHOLARSHIP ACADEMIC HONOR] FROM [EDU BGD] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString level = query.value(0).toString();
        QString nameOfSchool = query.value(1).toString();
        QString degree = query.value(2).toString();
        QString yearGrad = query.value(3).toString();
        QString highGradeUnit = query.value(4).toString();
        QString dateOfAttendanceFrom = query.value(5).toString();
        QString dateOfAttendanceTo = query.value(6).toString();
        QString scholarship = query.value(7).toString();

        addEducationBG(level, nameOfSchool, degree, yearGrad, highGradeUnit, dateOfAttendanceFrom, dateOfAttendanceTo, scholarship);
    }

    query.clear();
    query.exec("SELECT [CAREER SERVICE], [RATING], [EXAM DATE], [PLACE OF EXAM], [LIC NO], [LIC EXP] FROM [CIVIL SERV] "
               "where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString careerService = query.value(0).toString();
        QString rating = query.value(1).toString();
        QString examDate = query.value(2).toString();
        QString placeOfExam = query.value(3).toString();
        QString licNo = query.value(4).toString();
        QString licExp = query.value(5).toString();

        addCivilService(careerService, rating, examDate, placeOfExam, licNo, licExp);
    }

    query.clear();
    query.exec("SELECT [INC DATE FROM], [INC DATE TO], [DESIGNATION], [STATUS], [ANNUAL SAL], [ASS STATION], [BRANCH], [LW PAY], [SEP DATE], "
               "[SEP CAUSE] FROM [SERVICE REC] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString incDateFrom = query.value(0).toString();
        QString incDateTo = query.value(1).toString();;
        QString designation = query.value(2).toString();
        QString status = query.value(3).toString();
        double annualSal = query.value(4).toDouble();
        QString assStation = query.value(5).toString();
        QString branch = query.value(6).toString();
        QString lwPay = query.value(7).toString();
        QString sepDate = query.value(8).toString();
        QString sepCause = query.value(9).toString();

        addServiceRecord(incDateFrom, incDateTo, designation, status, QString::number(annualSal), assStation, branch, lwPay,
                         sepDate, sepCause);
    }

    query.clear();
    query.exec("SELECT [NAME AND ADDR], [INC DATE FROM], [INC DATE TO], [NO OF HOURS], [POSITION] FROM [VOLUNTARY WORK] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString nameAndAddr = query.value(0).toString();
        QString incDateFrom = query.value(1).toString();
        QString incDateTo = query.value(2).toString();
        double noOfHours = query.value(3).toDouble();
        QString position = query.value(4).toString();

        addVoluntaryWork(nameAndAddr, incDateFrom, incDateTo, QString::number(noOfHours), position);
    }

    query.clear();
    query.exec("SELECT [SEMINAR TITLE], [INC DATE FROM], [INC DATE TO], [NO OF HOURS], [CONDUCTED BY] FROM "
               "[TRAINING PROM] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString seminarTitle = query.value(0).toString();
        QString incDateFrom = query.value(1).toString();
        QString incDateTo = query.value(2).toString();
        double noOfHours = query.value(3).toDouble();
        QString conductedBy = query.value(4).toString();

        addTrainingProgram(seminarTitle, incDateFrom, incDateTo, QString::number(noOfHours), conductedBy);
    }

    query.clear();
    query.exec("SELECT [SKILL HOBBY] FROM [SKILL HOBBY] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString skillHobby = query.value(0).toString();

        addNewSkillHobby(skillHobby);
    }

    query.clear();
    query.exec("SELECT [NON ACADEMIC ORG] FROM [NON ACADEMIC] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString nonAcademic = query.value(0).toString();

        addNonAcademicRecognition(nonAcademic);
    }

    query.clear();
    query.exec("SELECT [ORG MEM] FROM [ORG MEM] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString orgMem = query.value(0).toString();

        addOrgMembership(orgMem);
    }

    query.clear();
    query.exec("SELECT [FULL NAME], [ADDRESS], [TEL NO] FROM [REFERENCES] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString fullName = query.value(0).toString();
        QString addr = query.value(1).toString();
        QString telNo = query.value(2).toString();

        addReference(fullName, addr, telNo);
    }

    query.clear();
    query.exec("SELECT [Q36A], [Q36A DET], [Q36B], [Q36B DET], [Q37A], [Q37A DET], [Q37B], [Q37B DET], [Q38], [Q38 DET], [Q39], [Q39 DET], "
               "[Q40], [Q40 DET], [Q41A], [Q41A DET], [Q41B], [Q41B DET], [Q41C], [Q41C DET] FROM [OTHER INFO I] where "
               "[EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        bool q36a = query.value(0).toBool();
        QString q36adet = query.value(1).toString();
        bool q36b = query.value(2).toBool();
        QString q36bdet = query.value(3).toString();
        bool q37a = query.value(4).toBool();
        QString q37adet = query.value(5).toString();
        bool q37b = query.value(6).toBool();
        QString q37bdet = query.value(7).toString();
        bool q38a = query.value(8).toBool();
        QString q38adet = query.value(9).toString();
        bool q39a = query.value(10).toBool();
        QString q39adet = query.value(11).toString();
        bool q40a = query.value(12).toBool();
        QString q40adet = query.value(13).toString();
        bool q41a = query.value(14).toBool();
        QString q41adet = query.value(15).toString();
        bool q41b = query.value(16).toBool();
        QString q41bdet = query.value(17).toString();
        bool q41c = query.value(18).toBool();
        QString q41cdet = query.value(19).toString();

        if (q36a){
            ui->question1AYesCB->setChecked(true);
            ui->question1ATextEdit->setDisabled(false);
            ui->question1ATextEdit->setText(q36adet);
        }
        else {
            ui->question1ANoCB->setChecked(true);
            ui->question1ATextEdit->setDisabled(true);
        }
        if (q36b){
            ui->question1BYesCB->setChecked(true);
            ui->question1BTextEdit->setDisabled(false);
            ui->question1BTextEdit->setText(q36bdet);
        }
        else {
            ui->question1BNoCB->setChecked(true);
            ui->question1BTextEdit->setDisabled(true);
        }
        if (q37a){
            ui->question2AYesCB->setChecked(true);
            ui->question2ATextEdit->setDisabled(false);
            ui->question2ATextEdit->setText(q37adet);
        }
        else {
            ui->question2ANoCB->setChecked(true);
            ui->question2ATextEdit->setDisabled(true);
        }
        if (q37b){
            ui->question2BYesCB->setChecked(true);
            ui->question2BTextEdit->setDisabled(false);
            ui->question2BTextEdit->setText(q37bdet);
        }
        else {
            ui->question2BNoCB->setChecked(true);
            ui->question2BTextEdit->setDisabled(true);
        }
        if (q38a){
            ui->question3AYesCB->setChecked(true);
            ui->question3ATextEdit->setDisabled(false);
            ui->question3ATextEdit->setText(q38adet);
        }
        else {
            ui->question3ANoCB->setChecked(true);
            ui->question3ATextEdit->setDisabled(true);
        }
        if (q39a){
            ui->question4AYesCB->setChecked(true);
            ui->question4ATextEdit->setDisabled(false);
            ui->question4ATextEdit->setText(q39adet);
        }
        else {
            ui->question4ANoCB->setChecked(true);
            ui->question4ATextEdit->setDisabled(true);
        }
        if (q40a){
            ui->question5AYesCB->setChecked(true);
            ui->question5ATextEdit->setDisabled(false);
            ui->question5ATextEdit->setText(q40adet);
        }
        else {
            ui->question5ANoCB->setChecked(true);
            ui->question5ATextEdit->setDisabled(true);
        }
        if (q41a){
            ui->question6AYesCB->setChecked(true);
            ui->question6ATextEdit->setDisabled(false);
            ui->question6ATextEdit->setText(q41adet);
        }
        else {
            ui->question6ANoCB->setChecked(true);
            ui->question6ATextEdit->setDisabled(true);
        }
        if (q41b){
            ui->question6BYesCB->setChecked(true);
            ui->question6BTextEdit->setDisabled(false);
            ui->question6BTextEdit->setText(q41bdet);
        }
        else {
            ui->question6BNoCB->setChecked(true);
            ui->question6BTextEdit->setDisabled(true);
        }
        if (q41c){
            ui->question6CYesCB->setChecked(true);
            ui->question6CTextEdit->setDisabled(false);
            ui->question6CTextEdit->setText(q41cdet);
        }
        else {
            ui->question6CNoCB->setChecked(true);
            ui->question6CTextEdit->setDisabled(true);
        }
    }

    query.clear();
    query.exec("SELECT [COMM TAX NO], [ISSUED AT], [ISSUED ON], [DATE ACCOMP] FROM [OTHER INFO II] where [EMPLOYEE ID] = '" + employeeID + "'");
    while (query.next()) {
        QString commTaxNo = query.value(0).toString();
        QString issuedAt = query.value(1).toString();
        QString issuedOn = query.value(2).toString();
        QString dateAccomp = query.value(3).toString();

        ui->commTaxNoEdit->setText(commTaxNo);
        ui->issuedAtEdit->setText(issuedAt);
        ui->issuedOnEdit->setDate(QDate::fromString(issuedOn));
        ui->dateAccomplishEdit->setDate(QDate::fromString(dateAccomp));
    }
}

void NewEmployee::clearAll()
{
    ui->scrollArea->verticalScrollBar()->setValue(ui->scrollArea->verticalScrollBar()->minimum());
    ui->scrollArea->horizontalScrollBar()->setValue(ui->scrollArea->horizontalScrollBar()->minimum());

    ui->firstnameedit->clear();
    ui->middlenameedit->clear();
    ui->lastnameedit->clear();
    ui->nameextedit->clear();
    ui->birthdateEdit->setDate(QDate::currentDate());
    ui->placeOfBirthEdit->clear();
    ui->maleCB->setChecked(false);
    ui->femaleCB->setChecked(false);
    ui->singleCB->setChecked(false);
    ui->marriedCB->setChecked(false);
    ui->annulledCB->setChecked(false);
    ui->widowedCB->setChecked(false);
    ui->separatedCB->setChecked(false);
    ui->otherCStatusCB->setChecked(false);
    ui->otherCStatusEdit->clear();
    ui->citizenshipEdit->clear();

    float meters = 0;
    float feet = 3.28f * meters;
    float fractpart, intpart;
    fractpart = modf(feet , &intpart);
    float feetToInch = fractpart * 12;
    ui->feetEdit->setText(QString::number(intpart));
    ui->inchEdit->setText(QString::number(feetToInch));

    ui->weightEdit->clear();
    ui->bloodTypeEdit->clear();
    ui->gsisNoEdit->clear();
    ui->pagibigNoEdit->clear();
    ui->philhealthNoEdit->clear();
    ui->sssNoEdit->clear();
    ui->residentAddrEdit->clear();
    ui->zipCodeResAddrEdit->clear();
    ui->telNoResAddrEdit->clear();
    ui->permAddrEdit->clear();
    ui->zipCodePermAddrEdit->clear();
    ui->telNoPermAddrEdit->clear();
    ui->emailEdit->clear();
    ui->cellNoEdit->clear();
    ui->agencyNoEdit->clear();
    ui->tinNoEdit->clear();

    while (totalSpouses > 0) on_deleteSpouseB_clicked();

    ui->fatherFirstNameEdit->clear();
    ui->fatherMiddleNameEdit->clear();
    ui->fatherSurnameEdit->clear();
    ui->motherFirstNameEdit->clear();
    ui->motherMiddleNameEdit->clear();
    ui->motherSurnameEdit->clear();

    while (totalChildren > 0) on_deleteChild_clicked();
    while (totalEduBg > 0) on_deleteEduBg_clicked();
    while (totalCivilService > 0) on_deleteCivilServ_clicked();
    while (totalServiceRecord > 0) on_deleteServiceRecord_clicked();
    while (totalVoluntaryWork > 0) on_deleteVWorkB_clicked();
    while (totalTrainingProg > 0) on_deleteTrainingProgramB_clicked();
    while (totalSkills > 0) on_deleteSkillHobbyB_clicked();
    while (totalNonAcademicRec > 0) on_deleteNonAcademicRecB_clicked();
    while (totalOrgMembership > 0) on_deleteOrgMembership_clicked();

    ui->question1AYesCB->setChecked(false);
    ui->question1ANoCB->setChecked(false);
    ui->question1ATextEdit->clear();
    ui->question1BYesCB->setChecked(false);
    ui->question1BNoCB->setChecked(false);
    ui->question1BTextEdit->clear();
    ui->question2AYesCB->setChecked(false);
    ui->question2ANoCB->setChecked(false);
    ui->question2ATextEdit->clear();
    ui->question2BYesCB->setChecked(false);
    ui->question2BNoCB->setChecked(false);
    ui->question2BTextEdit->clear();
    ui->question3AYesCB->setChecked(false);
    ui->question3ANoCB->setChecked(false);
    ui->question3ATextEdit->clear();
    ui->question4AYesCB->setChecked(false);
    ui->question4ANoCB->setChecked(false);
    ui->question4ATextEdit->clear();
    ui->question5AYesCB->setChecked(false);
    ui->question5ANoCB->setChecked(false);
    ui->question5ATextEdit->clear();
    ui->question6AYesCB->setChecked(false);
    ui->question6ANoCB->setChecked(false);
    ui->question6ATextEdit->clear();
    ui->question6BYesCB->setChecked(false);
    ui->question6BNoCB->setChecked(false);
    ui->question6BTextEdit->clear();
    ui->question6CYesCB->setChecked(false);
    ui->question6CNoCB->setChecked(false);
    ui->question6CTextEdit->clear();

    while (totalReferences > 0) on_deleteReferenceB_clicked();

    ui->commTaxNoEdit->clear();
    ui->issuedAtEdit->clear();
    ui->issuedOnEdit->setDate(QDate::currentDate());
    ui->dateAccomplishEdit->setDate(QDate::currentDate());
}


PresentDateData::PresentDateData()
{

}

PresentDateData::PresentDateData(QDateEdit *&dateEdit, QCheckBox *&checkBox)
{
    this->dateEdit = dateEdit;
    this->checkBox = checkBox;
}

void NewEmployee::on_backB_clicked()
{
    clearAll();
    if (mode == 0){
        stackWidget->setCurrentIndex(5);
    }
    else if (mode == 1){

    }
    else if (mode == 2){
        ViewEmployees *viewEmployees = (ViewEmployees*)(stackWidget->widget(4));
        viewEmployees->updateView();
        stackWidget->setCurrentIndex(5);
    }
}
