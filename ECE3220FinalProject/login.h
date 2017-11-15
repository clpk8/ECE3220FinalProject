#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    int IfClose();
    explicit Login(QWidget *parent = 0);
    ~Login();
     int close=0;

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_signup_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
