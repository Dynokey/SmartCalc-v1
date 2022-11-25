#include "creditcalc.h"

#include "sparrvio.h"
#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget* parent)
    : QDialog(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);

  ui->disp_sum->setText("0");
  ui->disp_deadline->setText("0");
  ui->disp_percent->setText("0");

  //    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_number()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_number()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_number()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_number()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_number()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_number()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_number()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_number()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_number()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_number()));
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::digits_number() {
  if (flag == true) {
    //        ui->disp_sum->clear();
    //        ui->disp_deadline->clear();
    //        ui->disp_percent->clear();
    ui->gen_sum->clear();
    ui->over_pay->clear();
    ui->pay_mounth->clear();
    flag = false;
  }

  QPushButton* button = (QPushButton*)sender();

  double all_numbers;

  QString label;

  if (sum == true && deadline == false && percent == false) {
    all_numbers = (ui->disp_sum->text() + button->text()).toDouble();

    label = QString::number(all_numbers, 'g', 12);

    ui->disp_sum->setText(label);

  } else if (sum == false && deadline == true && percent == false) {
    all_numbers = (ui->disp_deadline->text() + button->text()).toDouble();

    label = QString::number(all_numbers, 'g', 12);

    ui->disp_deadline->setText(label);

  } else if (sum == false && deadline == false && percent == true) {
    all_numbers = (ui->disp_percent->text() + button->text()).toDouble();

    label = QString::number(all_numbers, 'g', 12);

    ui->disp_percent->setText(label);
  }
}

void CreditCalc::on_pushButton_Calc_clicked() {
  flag = true;

  QString input_sum = ui->disp_sum->text();
  std::string str_sum = input_sum.toStdString();
  char* cstr_sum = new char[str_sum.length() + 1];
  strcpy(cstr_sum, str_sum.c_str());

  QString input_deadline = ui->disp_deadline->text();
  std::string str_deadline = input_deadline.toStdString();
  char* cstr_deadline = new char[str_deadline.length() + 1];
  strcpy(cstr_deadline, str_deadline.c_str());

  QString input_percent = ui->disp_percent->text();
  std::string str_percent = input_percent.toStdString();
  char* cstr_percent = new char[str_percent.length() + 1];
  strcpy(cstr_percent, str_percent.c_str());

  double gen_sum = 0.0;
  double over_pay = 0.0;
  double pay_min = 0.0;
  double pay_max = 0.0;

  if (diff == true) {
    int res_diff = credit_calc_diff(cstr_sum, cstr_deadline, cstr_percent,
                                    &gen_sum, &over_pay, &pay_min, &pay_max);
    if (res_diff == 0) {
      QString num_gen_sum;
      num_gen_sum = QString::number(gen_sum, 'g', 12);

      QString num_over_pay;
      num_over_pay = QString::number(over_pay, 'g', 12);

      QString num_pay_min;
      num_pay_min = QString::number(pay_min, 'g', 12);

      QString num_pay_max;
      num_pay_max = QString::number(pay_max, 'g', 12);

      ui->gen_sum->setText(num_gen_sum);
      ui->over_pay->setText(num_over_pay);
      ui->pay_mounth->setText(num_pay_max);
      ui->pay_mounth->setText(ui->pay_mounth->text() + "... ..." + num_pay_min);
    } else {
      ui->gen_sum->setText("INCORRECT INPUT");
      ui->over_pay->setText("INCORRECT INPUT");
      ui->pay_mounth->setText("INCORRECT INPUT");
    }

  } else if (ann == true) {
    int res_ann = credit_calc_ann(cstr_sum, cstr_deadline, cstr_percent,
                                  &gen_sum, &over_pay, &pay_min);
    if (res_ann == 0) {
      QString num_gen_sum;
      num_gen_sum = QString::number(gen_sum, 'g', 12);

      QString num_over_pay;
      num_over_pay = QString::number(over_pay, 'g', 12);

      QString num_pay_min;
      num_pay_min = QString::number(pay_min, 'g', 12);

      ui->gen_sum->setText(num_gen_sum);
      ui->over_pay->setText(num_over_pay);
      ui->pay_mounth->setText(num_pay_min);
    } else {
      ui->gen_sum->setText("INCORRECT INPUT");
      ui->over_pay->setText("INCORRECT INPUT");
      ui->pay_mounth->setText("INCORRECT INPUT");
    }
  }

  delete[] cstr_sum;
  delete[] cstr_deadline;
  delete[] cstr_percent;
}

void CreditCalc::on_radio_sum_clicked(bool checked) {
  sum = true;
  deadline = false;
  percent = false;
}

void CreditCalc::on_radio_deadline_clicked(bool checked) {
  sum = false;
  deadline = true;
  percent = false;
}

void CreditCalc::on_radio_percent_clicked(bool checked) {
  sum = false;
  deadline = false;
  percent = true;
}

void CreditCalc::on_pushButton_BackSpace_clicked() {
  if (sum == true) {
    QString text = ui->disp_sum->text();
    text.chop(1);

    if (text.isEmpty()) {
      text = "0";
    }
    ui->disp_sum->setText(text);

  } else if (deadline == true) {
    QString text = ui->disp_deadline->text();
    text.chop(1);

    if (text.isEmpty()) {
      text = "0";
    }
    ui->disp_deadline->setText(text);

  } else if (percent == true) {
    QString text = ui->disp_percent->text();
    text.chop(1);

    if (text.isEmpty()) {
      text = "0";
    }
    ui->disp_percent->setText(text);
  }
}

void CreditCalc::on_pushButton_t_clicked() {
  if (sum == true) {
    if (!(ui->disp_sum->text().contains('.')))
      ui->disp_sum->setText(ui->disp_sum->text() + ".");

  } else if (deadline == true) {
    ui->disp_deadline->setText(ui->disp_deadline->text());

  } else if (percent == true) {
    if (!(ui->disp_percent->text().contains('.')))
      ui->disp_percent->setText(ui->disp_percent->text() + ".");
  }
}

void CreditCalc::on_radio_ann_pay_clicked(bool checked) {
  diff = false;
  ann = true;
}

void CreditCalc::on_radio_diff_pay_clicked(bool checked) {
  ann = false;
  diff = true;
}

void CreditCalc::on_pushButton_Clear_clicked() {
  ui->disp_sum->clear();
  ui->disp_deadline->clear();
  ui->disp_percent->clear();
  ui->gen_sum->clear();
  ui->over_pay->clear();
  ui->pay_mounth->clear();

  ui->disp_sum->setText("0");
  ui->disp_deadline->setText("0");
  ui->disp_percent->setText("0");
  ui->gen_sum->setText("0");
  ui->over_pay->setText("0");
  ui->pay_mounth->setText("0");
}

void CreditCalc::on_pushButton_0_clicked() {
  if (sum == true) {
    if (ui->disp_sum->text().endsWith("0") &&
        ui->disp_sum->text().size() == 1) {
      ui->disp_sum->setText("0");

    } else {
      ui->disp_sum->setText(ui->disp_sum->text() + "0");
    }

  } else if (deadline == true) {
    if (ui->disp_deadline->text().endsWith("0") &&
        ui->disp_deadline->text().size() == 1) {
      ui->disp_deadline->setText("0");

    } else {
      ui->disp_deadline->setText(ui->disp_deadline->text() + "0");
    }

  } else if (percent == true) {
    if (ui->disp_percent->text().endsWith("0") &&
        ui->disp_percent->text().size() == 1) {
      ui->disp_percent->setText("0");

    } else {
      ui->disp_percent->setText(ui->disp_percent->text() + "0");
    }
  }
}
