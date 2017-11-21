#include "adminview.h"
#include "ui_adminview.h"
#include "additemwindow.h"

AdminView::AdminView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminView)
{
    ui->setupUi(this);
}

AdminView::~AdminView()
{
    delete ui;
}

void AdminView::on_pushButton_LoadTable_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ItemId, ItemName, Location from Item Where Status = 1");
    query.exec();
    modal->setQuery(query);
    ui->ItemTable->setModel(modal);




}

void AdminView::on_pushButton_Delete_clicked()
{
    //Need to add error handling
    QString id = ui->lineEdit_DeleteId->text();
    int ItemId = id.toInt();
    cout<<"correct ID is" << ItemId;
    QSqlQuery query;
    query.prepare("DELETE from Item Where ItemID = :ItemId");
    query.bindValue(":ItemId",ItemId);
    query.exec();
}

void AdminView::on_pushButton_AddItem_clicked()
{

    AddItemWindow aiw;
    aiw.data = data;
    aiw.setModal(true);
    aiw.exec();
}
