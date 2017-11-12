#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "database.h"
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{

    Q_OBJECT

public:
    QString Username;
    QString Password;
    DBManager *data;
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_Signup_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
