#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "signupwindow.h"
#include "mainwindow.h"
#include "adminview.h"
#include "sendmail.h"

LoginWindow::LoginWindow(QWidget *parent) : QDialog(parent), ui(new Ui::LoginWindow)
{
	ui->setupUi(this);
	ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
   QString str = QCoreApplication::applicationDirPath() + "/tiger.gif";

  // QString str = "./tiger.gif";

    qDebug () <<str;
    QPixmap pix(str);
    ui->label_pic->setPixmap(pix);
}

LoginWindow::~LoginWindow()
{
	delete ui;
}

void LoginWindow::on_pushButton_Signup_clicked()
{
    //create a signup window
	SignUpWindow s;
    s.setWindowTitle("Sign-Up");
	s.data = data;
	s.setModal(true);
	s.exec();
}

void LoginWindow::on_pushButton_Login_clicked()
{
    //get the infomation from UI
	Password = ui->lineEdit_Password->text();
	Pawprint = ui->lineEdit_Pawprint->text();

    //check if valid pawprint & password
	if(data->check(Pawprint,Password) == 1)
	{
		hide();
		cout << "Password is mathched." << endl;

        //create a user window
		if(data->getUserType(Pawprint) == 1){
			MainWindow *m = new MainWindow();
            m->setWindowTitle("Tiger Checkout");
			m->data = data;
			m->Pawprint = Pawprint;
			m->setAttribute(Qt::WA_DeleteOnClose);
			m->show();
		}

        //create admin window
        else{
            //use QThread to send email in the background
            SendMail SM(data);
            SM.start();

			AdminView av;
            av.setWindowTitle("Admin");
			av.data = data;
			av.setModal(true);
			av.exec();
            if(av.sendmailFlag == 0){
                SM.terminate();
            }
		}
	}

	else
	{
        //set warning message color
		ui->label_error1->setStyleSheet("color:red");
		ui->label_error1->setText("Pawprint or Password is invalid");
		cout<<"Password is invalid."<<endl;
	}
}
