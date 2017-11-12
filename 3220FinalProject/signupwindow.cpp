#include "signupwindow.h"
#include "ui_signupwindow.h"
SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_pushButton_SignUp_clicked()
{

    Pawprint = ui->lineEdit_Pawprint->text();
      Name = ui->lineEdit_Name->text();
      QString ID = ui->lineEdit_StudentID->text();
      StudentId = ID.toInt();
      Password = ui->lineEdit_Password->text();
      data->CreateUser(Pawprint,Name,StudentId,1,Password);
      hide(); // hide the main window
}
