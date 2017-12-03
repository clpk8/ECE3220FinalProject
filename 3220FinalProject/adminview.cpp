#include "adminview.h"
#include "ui_adminview.h"
#include "additemwindow.h"
#include "error.h"
#include "iostream"

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

    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery query1;
    query1.prepare("SELECT ItemId, ItemName, Item.Pawprint, BorrowTime, ReturnTime from Item, User where Status = 0 and Item.Pawprint = User.Pawprint");
    query1.exec();
    modal1->setQuery(query1);
    ui->BorrowedItem->setModel(modal1);
}

void AdminView::on_pushButton_Delete_clicked()
{

    int flag = 1;
    //Need to add error handling
    QString id = ui->lineEdit_DeleteId->text();

    AdminError AE(data);

    try{
        //make sure is not empty
        if(AE.isEmpty(id) == 0){
            throw 0;
        }
    }
        catch(int &d){
            flag = 0;
            qDebug() << "Item ID is empty, not able to delete" << endl;
          //  throw "Item ID is empty, not able to delete";

            }

    try{
        //make sure it is all integer
        if(AE.typeCheck(id) == 0){
            throw 0;
        }
    }

        catch(int &d){
        flag = 0;

            qDebug() << "Id is not Integer" << endl;
          //  throw "Id is not Integer";

        }

    int ItemId = id.toInt();

    try{
        if(AE.deleteMatch(ItemId) == 0){
            throw 0;
        }
    }
        catch(int &d){
        flag = 0;

            qDebug() << "Unable to delete" << endl;
         //   throw "Unable to delete";

        }
    catch(...){
        flag = 0;

        qDebug() << "catch all" << endl;

    }


    cout<<"correct ID is" << ItemId;
    if(flag == 1){
        QSqlQuery query;
        query.prepare("DELETE from Item Where ItemID = :ItemId");
        query.bindValue(":ItemId",ItemId);
        query.exec();

    }



}

void AdminView::on_pushButton_AddItem_clicked()
{


    AddItemWindow aiw;
    aiw.data = data;
    aiw.setModal(true);
    aiw.exec();
}
