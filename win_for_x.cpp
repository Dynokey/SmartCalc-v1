#include "win_for_x.h"
#include "ui_win_for_x.h"
#include "sparrvio.h"



win_for_x::win_for_x(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win_for_x)
{
    ui->setupUi(this);
}

win_for_x::~win_for_x()
{
    delete ui;
}

void win_for_x::on_pushButton_clicked()
{
//        QByteArray str = ui->x_text->toPlainText().toLocal8Bit();
//        std::string s = ui->textEdit->toPlainText().toStdString();
//        double x = ui->x_text->toPlainText().toDouble();


//         QString str = ui->x_text->text();
////         std::string res_str(str);
//         std::cout<<str<< std::endl;

//    QString input = ui->x_text->text();
//    std::string str_pp = input.toStdString();
//    char* cstr = new char[str_pp.length() + 1];

//    strcpy(cstr, str_pp.c_str());

//        std::string res_str(cstr);

        QWidget::close();
}

