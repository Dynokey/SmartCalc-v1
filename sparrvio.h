#ifndef SPARRVIO_H
#define SPARRVIO_H

#include <QMainWindow>
#include <iostream>


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

private:
    Ui::sparrvio *ui;

private slots:
    void press_button();
    void on_pushButton_ON_clicked();
//    void digits_numbers();
//    void on_action_2_triggered();
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
    void on_pushButton_AC_clicked();
    void on_pushButton_OFF_2_toggled(bool checked);
};
#endif // SPARRVIO_H
