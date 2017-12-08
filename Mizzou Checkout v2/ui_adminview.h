/********************************************************************************
** Form generated from reading UI file 'adminview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINVIEW_H
#define UI_ADMINVIEW_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminView
{
public:
    QTableView *ItemTable;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_DeleteId;
    QTableView *BorrowedItem;
    QLabel *label_Error;
    QLabel *label_img;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_LoadTable;
    QPushButton *pushButton_AddItem;
    QPushButton *pushButton_Delete;
    QPushButton *pushButton_Sendmail;

    void setupUi(QDialog *AdminView)
    {
        if (AdminView->objectName().isEmpty())
            AdminView->setObjectName(QStringLiteral("AdminView"));
        AdminView->resize(647, 689);
        ItemTable = new QTableView(AdminView);
        ItemTable->setObjectName(QStringLiteral("ItemTable"));
        ItemTable->setGeometry(QRect(70, 30, 511, 271));
        layoutWidget = new QWidget(AdminView);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 590, 182, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_DeleteId = new QLineEdit(layoutWidget);
        lineEdit_DeleteId->setObjectName(QStringLiteral("lineEdit_DeleteId"));

        horizontalLayout->addWidget(lineEdit_DeleteId);

        BorrowedItem = new QTableView(AdminView);
        BorrowedItem->setObjectName(QStringLiteral("BorrowedItem"));
        BorrowedItem->setGeometry(QRect(70, 330, 511, 251));
        label_Error = new QLabel(AdminView);
        label_Error->setObjectName(QStringLiteral("label_Error"));
        label_Error->setGeometry(QRect(110, 660, 431, 16));
        label_img = new QLabel(AdminView);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setGeometry(QRect(380, 70, 181, 191));
        label_2 = new QLabel(AdminView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 10, 191, 16));
        label_3 = new QLabel(AdminView);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 310, 131, 16));
        pushButton_LoadTable = new QPushButton(AdminView);
        pushButton_LoadTable->setObjectName(QStringLiteral("pushButton_LoadTable"));
        pushButton_LoadTable->setGeometry(QRect(220, 620, 110, 32));
        pushButton_AddItem = new QPushButton(AdminView);
        pushButton_AddItem->setObjectName(QStringLiteral("pushButton_AddItem"));
        pushButton_AddItem->setGeometry(QRect(120, 620, 97, 32));
        pushButton_Delete = new QPushButton(AdminView);
        pushButton_Delete->setObjectName(QStringLiteral("pushButton_Delete"));
        pushButton_Delete->setGeometry(QRect(330, 620, 111, 32));
        pushButton_Sendmail = new QPushButton(AdminView);
        pushButton_Sendmail->setObjectName(QStringLiteral("pushButton_Sendmail"));
        pushButton_Sendmail->setGeometry(QRect(440, 620, 113, 32));

        retranslateUi(AdminView);

        QMetaObject::connectSlotsByName(AdminView);
    } // setupUi

    void retranslateUi(QDialog *AdminView)
    {
        AdminView->setWindowTitle(QApplication::translate("AdminView", "Dialog", nullptr));
        label->setText(QApplication::translate("AdminView", "Item ID:", nullptr));
        label_Error->setText(QString());
        label_img->setText(QString());
        label_2->setText(QApplication::translate("AdminView", "Avaliable Items:", nullptr));
        label_3->setText(QApplication::translate("AdminView", "Borrowed Items:", nullptr));
        pushButton_LoadTable->setText(QApplication::translate("AdminView", "Load Table", nullptr));
        pushButton_AddItem->setText(QApplication::translate("AdminView", "Add Item", nullptr));
        pushButton_Delete->setText(QApplication::translate("AdminView", "Delete", nullptr));
        pushButton_Sendmail->setText(QApplication::translate("AdminView", "Stop SendMail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminView: public Ui_AdminView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINVIEW_H
