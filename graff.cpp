#include "graff.h"
#include "ui_graff.h"
#include "sparrvio.h"

Graff::Graff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graff)
{
    ui->setupUi(this);
}

Graff::~Graff()
{
    delete ui;
}
