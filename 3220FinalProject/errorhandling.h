#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H
#include <string>
#include <iostream>
#include <QCoreApplication>
#include "database.h"
using namespace std;

class ErrorHandling
{

public:
    ErrorHandling();
    ~ErrorHandling();
    void display();
  //  virtual int match() = 0;
  //  virtual int rangeCheck () = 0;
//    int isEmpty(QString str); //first check if anything is empty
//    int typeCheck (QString str);

protected:
    string msg;
    DBManager *d1;



};


#endif // ERRORHANDLING_H
