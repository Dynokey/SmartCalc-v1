#include "graf_win.h"
#include "ui_graf_win.h"
#include "sparrvio.h"

graf_win::graf_win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graf_win)
{
    ui->setupUi(this);
}

graf_win::~graf_win()
{
    delete ui;
}
