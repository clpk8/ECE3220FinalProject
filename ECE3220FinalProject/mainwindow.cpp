#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "secdialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DBManager d1("//Users//Ben//USER.db");
    Pawprint = ui->lineEdit_Pawprint->text();
    Name = ui->lineEdit_Name->text();
    QString ID = ui->lineEdit_ID->text();
    StudentId = ID.toInt();
    Password = ui->lineEdit_Password->text();
    d1.CreateUser(Pawprint,Name,StudentId,1,Password);
    hide(); // hide the main window
    SecDialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();//show dialog
}
