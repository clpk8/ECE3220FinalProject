#include "additemwindow.h"
#include "ui_additemwindow.h"
#include "errorhandle.h"

AddItemWindow::AddItemWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemWindow)
{
    ui->setupUi(this);
}

AddItemWindow::~AddItemWindow()
{
    delete ui;
}

void AddItemWindow::on_pushButton_Add_clicked()
{
    //set color of error message
    ui->label_Error->setStyleSheet("color:red");


    AdminError AE(data);
    int errorflag = 1, typeflag = 1;
    QString ItemId1 = ui->lineEdit_ItemId->text();
    QString BorrowLength1 = ui->lineEdit_BorrowLength->text();


    ItemName = ui->lineEdit_Name->text();
    Location = ui->lineEdit_Location->text();


    try{
        if(AE.typeCheck(BorrowLength1) == 0 || AE.typeCheck(ItemId1) == 0){
            throw 0;
        }
    }
    catch(int &d){
        typeflag = 0;
        ui->label_Error->setText("BorrowLength or ItemId is not int");
       // qDebug() << "BorrowLength or ItemId is not int";

    }


    try{
        if(AE.isEmpty(ItemId1) == 0 || AE.isEmpty(BorrowLength1) == 0 || AE.isEmpty(ItemName) == 0 || AE.isEmpty(Location) == 0){
            throw 0;
        }
    }
    catch(int &d){
        errorflag = 0;
        ui->label_Error->setText("Something is empty");
       // qDebug() << "Something is empty";
    }

    if(typeflag == 1){
        BorrowLength = BorrowLength1.toDouble();
        ItemId = ItemId1.toInt();
        try{
            if(AE.checkBorrowLength(BorrowLength1) == 0){
                throw 0;
            }

        }
        catch(int &d){
            errorflag = 0;
            ui->label_Error->setText( "Borrowlength has to be between 60 mins and 30 days");

           // qDebug() << "Borrowlength has to be between 60mins and 30 days";
        }
        try{
            if(AE.addMatch(ItemId) == 0){
                throw 0;
            }
        }
        catch(int &d){
            errorflag = 0;
            ui->label_Error->setText( "ItemId is already Exist! ");

        //    qDebug() << "ItemId is already Exist! ";
        }




        if(errorflag == 1){
            ui->label_Error->setText( "");
            data->InsertItem(ItemId, ItemName, Location, BorrowLength);
            hide();
        }
    }



}
