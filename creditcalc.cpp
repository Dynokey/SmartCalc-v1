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
    if(sum == true && deadline == false && percent == false){
        all_numbers = (ui->disp_sum->text() + button->text()).toDouble();
        label = QString::number(all_numbers, 'g', 12);
        ui->disp_sum->setText(label);
    } else if(sum == false && deadline == true && percent == false){
        all_numbers = (ui->disp_deadline->text() + button->text()).toDouble();
        label = QString::number(all_numbers, 'g', 12);
        ui->disp_deadline->setText(label);
    } else if(sum == false && deadline == false && percent == true){
        all_numbers = (ui->disp_percent->text() + button->text()).toDouble();
        label = QString::number(all_numbers, 'g', 12);
        ui->disp_percent->setText(label);
    }
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



void CreditCalc::on_radio_sum_clicked(bool checked)
{
    sum = true;
    deadline = false;
    percent = false;
}


void CreditCalc::on_radio_deadline_clicked(bool checked)
{
    sum = false;
    deadline = true;
    percent = false;
}


void CreditCalc::on_radio_percent_clicked(bool checked)
{
    sum = false;
    deadline = false;
    percent = true;
}


void CreditCalc::on_pushButton_BackSpace_clicked()
{
    if(sum == true){

        QString text = ui->disp_sum->text();
        text.chop(1);

        if(text.isEmpty()){
            text = "0";
        }
        ui->disp_sum->setText(text);

    } else if(deadline == true){

        QString text = ui->disp_deadline->text();
        text.chop(1);

        if(text.isEmpty()){
            text = "0";
        }
        ui->disp_deadline->setText(text);

    } else if(percent == true){

        QString text = ui->disp_percent->text();
        text.chop(1);

        if(text.isEmpty()){
            text = "0";
        }
        ui->disp_percent->setText(text);
    }
}


void CreditCalc::on_pushButton_t_clicked()
{

    if(sum == true){

        if(!(ui->disp_sum->text().contains('.')))

                 ui->disp_sum->setText(ui->disp_sum->text() + ".");

    } else if(deadline == true){
        if(!(ui->disp_deadline->text().contains('.')))

                 ui->disp_deadline->setText(ui->disp_deadline->text() + ".");


    } else if(percent == true){
        if(!(ui->disp_percent->text().contains('.')))

                 ui->disp_percent->setText(ui->disp_percent->text() + ".");

    }
}

