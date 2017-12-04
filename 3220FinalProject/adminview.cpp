#include "adminview.h"
#include "ui_adminview.h"
#include "additemwindow.h"
#include "errorhandle.h"
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

    ui->label_Error->setStyleSheet("color:red");
    int errorflag = 1, typeflag = 1;
    //Need to add error handling
    QString id = ui->lineEdit_DeleteId->text();

    AdminError AE(data);

    //--------



    try{
        //make sure it is all integer
        if(AE.typeCheck(id) == 0){
            throw 0;
        }
    }

        catch(int &d){
        typeflag = 0;

        ui->label_Error->setText("Id is not Integer");
           // qDebug() << "Id is not Integer" << endl;
          //  throw "Id is not Integer";

        }
    try{
        //make sure is not empty
        if(AE.isEmpty(id) == 0){
            throw 0;
        }
    }
        catch(int &d){
            errorflag = 0;
            ui->label_Error->setText("Item ID is empty, not able to delete");
           // qDebug() << "Item ID is empty, not able to delete" << endl;
          //  throw "Item ID is empty, not able to delete";

            }

    int ItemId = id.toInt();
    if(typeflag == 1){
        try{
            if(AE.deleteMatch(ItemId) == 0){
                throw 0;
            }
        }
            catch(int &d){
            errorflag = 0;
            ui->label_Error->setText("Unable to delete");
          //  qDebug() << "Unable to delete" << endl;
             //   throw "Unable to delete";

            }


    cout<<"correct ID is" << ItemId;
    if(errorflag == 1){
        ui->label_Error->setText("");
        QSqlQuery query;
        query.prepare("DELETE from Item Where ItemID = :ItemId");
        query.bindValue(":ItemId",ItemId);
        query.exec();

    }



}
}

void AdminView::on_pushButton_AddItem_clicked()
{

    AddItemWindow aiw;
    aiw.data = data;
    aiw.setModal(true);
    aiw.exec();
}
