#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QDialog>
#include "database.h"

namespace Ui {
class AddItemWindow;
}

class AddItemWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemWindow(QWidget *parent = 0);
    ~AddItemWindow();
    DBManager *data;

private:
    Ui::AddItemWindow *ui;
};

#endif // ADDITEMWINDOW_H
