#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_Load_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ItemId, ItemName, Location from Item Where Status = 1");
    query.exec();
    modal->setQuery(query);
    ui->AvaliableItem->setModel(modal);
    QSqlQuery query1;
    query1.prepare("SELECT ItemId, ItemName, Location from Item Where Status = 0 and Pawprint = :Pawprint");
    query1.bindValue(":Pawprint",Pawprint);
    query1.exec();
    modal1->setQuery(query1);
    ui->BorrowedItem->setModel(modal1);


}

void MainWindow::on_pushButton_CheckOut_clicked()
{
    //Need to add error handling
    QString id = ui->lineEdit_ItemId->text();
    int ItemId = id.toInt();
   // cout<<"correct ID is" << ItemId;
    QSqlQuery query;
    query.prepare("UPDATE Item set Status = 0, Pawprint = :Pawprint, BorrowTime = datetime('now', 'localtime'), ReturnTime = datetime('now','localtime','+' || BorrowLength || ' minutes') where ItemId = :ItemId");
    query.bindValue(":ItemId",ItemId);
    query.bindValue(":Pawprint",Pawprint);
    query.exec();
}

void MainWindow::on_pushButton_Return_clicked()
{
    //Need to add error handling
    QString id = ui->lineEdit_ItemId->text();
    int ItemId = id.toInt();
   // cout<<"correct ID is" << ItemId;
    QSqlQuery query;
    query.prepare("UPDATE Item set Status = 1, Pawprint = NULL where ItemId = :ItemId");
    query.bindValue(":ItemId",ItemId);
    query.exec();

}
