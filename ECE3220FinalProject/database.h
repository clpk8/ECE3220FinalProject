#ifndef DATABASE_H
#define DATABASE_H
#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>


#include <iostream>
using namespace std;
class DBManager
{
public:
    DBManager(const QString& path);
    void CreateUser(const QString& Pawprint,const QString& Name,
                    int StudentId, int UserType,
                    const QString& Password);

private:
    QSqlDatabase m_db;
};
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



#endif // DATABASE_H
