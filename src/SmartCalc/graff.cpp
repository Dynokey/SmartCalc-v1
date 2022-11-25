#include "graff.h"

#include "sparrvio.h"
#include "ui_graff.h"

Graff::Graff(QWidget *parent) : QDialog(parent), ui(new Ui::Graff) {
  ui->setupUi(this);
}

Graff::~Graff() { delete ui; }
