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

void graf_win::on_pushButton_Exit_clicked()
{
     QApplication::quit();
}


void graf_win::on_pushButton_Push_clicked()
{
    double x_from;
    double x_before;
    bool err = x_correct(&x_from, &x_before);
    if(err == true){

        h = 0.1;
        xBegin = -3;
        xEnd = 3 + h;

        ui->widget->xAxis->setRange(x_from, x_before);
        ui->widget->yAxis->setRange(x_from, x_before);

        N = (xEnd - xBegin) / h + 2;

        for(X = xBegin; X <= xEnd; X += h){
            x.push_back(X);
            y.push_back(X*X);
        }

        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x, y);
        ui->widget->replot();
    } else {
        ui->domain_x_from->clear();
        ui->domain_x_before->clear();
    }

}

int graf_win::x_correct(double* x_from, double* x_before){
    bool ret = true;

    QString str_domain_x_from = ui->domain_x_from->toPlainText();
    QString str_domain_x_beforer = ui->domain_x_before->toPlainText();

    bool res_1 = false;
    bool res_2 = false;

    double x_1 = str_domain_x_from.toDouble(&res_1);
    double x_2 = str_domain_x_beforer.toDouble(&res_2);

    if(x_1 == false || x_2 == false){
        ret = false;
    }
    if(x_1 > 10000000 || x_2 > 10000000){
        ret = false;
    }

    if(x_1 >= x_2){
        ret = false;
    }
    if(ret == true){
        *x_from = x_1;
        *x_before = x_2;
    }

    return ret;
}
