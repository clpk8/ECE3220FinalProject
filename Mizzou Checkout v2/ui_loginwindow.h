/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_Pawprint;
    QLineEdit *lineEdit_Password;
    QLabel *label_error1;
    QLabel *label_pic;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_Login;
    QPushButton *pushButton_Signup;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(447, 352);
        layoutWidget = new QWidget(LoginWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 60, 231, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_Pawprint = new QLineEdit(layoutWidget);
        lineEdit_Pawprint->setObjectName(QStringLiteral("lineEdit_Pawprint"));

        verticalLayout_2->addWidget(lineEdit_Pawprint);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));

        verticalLayout_2->addWidget(lineEdit_Password);


        horizontalLayout->addLayout(verticalLayout_2);

        label_error1 = new QLabel(LoginWindow);
        label_error1->setObjectName(QStringLiteral("label_error1"));
        label_error1->setGeometry(QRect(100, 30, 231, 16));
        label_pic = new QLabel(LoginWindow);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(170, 220, 111, 111));
        layoutWidget1 = new QWidget(LoginWindow);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(170, 130, 111, 91));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_Login = new QPushButton(layoutWidget1);
        pushButton_Login->setObjectName(QStringLiteral("pushButton_Login"));

        verticalLayout_3->addWidget(pushButton_Login);

        pushButton_Signup = new QPushButton(layoutWidget1);
        pushButton_Signup->setObjectName(QStringLiteral("pushButton_Signup"));

        verticalLayout_3->addWidget(pushButton_Signup);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("LoginWindow", "Pawprint:", nullptr));
        label_2->setText(QApplication::translate("LoginWindow", "Password:", nullptr));
        label_error1->setText(QString());
        label_pic->setText(QString());
        pushButton_Login->setText(QApplication::translate("LoginWindow", "Login", nullptr));
        pushButton_Signup->setText(QApplication::translate("LoginWindow", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
