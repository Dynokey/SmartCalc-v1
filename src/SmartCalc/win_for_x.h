#ifndef WIN_FOR_X_H
#define WIN_FOR_X_H

#include <QDialog>
#include "sparrvio.h"

extern "C" {
#include "src/s21_SmartCalc.h"
}

namespace Ui {
class win_for_x;
}

class win_for_x : public QDialog
{
    Q_OBJECT

public:
    explicit win_for_x(QWidget *parent = nullptr);
    ~win_for_x();

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_AC_clicked();

    void on_pushButton_eq_clicked();

private:
    Ui::win_for_x *ui;
};

#endif // WIN_FOR_X_H
