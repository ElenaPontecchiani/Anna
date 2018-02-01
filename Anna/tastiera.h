#ifndef TASTIERA_H
#define TASTIERA_H

#include <QWidget>
#include "matrice_input.h"
#include <QLineEdit>

class Matrice_Input;

class Tastiera : public QWidget
{
    Q_OBJECT
private:
    Matrice_Input* mi;
    QLineEdit* x;
public:
    explicit Tastiera(Matrice_Input* mm, QWidget *parent = nullptr);

signals:
    void trasposta();
    void gauss();
    void gaussj();
    void radX(double coeff);
    void powX(double coeff);
    void plusX(double coeff);
public slots:
};

#endif // TASTIERA_H

