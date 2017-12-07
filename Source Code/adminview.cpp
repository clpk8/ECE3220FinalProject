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
    QString str = QCoreApplication::applicationDirPath() + "/mu.png";
    qDebug () <<str;
    QPixmap pix(str);
    ui->label_img->setPixmap(pix);
}

AdminView::~AdminView()
{
	delete ui;
}

void AdminView::on_pushButton_LoadTable_clicked()
{
    //loading infomations to a table view
	QSqlQueryModel * modal = new QSqlQueryModel();
	QSqlQuery query;
	query.prepare("SELECT ItemId, ItemName, Location from Item Where Status = 1");
	query.exec();
	modal->setQuery(query);
	ui->ItemTable->setModel(modal);

    QSqlQuery query2;
    query2.prepare("SELECT * from Item where Status = 0");
    if(query2.exec())
    {

           QSqlQueryModel * modal1 = new QSqlQueryModel();
           QSqlQuery query1;
           query1.prepare("SELECT ItemId, ItemName, Item.Pawprint, BorrowTime, ReturnTime from Item, User where Status = 0 and Item.Pawprint = User.Pawprint");
           if(query1.exec()){
               modal1->setQuery(query1);
               ui->BorrowedItem->setModel(modal1);

        }
    }
}

void AdminView::on_pushButton_Delete_clicked()
{
    //error classes
    ErrorHandle *E = new ErrorHandle(data);
    AdminError AE(data);
    E = &AE;

    //Set error message to red
	ui->label_Error->setStyleSheet("color:red");
	int errorflag = 1, typeflag = 1;
    //read values from UI
	QString id = ui->lineEdit_DeleteId->text();
    //try block to make sure type is right
	try{
		if(AE.typeCheck(id) == 0){
			throw 0;
		}
	}

	catch(int &d){
		typeflag = 0;
        QString error = "Id is not Integer";
        E->errorMessage(error);
        ui->label_Error->setText(E->msg);
	}

    //try block to make sure it is not empty
	try{
		if(AE.isEmpty(id) == 0){
			throw 0;
		}
	}

	catch(int &d){
		errorflag = 0;
        QString error = "Item ID is empty, not able to delete";
        E->errorMessage(error);
        ui->label_Error->setText(E->msg);
	}

    //only if ID is correct
	int ItemId = id.toInt();

	if(typeflag == 1){  
        //try block to make sure delete is correct
		try{
			if(AE.deleteMatch(ItemId) == 0){
				throw 0;
			}
		}

		catch(int &d){
			errorflag = 0;
            QString error = "Unable to delete";
            E->errorMessage(error);
            ui->label_Error->setText(E->msg);
		}

		if(errorflag == 1){
            //clean label, and delete item
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
    //create an Additem window when pushButton clicked
	AddItemWindow aiw;
    aiw.setWindowTitle("Add Item");
	aiw.data = data;
	aiw.setModal(true);
	aiw.exec();
}

void AdminView::on_pushButton_Sendmail_clicked()
{
    sendmailFlag = 0;
}
