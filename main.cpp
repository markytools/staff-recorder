#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.addLibraryPath("D:/Documents/QT/OJT Projects/EmployeeDataManager/thirdparty/");
    MainWindow w;
    w.show();

    return a.exec();
}
