#ifndef ERROR_H
#define ERROR_H
#include <string>
#include <iostream>
#include <QCoreApplication>
#include "database.h"

class Error
{
public:
    Error(DBManager *db);
    Error();
    ~Error();
    virtual void display() = 0;
    int isEmpty(QString str);
    int typeCheck(QString str);

protected:
    string msg;
    DBManager *d1;

};


class AdminError : public Error {
private:
    int itemId;
    double BorrowLength;
public:
    AdminError(DBManager *d1);
    AdminError();
    ~AdminError();
    void display();
    int checkBorrowLength(QString time); //grab a QString, convert it to int then check
    int deleteMatch(int id);
    int addMatch(int id);

};


#endif // ERROR_H
