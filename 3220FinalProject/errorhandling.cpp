#include "errorhandling.h"
#include <cctype>

//int ErrorHandling::isEmpty(QString str){

//    if(str.isEmpty() == true){
//        return 0; //it is empty, return a 0
//    }
//    else{
//        return 1; // is not empty
//    }
//}

//int ErrorHandling::typeCheck(QString str){
//    bool ok;
//    int value = str.toInt(&ok);
//    if(!ok){
//        return 0; //which means it is not integer
//    }
//    else{
//        return 1; //no trash characters in the str
//    }
//}
//int AdminError::deleteMatch(int ID){
//    QSqlQuery query;
//    query.prepare("SELECT ItemId FROM Item WHERE Status = 1 and ItemId = (:ItemId)");
//    query.bindValue(":ItemId",ID);
//    if(query.exec())
//    {
//        if(query.next())
//        {
//            //you can delete
//            return 1;
//        }
//    }
//    else
//    {
//        //no deleting
//        return 0;
//    }
//}

//int AdminError::addMatch(int ID){
//    QSqlQuery query;
//    query.prepare("SELECT ItemId FROM Item WHERE ItemId = (:ItemId)");
//    query.bindValue(":ItemId",ID);
//    if(query.exec())
//    {
//        if(query.next())
//        {
//            //you cant add, return 0 for false
//            return 0;
//        }
//    }
//    else
//    {
//        //you CAN add
//        return 1;
//    }
//}




//int AdminError::checkBorrowLength(QString time){
//    BorrowLength = time.toDouble();
//    if(BorrowLength <= 60){
//        //enter a greater value
//        return 0;
//    }
//    else{
//        //right time
//        return 1;
//    }


//}
