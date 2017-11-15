#include "login.h"
#include "ui_login.h"
#include "MainWindow.h"
#include <QApplication>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_Login_clicked()
{
    close = 1;
    hide();
    MainWindow w;
    //w.setModal
    w.show();
}

void Login::on_pushButton_signup_clicked()
{


}
