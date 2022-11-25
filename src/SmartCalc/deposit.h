#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "QtWidgets/qslider.h"
#include <QDialog>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();
    //! определение входящая трансакция или исходящая
    int out_transaction = 1;
    //! капитализация процентов да/нет
    bool h_cap_percent = false;
    //! выбор периода выплат
    int comboBox = 0;

private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_slider_place_valueChanged(int value);

    void on_cap_percen_stateChanged(int arg1);

//    void on_slider_period_trans_valueChanged(int value);

    void on_slider_sum_trans_valueChanged(int value);


    void on_out_transaction_clicked(bool checked);

    void on_in_transaction_clicked(bool checked);

    void on_Exit_clicked();

    void on_period_trans_valueChanged(int arg1);

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H
