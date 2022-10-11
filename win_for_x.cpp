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

void win_for_x::on_pushButton_ok_clicked()
{
//        QByteArray str = ui->x_text->toPlainText().toLocal8Bit();
//        std::string s = ui->x_text->toPlainText().toStdString();

        QString str = ui->x_text->toPlainText();
        int n = str.size();
        std::cout<<n<< std::endl;

        QString str_off = ui->x_text->toPlainText();
        bool res = false;

        double x = str_off.toDouble(&res);
        if(!str.isEmpty() && res == true){

            global::x_value = x;
            global::flag_x_value = false;

            QWidget::close();
        }
}


