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

private slots:
    void on_pushButton_clicked();
    void digits_number();

    void on_pushButton_Exit_clicked();

private:
    Ui::CreditCalc *ui;
    Ui::CreditCalc *creditcalc;

};

#endif // CREDITCALC_H
