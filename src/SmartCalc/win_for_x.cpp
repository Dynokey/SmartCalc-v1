
#include "win_for_x.h"

#include "ui_win_for_x.h"

extern "C" {
#include "src/s21_SmartCalc.h"
}

win_for_x::win_for_x(QWidget* parent) : QDialog(parent), ui(new Ui::win_for_x) {
  ui->setupUi(this);
}

win_for_x::~win_for_x() { delete ui; }

void win_for_x::on_pushButton_ok_clicked() {
  QString str = ui->x_text->toPlainText();

  QString str_off = ui->x_text->toPlainText();
  bool res = false;

  double x = str_off.toDouble(&res);

  if (!str.isEmpty() && res == true) {
    global::x_value = x;
    global::flag_x_value = false;

    QWidget::close();
  }
}

void win_for_x::on_pushButton_AC_clicked() {
  ui->x_text->clear();
  global::flag_x_value = true;
  ui->result_x->clear();
}

void win_for_x::on_pushButton_eq_clicked() {
  QString str_eq = ui->x_text->toPlainText();

  bool res = false;

  double x = str_eq.toDouble(&res);

  double check;

  if (!str_eq.isEmpty() && res == true) {
    global::x_value = x;
    global::flag_x_value = false;

    std::string str_global = global::str_for_x_eq.toStdString();
    char* cstr = new char[str_global.length() + 1];

    strcpy(cstr, str_global.c_str());

    int err = 0;

    err = my_main(cstr, &check, global::x_value);

    std::string res_str(cstr);

    if (err == 0) {
      QString num_to_str;
      num_to_str = QString::number(check, 'g', 12);
      ui->result_x->setText(num_to_str);

      delete[] cstr;
    } else {
      ui->result_x->clear();
      ui->result_x->setText("ERROR");
    }
    global::x_value = 0.0;
    global::flag_x_value = false;

  } else {
    ui->result_x->clear();
    ui->result_x->setText("ERROR");
  }
}
