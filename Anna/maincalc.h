#ifndef MAINCALC_H
#define MAINCALC_H

#include <QWidget>
#include "maincalc.h"
#include "matrice_input.h"
#include "../Parte_Logica/matrix.h"

class MainCalc : public QWidget
{
    Q_OBJECT
private:
    Matrice_Input* princ;
    Matrice_Input* aux;
public:
    explicit MainCalc(QWidget *parent = nullptr);

signals:

public slots:
    void somma();
};

#endif // MAINCALC_H
