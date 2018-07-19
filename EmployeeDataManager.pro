#-------------------------------------------------
#
# Project created by QtCreator 2017-04-07T13:06:19
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += xlsx

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RC_FILE = myapp.rc

TARGET = EmployeeDataManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    employeemanagerhome.cpp \
    newemployee.cpp \
    customqtui.cpp \
    utils.cpp \
    viewemployees.cpp \
    plantillapersonnel.cpp \
    plantillacasual.cpp \
    numplantillavacpos.cpp \
    boolquery.cpp \
    viewplantillapersonnels.cpp \
    viewplantillacasualappt.cpp \
    customquery.cpp \
    enterpassword.cpp

HEADERS  += mainwindow.h \
    employeemanagerhome.h \
    newemployee.h \
    customqtui.h \
    utils.h \
    viewemployees.h \
    plantillapersonnel.h \
    plantillacasual.h \
    numplantillavacpos.h \
    boolquery.h \
    viewplantillapersonnels.h \
    viewplantillacasualappt.h \
    customquery.h \
    enterpassword.h

FORMS    += mainwindow.ui \
    employeemanagerhome.ui \
    newemployee.ui \
    viewemployees.ui \
    plantillapersonnel.ui \
    plantillacasual.ui \
    numplantillavacpos.ui \
    viewplantillapersonnels.ui \
    viewplantillacasualappt.ui \
    customquery.ui \
    enterpassword.ui

CONFIG += mobility
CONFIG += c++11
MOBILITY = 

RESOURCES += \
    resource/resource.qrc



