#include "mainwindow.h"
#include <QApplication>
#include "loginwindow.h"
#include "signupwindow.h"
#include "database.h"

//Database constructor
DBManager::DBManager(const QString& path)
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName(path);

	if (!m_db.open())
	{
		qDebug() << "Error: connection with database fail";
	}
	else
	{
		qDebug() << "Database: connection ok";
	}
}

//enroll a new user to our system
void DBManager::CreateUser(const QString &Pawprint, const QString &Name, const int StudentId, const int UserType, const QString &Password)
{
	QSqlQuery query;
    query.prepare("UPDATE User SET Pawprint = :Pawprint, Name = :Name, UserType = :UserType, Password = :Password WHERE StudentId = :StudentId");

	query.bindValue(":Pawprint", Pawprint);
	query.bindValue(":Name", Name);
	query.bindValue(":StudentId", StudentId);
	query.bindValue(":UserType", UserType);
	query.bindValue(":Password", Password);

	if(query.exec())
	{
		cout<<"insert success!!"<<endl;
	}
	else
	{
		qDebug()<<"error" << query.lastError();
	}
}

//check to make sure valid information
int DBManager::check(const QString &Pawprint, const QString &Password)
{
	QSqlQuery query;
	query.prepare("SELECT Pawprint, Password FROM User WHERE Pawprint = (:Pawprint)"
			"and Password = (:Password)");
	query.bindValue(":Pawprint",Pawprint);
	query.bindValue(":Password",Password);
	if(query.exec())
	{
		if(query.next())
		{
			cout<<"logged in"<<endl;
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

//check StudentId was enrolled in our class
int DBManager::check(int StudentID)
{
	QSqlQuery query;
	query.prepare("SELECT StudentId FROM User WHERE StudentId = (:StudentId)");
	query.bindValue(":StudentId",StudentID);

	if(query.exec())
	{
		if(query.next())
		{
			cout<<"ID matched."<<endl;
			return 1;
		}
	}
	else
	{
		return -1;
	}
}

//get the type, 0 is Admin, 1 is regualr user
int DBManager::getUserType(QString PawPrint){
	int ID = 0;//if is admin
	QSqlQuery query;
	query.prepare("SELECT UserType FROM User WHERE UserType = (:UserType) AND PawPrint = (:PawPrint)");
	query.bindValue(":UserType",ID);
	query.bindValue(":PawPrint",PawPrint);

	if(query.exec())
	{
		if(query.next())
		{
			cout<<"Admin found."<<endl;
			return 0;
		}
	}
	else
	{
		return 1;
	}
}

//inser a new item
void DBManager::InsertItem(const int ItemId, const QString &ItemName, const QString &Location, const int BorrowLength){

	QSqlQuery query;
	query.prepare("INSERT INTO Item (ItemId, ItemName, Status, Location, BorrowLength) "
			"values(:ItemId, :ItemName, :Status, :Location, :BorrowLength)");

	query.bindValue(":ItemId", ItemId);
	query.bindValue(":ItemName", ItemName);
	query.bindValue(":Status", 1);
	query.bindValue(":Location", Location);
	query.bindValue(":BorrowLength", BorrowLength);

	if(query.exec())
	{
		cout<<"insert Item success!!"<<endl;
	}
	else
	{
		qDebug()<<"error" << query.lastError();
	}

}
int DBManager::ifOpen(){
    if(m_db.isOpen()){
        return 1;
    }
    else{
        return 0;
    }
}

//main function begin
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    //create a DBManager class with my local database file
    QString str = QCoreApplication::applicationDirPath() + "//FP.db";
    qDebug() << str;
    DBManager d1(str);
        //first create login window
        LoginWindow lw;
        lw.setWindowTitle("Login");
        lw.data = &d1;
        lw.show();



	return a.exec();
}
