/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTableView *AvaliableItem;
    QLabel *label_2;
    QTableView *BorrowedItem;
    QLabel *label_img;
    QLabel *label_Error;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_ItemId;
    QPushButton *pushButton_CheckOut;
    QPushButton *pushButton_Return;
    QPushButton *pushButton_Load;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(719, 629);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 241, 21));
        AvaliableItem = new QTableView(centralWidget);
        AvaliableItem->setObjectName(QStringLiteral("AvaliableItem"));
        AvaliableItem->setGeometry(QRect(10, 30, 351, 231));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 270, 231, 16));
        BorrowedItem = new QTableView(centralWidget);
        BorrowedItem->setObjectName(QStringLiteral("BorrowedItem"));
        BorrowedItem->setGeometry(QRect(10, 290, 351, 271));
        label_img = new QLabel(centralWidget);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setGeometry(QRect(410, 80, 221, 121));
        label_Error = new QLabel(centralWidget);
        label_Error->setObjectName(QStringLiteral("label_Error"));
        label_Error->setGeometry(QRect(430, 510, 221, 16));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(440, 371, 194, 134));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_ItemId = new QLineEdit(widget);
        lineEdit_ItemId->setObjectName(QStringLiteral("lineEdit_ItemId"));

        horizontalLayout->addWidget(lineEdit_ItemId);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_CheckOut = new QPushButton(widget);
        pushButton_CheckOut->setObjectName(QStringLiteral("pushButton_CheckOut"));

        verticalLayout->addWidget(pushButton_CheckOut);

        pushButton_Return = new QPushButton(widget);
        pushButton_Return->setObjectName(QStringLiteral("pushButton_Return"));

        verticalLayout->addWidget(pushButton_Return);

        pushButton_Load = new QPushButton(widget);
        pushButton_Load->setObjectName(QStringLiteral("pushButton_Load"));

        verticalLayout->addWidget(pushButton_Load);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 719, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "List of avaliable item", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Borrowed Item", nullptr));
        label_img->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_Error->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Item ID:", nullptr));
        pushButton_CheckOut->setText(QApplication::translate("MainWindow", "Checkout", nullptr));
        pushButton_Return->setText(QApplication::translate("MainWindow", "Return", nullptr));
        pushButton_Load->setText(QApplication::translate("MainWindow", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
