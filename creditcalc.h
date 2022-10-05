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

private slots:
    void on_pushButton_clicked();
    void digits_number();
    void on_pushButton_Exit_clicked();

    void on_radio_sum_clicked(bool checked);

    void on_radio_deadline_clicked(bool checked);

    void on_radio_percent_clicked(bool checked);

    void on_pushButton_BackSpace_clicked();

    void on_pushButton_t_clicked();

private:
    Ui::CreditCalc *ui;
    Ui::CreditCalc *creditcalc;

};

#endif // CREDITCALC_H
