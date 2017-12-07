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
    //set working color
	ui->label_error->setStyleSheet("color:red");
    //create error handling class
    ErrorHandle *E = new ErrorHandle(data);

    int flag = 1;
    //get informations from UI
	Pawprint = ui->lineEdit_Pawprint->text();
	Name = ui->lineEdit_Name->text();
	Password = ui->lineEdit_Password->text();
	QString passowrd1 = ui->lineEdit_Password1->text();
	QString ID = ui->lineEdit_StudentID->text();

    //try block to make sure nothing is empty
	try{
        if(E->isEmpty(Pawprint) == 0 || E->isEmpty(Name) == 0 || E->isEmpty(Password) == 0 || E->isEmpty(passowrd1) == 0 || E->isEmpty(ID) == 0){
			throw 0;
		}

	}

	catch(int &d){
		flag = 0;
        QString error = "Something is empty";
        E->errorMessage(error);
        ui->label_error->setText(E->msg);
	}

	StudentId = ID.toInt();

    //try block to make sure that ID exist
	try{
        if(E->checkIdExist(StudentId) == 0){
			throw 0;
		}
	}

	catch(int &d){
		flag = 0;
        QString error = "ID already Exist";
        E->errorMessage(error);
        ui->label_error->setText(E->msg);
    }

    //only if all correct
	if(flag == 1){

        //check again if two password is correct
		if(Password == passowrd1 && data->check(StudentId) == 1){
            //create user
			data->CreateUser(Pawprint,Name,StudentId,1,Password);
            //hide it once it is success
			hide();
		}

        //Has error
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
