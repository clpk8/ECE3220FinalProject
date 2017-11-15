#include "MainWindow.h"
#include <QApplication>
#include <login.h>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    l.show();


    return a.exec();

}
