#include "sendmail.h"
#include <QtCore>

SendMail::SendMail(QObject *parent) : QThread(parent)
{

}

void SendMail::run(){

    QSqlQuery query;

    query.prepare("SELECT julianday('now','localtime')*1440 - julianday(BorrowTime)*1440 From Item where ItemId = 100001;"");



}
