#include "sparrvio.h"
#include "./ui_sparrvio.h"
#include "s21_SmartCalc.h"

sparrvio::sparrvio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sparrvio)
{
    ui->setupUi(this);

    connect(ui -> pushButton_0,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_1,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_2,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_3,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_4,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_5,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_6,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_7,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_8,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_9,SIGNAL(clicked()), this,SLOT(digits_numbers()));
    connect(ui -> pushButton_plus,SIGNAL(clicked()), this,SLOT(digits_numbers()));
}

sparrvio::~sparrvio()
{
    delete ui;
}

//void sparrvio::digits_numbers()
//{
//    QPushButton *button = (QPushButton *)sender();

//    double numbers;
//    QString num_to_str;
//    numbers = (ui -> result -> text() + button -> text()).toDouble();
//    num_to_str = QString::number(numbers, 'g', 256);

//    ui -> result -> setText(num_to_str);
//}

void sparrvio::digits_numbers()

{
    QPushButton *button = (QPushButton *) sender();
    if (ui->result->text().endsWith("0") && ui->result->text().size() == 1) {
        ui->result->setText(button->text());
    } else {
        if (ui->result->text().endsWith("x") != 1 || button->text() != "x") {
            ui->result->setText(ui->result->text() + button->text());
        }
    }

}


void sparrvio::on_action_2_triggered()
{
    QApplication::quit();
}


void sparrvio::on_pushButton_eq_clicked()
{
//    QPushButton *button = (QPushButton *)sender();
//    double numbers;
//    QString num_to_str;
//    numbers = (ui -> result -> text() + button -> text()).toDouble();
//    num_to_str = QString::number(numbers, 'g', 256);
//    char* str(const QString & num_to_str);
//std::cout<<numbers<< std::endl;
//    int check = 0;
//    char str[256] = {')', '+', '2'};
//    check = validator(str);
//    if(check == 0)
//        std::cout<<check<< std::endl;
//    else
//        std::cout<<"false"<< std::endl;
    QString input = ui->result->text();
    std::string str1 = input.toStdString();
    char* cstr = new char[str1.length() + 1];

    strcpy(cstr, str1.c_str());
    int check = 0;
    check = validator(cstr);
    std::cout<<check<< std::endl;

    std::string res_str(cstr);

    QString label = QString::fromStdString(res_str);

    ui->result->setText(label);
//    if (check == 1)
//    free();
//    delete [] cstr;
}
