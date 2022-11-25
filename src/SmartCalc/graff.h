#ifndef GRAFF_H
#define GRAFF_H

#include <QDialog>

namespace Ui {
class Graff;
}

class Graff : public QDialog
{
    Q_OBJECT

public:
    explicit Graff(QWidget *parent = nullptr);
    ~Graff();

private:
    Ui::Graff *ui;
};

#endif // GRAFF_H
