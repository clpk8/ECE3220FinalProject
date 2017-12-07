#ifndef SENDMAIL_H
#define SENDMAIL_H
#include <QCoreApplication>
#include "database.h"

class SendMail : public QThread
{
public:
    SendMail(DBManager *d1);
    void run();

private:
    DBManager *d1;
};

#endif // SENDMAIL_H
