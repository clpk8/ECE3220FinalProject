#include "mainwindow.h"
#include <QApplication>
#include "loginwindow.h"
#include "signupwindow.h"
#include "database.h"

DBManager::DBManager(const QString& path){
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

void DBManager::CreateUser(const QString &Pawprint, const QString &Name, int StudentId, int UserType, const QString &Password){
    QSqlQuery query;
    query.prepare("INSERT INTO ECE3220User (Pawprint, Name, StudentId, UserType, Password) "
                  "values(:Pawprint, :Name, :StudentId, :UserType, :Password)");
    query.bindValue(":Pawprint", Pawprint);
    query.bindValue(":Name", Name);
    query.bindValue(":StudentId", StudentId);
    query.bindValue(":UserType", UserType);
    query.bindValue(":Password", Password);


    if(query.exec()){
        cout<<"insert success!!"<<endl;
    }
    else{
        qDebug()<<"error" << query.lastError();
    }
}
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    DBManager d1("//Users//Ben//Dropbox//3220//USER.db");

    LoginWindow lw;
    lw.data = &d1;
    lw.show();

    return a.exec();
}
