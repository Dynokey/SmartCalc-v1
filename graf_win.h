#ifndef GRAF_WIN_H
#define GRAF_WIN_H

#include <QDialog>

namespace Ui {
class graf_win;
}

class graf_win : public QDialog
{
    Q_OBJECT

public:
    explicit graf_win(QWidget *parent = nullptr);
    ~graf_win();

private slots:
    void on_pushButton_Exit_clicked();

    void on_pushButton_Push_clicked();

    int x_correct(double* x_from, double* x_before);

private:
    Ui::graf_win *ui;

    double xBegin, xEnd, h, X;
    int N;

    QVector<double> x, y;
};

#endif // GRAF_WIN_H
