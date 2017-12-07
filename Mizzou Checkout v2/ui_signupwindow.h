/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

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

class Ui_SignUpWindow
{
public:
    QPushButton *pushButton_SignUp;
    QLabel *label_error;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_Pawprint;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit_Password1;
    QLineEdit *lineEdit_StudentID;

    void setupUi(QDialog *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName(QStringLiteral("SignUpWindow"));
        SignUpWindow->resize(400, 300);
        pushButton_SignUp = new QPushButton(SignUpWindow);
        pushButton_SignUp->setObjectName(QStringLiteral("pushButton_SignUp"));
        pushButton_SignUp->setGeometry(QRect(150, 240, 113, 32));
        label_error = new QLabel(SignUpWindow);
        label_error->setObjectName(QStringLiteral("label_error"));
        label_error->setGeometry(QRect(60, 31, 271, 20));
        layoutWidget = new QWidget(SignUpWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 60, 281, 151));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit_Pawprint = new QLineEdit(layoutWidget);
        lineEdit_Pawprint->setObjectName(QStringLiteral("lineEdit_Pawprint"));

        verticalLayout->addWidget(lineEdit_Pawprint);

        lineEdit_Name = new QLineEdit(layoutWidget);
        lineEdit_Name->setObjectName(QStringLiteral("lineEdit_Name"));

        verticalLayout->addWidget(lineEdit_Name);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));

        verticalLayout->addWidget(lineEdit_Password);

        lineEdit_Password1 = new QLineEdit(layoutWidget);
        lineEdit_Password1->setObjectName(QStringLiteral("lineEdit_Password1"));

        verticalLayout->addWidget(lineEdit_Password1);

        lineEdit_StudentID = new QLineEdit(layoutWidget);
        lineEdit_StudentID->setObjectName(QStringLiteral("lineEdit_StudentID"));

        verticalLayout->addWidget(lineEdit_StudentID);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QDialog *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QApplication::translate("SignUpWindow", "Dialog", nullptr));
        pushButton_SignUp->setText(QApplication::translate("SignUpWindow", "Sign Up", nullptr));
        label_error->setText(QString());
        label->setText(QApplication::translate("SignUpWindow", "Pawprint:", nullptr));
        label_2->setText(QApplication::translate("SignUpWindow", "Name:", nullptr));
        label_4->setText(QApplication::translate("SignUpWindow", "Password:", nullptr));
        label_5->setText(QApplication::translate("SignUpWindow", "Enter Password again:", nullptr));
        label_3->setText(QApplication::translate("SignUpWindow", "Swipe Student ID:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
