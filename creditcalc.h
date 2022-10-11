#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QDialog>


namespace Ui {
class CreditCalc;
}

class CreditCalc : public QDialog
{
    Q_OBJECT

public:
    explicit CreditCalc(QWidget *parent = nullptr);
    ~CreditCalc();
    bool sum = false;
    bool deadline = false;
    bool percent = false;
    bool ann = false;
    bool diff = false;
    bool flag = false;

private slots:

    void digits_number();

    void on_radio_sum_clicked(bool checked);

    void on_radio_deadline_clicked(bool checked);

    void on_radio_percent_clicked(bool checked);

    void on_pushButton_BackSpace_clicked();

    void on_pushButton_t_clicked();

    void on_pushButton_Calc_clicked();

    void on_radio_ann_pay_clicked(bool checked);

    void on_radio_diff_pay_clicked(bool checked);

    void on_pushButton_Clear_clicked();

    void on_pushButton_0_clicked();

private:
    Ui::CreditCalc *ui;
    Ui::CreditCalc *creditcalc;

};

#endif // CREDITCALC_H
