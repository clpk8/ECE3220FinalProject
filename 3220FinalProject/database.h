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





#endif // DATABASE_H
