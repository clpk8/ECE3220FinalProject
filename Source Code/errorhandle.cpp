#include "errorhandle.h"
#include <cctype>

ErrorHandle::ErrorHandle(DBManager *db)
{
	d1 = db;

}

ErrorHandle::ErrorHandle(){

}

ErrorHandle::~ErrorHandle(){

}

AdminError::AdminError(){

}

AdminError::AdminError(DBManager *db){
	d1 = db;
}

AdminError::~AdminError(){

}

//check if empty
int ErrorHandle::isEmpty(QString str){

	if(str.isEmpty() == true){
		return 0; //it is empty, return a 0
	}
	else{
		return 1; // is not empty
	}
}

//dynamic binding display message
void ErrorHandle::errorMessage(QString str){
    this->msg = "Error: " + str;
}
void AdminError::errorMessage(QString str){
    this->msg = "Admin Error: " + str;
}

//check the type of parameters
int ErrorHandle::typeCheck(QString str){
	bool ok;
	int value = str.toInt(&ok);
	if(!ok){
		return 0; //which means it is not integer
	}
	else{
		return 1; //no trash characters in the str
	}
}

//check if the id is valid to add
int ErrorHandle::checkIdExist(int ID){
	QSqlQuery query;
	query.prepare("SELECT StudentId FROM User WHERE StudentId = (:StudentId) and Pawprint NOT NULL");
	query.bindValue(":StudentId",ID);
	if(query.exec())
	{
		if(query.next())
		{
			//you cant add
			return 0;
		}
		else
		{
			//you can add
			return 1;
		}
	}
}

//function overload, check if the item can be returned
int ErrorHandle::checkIdExist(int ItemId, QString Pawprint){
	QSqlQuery query;
	query.prepare("SELECT ItemId FROM Item WHERE ItemId = (:ItemId) and Pawprint = (:Pawprint)");
	query.bindValue(":ItemId",ItemId);
	query.bindValue(":Pawprint",Pawprint);
	if(query.exec())
	{
		if(query.next())
		{
			//corret item found
			return 1;
		}
		else
		{
			//Item cant not be returned or not found
			return 0;
		}
	}
}

//check if the item can be checked out
int ErrorHandle::checkoutCheck(int ItemID){
	QSqlQuery query;
	query.prepare("SELECT ItemId FROM Item WHERE ItemId = (:ItemId) and Status = 1");
	query.bindValue(":ItemId",ItemID);
	if(query.exec())
	{
		if(query.next())
		{
			//you can checkout
			return 1;
		}
		else
		{
			//You cannot check out
			return 0;
		}
	}
}

//check if the item can be deleted
int AdminError::deleteMatch(int ID){
	QSqlQuery query;
	query.prepare("SELECT ItemId FROM Item WHERE Status = 1 and ItemId = (:ItemId)");
	query.bindValue(":ItemId",ID);

	if(query.exec())
	{
		if(query.next())
		{
			//you can delete
			return 1;
		}
		else
		{
			//no deleting
			return 0;
		}
	}
}

//check if the item can be added
int AdminError::addMatch(int ID){
	QSqlQuery query;
	query.prepare("SELECT ItemId FROM Item WHERE ItemId = (:ItemId)");
	query.bindValue(":ItemId",ID);
	if(query.exec())
	{
		if(query.next())
		{
			//you cant add, return 0 for false
			return 0;
		}
		else
		{
			//you CAN add
			return 1;
		}
	}
}

//check the range of BorrowLength
int AdminError::checkBorrowLength(QString time){
	BorrowLength = time.toDouble();

	if(BorrowLength <= 60 || BorrowLength >= (30*1440)){
		//time between one hours and 30 days
		return 0;
	}
	else{
		//right time
		return 1;
	}
}

