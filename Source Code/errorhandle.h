#ifndef ERRORHANDLE_H
#define ERRORHANDLE_H
#include <string>
#include <iostream>
#include <QCoreApplication>
#include "database.h"

class ErrorHandle
{
	public:
		ErrorHandle(DBManager *db);
		ErrorHandle();
		~ErrorHandle();
		int isEmpty(QString str);
		int typeCheck(QString str);
		int checkIdExist(int ID);
		int checkIdExist(int ItemID, QString Pawprint);
		int checkoutCheck(int ItemID);
        virtual void errorMessage(QString str);
        QString msg;
	protected:
		DBManager *d1;
};


class AdminError : public ErrorHandle {
	private:
		int itemId;
		double BorrowLength;
	public:
		AdminError(DBManager *d1);
		AdminError();
		~AdminError();
		int checkBorrowLength(QString time); //grab a QString, convert it to int then check
		int deleteMatch(int id);
		int addMatch(int id);
        virtual void errorMessage(QString str);
};

#endif // ERRORHANDLE_H
