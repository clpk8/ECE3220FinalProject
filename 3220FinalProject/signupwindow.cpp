#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "errorhandle.h"
SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_Password1->setEchoMode(QLineEdit::Password);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_pushButton_SignUp_clicked()
{
    ui->label_error->setStyleSheet("color:red");


    ErrorHandle E(data);
    int flag = 1;
    Pawprint = ui->lineEdit_Pawprint->text();
    Name = ui->lineEdit_Name->text();
    Password = ui->lineEdit_Password->text();
    QString passowrd1 = ui->lineEdit_Password1->text();
    QString ID = ui->lineEdit_StudentID->text();

    try{
        if(E.isEmpty(Pawprint) == 0 || E.isEmpty(Name) == 0 || E.isEmpty(Password) == 0 || E.isEmpty(passowrd1) == 0 || E.isEmpty(ID) == 0){
            throw 0;
        }

    }
    catch(int &d){
        flag = 0;
        ui->label_error->setText("Something is empty");
    }
    StudentId = ID.toInt();

    try{
        if(E.checkIdExist(StudentId) == 0){
            throw 0;
        }
    }
    catch(int &d){
        flag = 0;
        ui->label_error->setText("ID already Exist");
    }


    if(flag == 1){

          if(Password == passowrd1 && data->check(StudentId) == 1){
              data->CreateUser(Pawprint,Name,StudentId,1,Password);
              hide();

              ui->label_error->setText("Password not match");
          }
          else{
              if(data->check(StudentId) != 1)
              {
                  ui->label_error->setText("Id not found");
                  cout <<"create user fail!"<<endl;
              }
              else if(Password != passowrd1){
                  ui->label_error->setText("Password Not match!");
                  cout <<"create user fail!"<<endl;
              }
          }
    }




}
