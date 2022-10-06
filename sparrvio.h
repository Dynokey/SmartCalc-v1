#ifndef SPARRVIO_H
#define SPARRVIO_H

#include <QMainWindow>
#include <iostream>
#include <creditcalc.h>
//#include <form.h>

extern "C" {
#include "src/s21_SmartCalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class sparrvio; }
QT_END_NAMESPACE

class sparrvio : public QMainWindow
{
    Q_OBJECT

public:
    sparrvio(QWidget *parent = nullptr);
    ~sparrvio();
    int flag = 0;

private:
    Ui::sparrvio *ui;
    CreditCalc win_credit;


private slots:
    void press_button();
    void on_pushButton_ON_clicked();
    void on_pushButton_eq_clicked();
//    void on_pushButton_t_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_tan_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_OFF_clicked();
    void on_pushButton_asin_clicked();
    void on_pushButton_acos_clicked();
    void on_pushButton_atan_clicked();
    void on_pushButton_mod_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_scale_clicked();
    void on_pushButton_BackSpace_clicked();

    void on_pushButtonCredit_clicked();
};
#endif // SPARRVIO_H
