#include "sparrvio.h"
#include "./ui_sparrvio.h"
#include "src/s21_SmartCalc.h"


//double num_first;

sparrvio::sparrvio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sparrvio)

{
    ui->setupUi(this);
    connect(ui->pushButton_t,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_brL,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_brR,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_ON,SIGNAL(clicked()),this,SLOT(on_pushButton_ON_clicked()));
//    connect(ui->pushButton_sign,SIGNAL(clicked()),this,SLOT(press_button()));
//    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(press_button()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(press_button()));
//    connect(ui->pushButton_equal,SIGNAL(clicked()),this,SLOT(on_pushButton_equal_clicked()));
}

sparrvio::~sparrvio()

{
    delete ui;

}


void sparrvio::press_button()

{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }
    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText(button->text());
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + button->text());
        }
    }
}

void sparrvio::on_pushButton_ON_clicked()

{
    ui->pushButton_t->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->result->setText("0");
}


void sparrvio::on_pushButton_eq_clicked()
{
    flag = 1;
    QString input = ui->result->text();
    std::string str_pp = input.toStdString();
    char* cstr = new char[str_pp.length() + 1];

    strcpy(cstr, str_pp.c_str());
    double check = 0.0;
    int err = 0;
    err = my_main(cstr, &check);
    std::cout<<check<< std::endl;
    std::cout<<err<< std::endl;

    std::string res_str(cstr);

    if(err == 0){
        QString num_to_str;
        num_to_str = QString::number(check, 'g', 12);
        ui->result->setText(num_to_str);
        delete [] cstr;
    } else {
        ui->result->clear();
        ui->result->setText("Incorrect Input");
    }


}


//void sparrvio::on_pushButton_t_clicked()
//{
//        if(!(ui->result->text().contains('.')))

//        ui->result->setText(ui->result->text() + ".");

//}


void sparrvio::on_pushButton_sin_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }
    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("sin(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "sin(");
        }
    }

}


void sparrvio::on_pushButton_cos_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }
    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("cos(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "cos(");
        }
    }
}


void sparrvio::on_pushButton_tan_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("tan(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "tan(");
        }
    }
}


void sparrvio::on_pushButton_sqrt_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("sqrt(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "sqrt(");
        }
    }
}


void sparrvio::on_pushButton_asin_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("asin(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "asin(");
        }
    }
}


void sparrvio::on_pushButton_acos_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("acos(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "acos(");
        }
    }
}


void sparrvio::on_pushButton_atan_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("atan(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "atan(");
        }
    }
}


void sparrvio::on_pushButton_mod_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("%");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "%");
        }
    }
}


void sparrvio::on_pushButton_log_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("log(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "log(");
        }
    }
}


void sparrvio::on_pushButton_ln_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("l_n(");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "l_n(");
        }
    }
}


void sparrvio::on_pushButton_scale_clicked()
{
    if(flag != 0){
        ui->result->clear();
        flag = 0;
    }

    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText("^");
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + "^");
        }
    }
}


void sparrvio::on_pushButton_OFF_clicked()
{
    QApplication::quit();
}

void sparrvio::on_pushButton_BackSpace_clicked()
{
    QString text = ui->result->text();
    text.chop(1);

    if(text.isEmpty()){
        text = "0";
    }
    ui->result->setText(text);
}


void sparrvio::on_pushButtonCredit_clicked()
{
    win_credit.show();
}

