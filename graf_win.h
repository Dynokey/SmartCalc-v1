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

private:
    Ui::graf_win *ui;
};

#endif // GRAF_WIN_H
