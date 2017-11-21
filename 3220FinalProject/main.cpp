#include "mainwindow.h"
#include <QApplication>
#include "loginwindow.h"
#include "signupwindow.h"
#include "database.h"

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

void DBManager::CreateUser(const QString &Pawprint, const QString &Name, int StudentId, int UserType, const QString &Password)
{
    QSqlQuery query;
//    query.prepare("INSERT INTO User (Pawprint, Name, StudentId, UserType, Password) "
//                  "values(:Pawprint, :Name, :StudentId, :UserType, :Password)");
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

int DBManager::matchID(int StudentID)
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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBManager d1("//Users//Ben//Dropbox//3220//FP.db");

    LoginWindow lw;
    lw.data = &d1;
    lw.show();

    return a.exec();
}
