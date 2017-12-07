#include "sendmail.h"

SendMail::SendMail(DBManager *db)
{
    d1 = db;
}

void SendMail::run(){
        //declear some Query statments
        QSqlQuery query;//query to select time
        QSqlQuery query1;//query to select pawprint
        QSqlQuery query2;//query to select ItemName
        QSqlQuery query3;//query to select BorrowTime
        QSqlQuery query4;//query to select ReturnTime

        //vector to store informations, they are matched bt index
        vector <int> TimeList;
        vector <string> PawPrintList;
        vector <string> ItemNameList;
        vector <string> BorrowTimeList;
        vector <string> ReturnTimeList;
        vector <bool> MailFlagList;

        //never stop looping
        while(1){
            unsigned long i = 0;
            //reset the vectors everytime to store new values
            TimeList.clear();
            PawPrintList.clear();
            ItemNameList.clear();
            BorrowTimeList.clear();
            ReturnTimeList.clear();
            //MailFlagList.clear();

            //query to get informations
            query.exec("SELECT julianday(ReturnTime)*1440 - julianday('now','localtime')*1440 From Item where Status = 0;");
            query1.exec("SELECT PawPrint from Item where Status = 0;");
            query2.exec("SELECT ItemName from Item where Status = 0;");
            query3.exec("SELECT BorrowTime from Item where Status = 0;");
            query4.exec("SELECT ReturnTime from Item where Status = 0;");

            while(query.next()){
                int time = query.value(0).toInt();
                TimeList.push_back(time);
                MailFlagList.push_back(false);
            }
            while(query1.next()){
                QString PawPrint = query1.value(0).toString();
                PawPrintList.push_back(PawPrint.toStdString());
            }
            while(query2.next()){
                QString ItemName = query2.value(0).toString();
                ItemNameList.push_back(ItemName.toStdString());
            }
            while(query3.next()){
                QString BorrowTime = query3.value(0).toString();
                BorrowTimeList.push_back(BorrowTime.toStdString());
            }
            while(query4.next()){
                QString ReturnTime = query4.value(0).toString();
                ReturnTimeList.push_back(ReturnTime.toStdString());
                for(int j = 0; j < TimeList.size();j++){
                    if(TimeList[j] <= 60 && MailFlagList[j] == true){
                        MailFlagList[j] = true;
                     }
                else{
                    MailFlagList[j] = false;
                }
            }
          }
            //check all the item in vectors
            while( i < TimeList.size()){
                //pause a little bit
                usleep(10000);

                //send email if 60mins away from return time, and flag to makesure it dont send infinite emails
                if(TimeList[i] <= 60 && MailFlagList[i] == false){

                    //concanation to write email command
                    string SentMailCommand = "echo \" Dear Student, \n  You have borrwed " + ItemNameList[i]
                            + " in " + BorrowTimeList[i] +  ". It has to be returned by " + ReturnTimeList[i] +  ", Please return it in time to avoid charge.\nMizzou Checkout\""
                              " | mail -s \"Item return notice\" \" " + PawPrintList[i] + "@mail.missouri.edu\"";

                    //send mail through terminal, using QProcess to call
                    QProcess *process = new QProcess;
                    const char *SentMailCommandInChar = SentMailCommand.c_str();

                    //start bash(terminal in MAC)
                    process->start("bash", QStringList() << "-c" <<  SentMailCommandInChar);
                    //set flag once perticular index was send
                    MailFlagList[i] = true;

                }
                i++;

            }
        }
}

