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

    //create ERROR object with database
    ErrorHandle *E = new ErrorHandle(data);
    AdminError AE(data);
    E = &AE;
	int errorflag = 1, typeflag = 1;

    //read values from user interface(ui)
	QString ItemId1 = ui->lineEdit_ItemId->text();
	QString BorrowLength1 = ui->lineEdit_BorrowLength->text();
	ItemName = ui->lineEdit_Name->text();
	Location = ui->lineEdit_Location->text();

    //try block to check type
	try{
		if(AE.typeCheck(BorrowLength1) == 0 || AE.typeCheck(ItemId1) == 0){
			throw 0;
		}
	}

	catch(int &d){
		typeflag = 0;
        QString error = "BorrowLength or ItemId is not int";
        E->errorMessage(error);
        ui->label_Error->setText(E->msg);
	}

    //try block to check empty
	try{
		if(AE.isEmpty(ItemId1) == 0 || AE.isEmpty(BorrowLength1) == 0 || AE.isEmpty(ItemName) == 0 || AE.isEmpty(Location) == 0){
			throw 0;
		}
	}

	catch(int &d){
		errorflag = 0;
        QString error = "Something is empty";
        E->errorMessage(error);
        ui->label_Error->setText(E->msg);
	}

    //only if type is integer
	if(typeflag == 1){
		BorrowLength = BorrowLength1.toDouble();
		ItemId = ItemId1.toInt();

        //try block to make sure borrowlendght is valid
		try{
			if(AE.checkBorrowLength(BorrowLength1) == 0){
				throw 0;
			}
		}

		catch(int &d){
			errorflag = 0;
            QString error = "Borrowlength has to be between 60 mins and 30 days";
            E->errorMessage(error);
            ui->label_Error->setText(E->msg);
		}

        //try block to make sure adding a valid ID
		try{
			if(AE.addMatch(ItemId) == 0){
				throw 0;
			}
		}

		catch(int &d){
			errorflag = 0;
            QString error =  "ItemId is already Exist! ";
            E->errorMessage(error);
            ui->label_Error->setText(E->msg);
		}

        //only if no error found
		if(errorflag == 1){
            //clean the error tab
            ui->label_Error->setText("");
            //insert into database
			data->InsertItem(ItemId, ItemName, Location, BorrowLength);
			hide();
		}
	}
}
