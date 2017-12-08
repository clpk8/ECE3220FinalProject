/********************************************************************************
** Form generated from reading UI file 'additemwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMWINDOW_H
#define UI_ADDITEMWINDOW_H

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

class Ui_AddItemWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_ItemId;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_Location;
    QLineEdit *lineEdit_BorrowLength;
    QPushButton *pushButton_Add;
    QLabel *label_Error;

    void setupUi(QDialog *AddItemWindow)
    {
        if (AddItemWindow->objectName().isEmpty())
            AddItemWindow->setObjectName(QStringLiteral("AddItemWindow"));
        AddItemWindow->resize(393, 304);
        layoutWidget = new QWidget(AddItemWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 301, 151));
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

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_ItemId = new QLineEdit(layoutWidget);
        lineEdit_ItemId->setObjectName(QStringLiteral("lineEdit_ItemId"));

        verticalLayout_2->addWidget(lineEdit_ItemId);

        lineEdit_Name = new QLineEdit(layoutWidget);
        lineEdit_Name->setObjectName(QStringLiteral("lineEdit_Name"));

        verticalLayout_2->addWidget(lineEdit_Name);

        lineEdit_Location = new QLineEdit(layoutWidget);
        lineEdit_Location->setObjectName(QStringLiteral("lineEdit_Location"));

        verticalLayout_2->addWidget(lineEdit_Location);

        lineEdit_BorrowLength = new QLineEdit(layoutWidget);
        lineEdit_BorrowLength->setObjectName(QStringLiteral("lineEdit_BorrowLength"));

        verticalLayout_2->addWidget(lineEdit_BorrowLength);


        horizontalLayout->addLayout(verticalLayout_2);

        pushButton_Add = new QPushButton(AddItemWindow);
        pushButton_Add->setObjectName(QStringLiteral("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(130, 240, 113, 32));
        label_Error = new QLabel(AddItemWindow);
        label_Error->setObjectName(QStringLiteral("label_Error"));
        label_Error->setGeometry(QRect(0, 20, 391, 20));

        retranslateUi(AddItemWindow);

        QMetaObject::connectSlotsByName(AddItemWindow);
    } // setupUi

    void retranslateUi(QDialog *AddItemWindow)
    {
        AddItemWindow->setWindowTitle(QApplication::translate("AddItemWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("AddItemWindow", "Item Id:", nullptr));
        label_2->setText(QApplication::translate("AddItemWindow", "Name:", nullptr));
        label_3->setText(QApplication::translate("AddItemWindow", "Location:", nullptr));
        label_4->setText(QApplication::translate("AddItemWindow", "Borrow Length (Mins):", nullptr));
        pushButton_Add->setText(QApplication::translate("AddItemWindow", "Add", nullptr));
        label_Error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddItemWindow: public Ui_AddItemWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMWINDOW_H
