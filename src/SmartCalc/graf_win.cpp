#include "graf_win.h"

#include "sparrvio.h"
#include "src/s21_SmartCalc.h"
#include "ui_graf_win.h"

graf_win::graf_win(QWidget *parent) : QDialog(parent), ui(new Ui::graf_win) {
  ui->setupUi(this);
}

graf_win::~graf_win() { delete ui; }

void graf_win::on_pushButton_Exit_clicked() { QWidget::close(); }

void graf_win::on_pushButton_Push_clicked() {
  ui->step->setEnabled(false);

  double x_from;
  double x_before;
  double step;
  bool err = x_correct(&x_from, &x_before, &step);
  if (err == true) {
    //        step = 100;
    //        xBegin = -3;
    //        xEnd = 3 + step;

    xBegin = x_from;
    xEnd = x_before + step;

    ui->widget->xAxis->setRange(x_from, x_before);
    ui->widget->yAxis->setRange(-50, 50);

    N = (xEnd - xBegin) / step + 2;
//    double x_in = global::x_value;

    QString input = global::str_for_graf;
    std::string str_pp = input.toStdString();
    char *cstr = new char[str_pp.length() + 1];

    strcpy(cstr, str_pp.c_str());

    double check = 0.0;
    int err = 0;

    for (X = xBegin; X <= xEnd; X += step) {
      err = my_main(cstr, &check, X);
      x.push_back(X);
      y.push_back(check);
    }
    //        ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
  } else {
    ui->domain_x_from->clear();
    ui->domain_x_before->clear();
    ui->step->clear();
  }
}

int graf_win::x_correct(double *x_from, double *x_before, double *step) {
  bool ret = true;

  QString str_domain_x_from = ui->domain_x_from->toPlainText();
  QString str_domain_x_beforer = ui->domain_x_before->toPlainText();
  QString str_step = ui->step->toPlainText();

  bool res_1 = false;
  bool res_2 = false;
  bool res_3 = false;

  double x_1 = str_domain_x_from.toDouble(&res_1);
  double x_2 = str_domain_x_beforer.toDouble(&res_2);
  double d_step = str_step.toDouble(&res_3);

  std::cout << x_1 << std::endl;
  std::cout << x_2 << std::endl;
  std::cout << d_step << std::endl;

  if (res_1 == false || res_2 == false || res_3 == false) {
    ret = false;
  }

  if (x_1 > 10000000 || x_2 > 10000000) {
    ret = false;
  }

  if (x_1 >= x_2) {
    ret = false;
  }

  if (ret == true) {
    *x_from = x_1;
    *x_before = x_2;
    *step = d_step;
  }

  return ret;
}
