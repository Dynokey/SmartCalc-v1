#ifndef SPARRVIO_H
#define SPARRVIO_H

#include <QMainWindow>
#include <QVector>
#include <QtMath>
#include <QtWidgets/QWidget>
#include <QInputDialog>
#include <QtCharts/QValueAxis>
#include <QTextEdit>
#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <iostream>
#include "creditcalc.h"
#include "deposit.h"
#include "graf_win.h"
#include "qcustomplot.h"
#include "global.h"

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
    //! флаг нажания кнопки "="
    int flag_press_eq = 0;
    //! флаг нажатия "."
    int clicked_t = 0;
    //! счечик изменения унарного знака +/-
    int count_un_sing = 0;

private:
    Ui::sparrvio *ui;
    CreditCalc win_credit;
    Deposit *deposit;

private slots:
    void press_button();
    void on_pushButton_ON_clicked();
    void on_pushButton_eq_clicked();
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

    void on_pushButton_Credit_clicked();
    void on_pushButton_t_clicked();
    void on_pushButton_graf_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_un_sign_clicked();
    void on_pushButton_Deposit_clicked();
};
#endif // SPARRVIO_H
