#include "deposit.h"

#include "sparrvio.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) : QDialog(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
}

Deposit::~Deposit() { delete ui; }

void Deposit::on_comboBox_activated(int index) { comboBox = index; }

void Deposit::on_slider_place_valueChanged(int value) {
  ui->place_period->setText(QString::number(value));
}

void Deposit::on_cap_percen_stateChanged(int arg1) {
  if (arg1 == Qt::Checked) {
    h_cap_percent = true;
  } else {
    h_cap_percent = false;
  }
}

// void Deposit::on_slider_period_trans_valueChanged(int value)
//{
//     ui->period_trans->setText(QString::number(value));
// }

void Deposit::on_slider_sum_trans_valueChanged(int value) {
  ui->sum_trans->setText(QString::number(value));
}

void Deposit::on_out_transaction_clicked(bool checked) { out_transaction = -1; }

void Deposit::on_in_transaction_clicked(bool checked) { out_transaction = 1; }

void Deposit::on_pushButton_clicked() {
  bool res = false;
  //  std::cout << res << std::endl;
  //  std::cout << "res" << std::endl;

  QString sum_deposit = ui->sum_deposit->toPlainText();
  double d_sum_deposit = sum_deposit.toDouble(&res);

  QString place_period = ui->place_period->text();
  int i_place_period = place_period.toInt(&res);

  QString sum_transaction = ui->sum_trans->text();
  int d_sum_trans = out_transaction * sum_transaction.toDouble(&res);

  QString percen = ui->percen->toPlainText();
  double d_percen = percen.toDouble();

  QString tax = ui->tax->toPlainText();
  double d_tax = tax.toDouble();

  QString period_trans = ui->period_trans->text();
  int i_period_trans = period_trans.toInt(&res);

  double sum_dep = sum_deposit.toDouble(&res);

  double out_sum_end = 0;
  double out_sum_tax = 0;
  double out_percent = 0;
  type_d period_pay;
  type_d cap_percen;

  if (comboBox == 0) {
    period_pay = pay_every_day;
  } else if (comboBox == 1) {
    period_pay = pay_every_year;
  } else if (comboBox == 2) {
    period_pay = pay_at_the_end;
  }

  if (h_cap_percent == true) {
    cap_percen = cap_yes;
  } else if (h_cap_percent == false) {
    cap_percen = cap_no;
  }

  // int deposit_calc(double sum, int day, double interest_rate, double
  // tax_rate,
  //                  type_d period_pay, type_d cap_percen, int transaction,
  //                  double sum_transaction, double* sum_end, double* sum_tax,
  //                  double* percen);
  if (period_pay == pay_every_year && i_place_period < 365) {
    res = false;
  }

  if (res == true) {
    deposit_calc(d_sum_deposit, i_place_period, d_percen, d_tax, period_pay,
                 cap_percen, i_period_trans, d_sum_trans, &out_sum_end,
                 &out_sum_tax, &out_percent);

    QString str_out_sum;
    str_out_sum = QString::number(out_sum_end, 'g', 12);
    QString str_sum_tax;
    str_sum_tax = QString::number(out_sum_tax, 'g', 12);
    QString str_percent;
    str_percent = QString::number(out_percent, 'g', 12);

    //  std::cout << d_sum_deposit << std::endl;
    //  std::cout << i_place_period << std::endl;
    //  std::cout << d_percen << std::endl;
    //  std::cout << d_tax << std::endl;
    //  std::cout << period_pay << std::endl;
    //  std::cout << cap_percen << std::endl;
    //  std::cout << d_sum_trans << std::endl;
    //  std::cout << i_period_trans << std::endl;

    ui->out_sum->clear();
    ui->out_tax->clear();
    ui->out_percen->clear();

    ui->out_sum->setText(str_out_sum);
    ui->out_tax->setText(str_sum_tax);
    ui->out_percen->setText(str_percent);
  } else {
    ui->out_sum->setText("INCORRECT INPUT");
    ui->out_tax->setText("INCORRECT INPUT");
    ui->out_percen->setText("INCORRECT INPUT");
  }
}

void Deposit::on_Exit_clicked() { QWidget::close(); }

void Deposit::on_period_trans_valueChanged(int arg1) {}
