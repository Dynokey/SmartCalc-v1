#include "creditcalc.h"
#include "ui_creditcalc.h"
#include "sparrvio.h"

CreditCalc::CreditCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditCalc)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_number()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_number()));
}

CreditCalc::~CreditCalc()
{
    delete ui;
}

void CreditCalc::digits_number(){
    QPushButton *button = (QPushButton *) sender();

    double all_numbers;
    QString label;
    all_numbers = (ui->sum_credit->text() + button->text()).toDouble();
    label = QString::number(all_numbers, 'g', 12);

    ui->sum_credit->setText(label);
}

void CreditCalc::on_pushButton_clicked()
{
    CreditCalc one;
    one.show();
}


void CreditCalc::on_pushButton_Exit_clicked()
{
        QApplication::quit();
}

