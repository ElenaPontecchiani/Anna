#include "maincalc.h"
#include "matrice_input.h"
#include "../Parte_Logica/matrix.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>

MainCalc::MainCalc(QWidget *parent) : QWidget(parent)
{
    QWidget* w = new Matrice_Input(4,5);
    QWidget* y = new Matrice_Input(5,4);

    princ = dynamic_cast<Matrice_Input*>(w);
    aux = dynamic_cast<Matrice_Input*>(y);

    QPushButton* p = new QPushButton("Somma",this);
    QHBoxLayout* b = new QHBoxLayout();
    b->addWidget(w);
    b->addWidget(p);
    b->addWidget(y);

    connect(p,SIGNAL(released()),this,SLOT(somma()));

    setLayout(b);
};


void MainCalc::somma(){
    *(princ->getMat()) = *(princ->getMat()) + *(aux->getMat());
    princ->upMat();
}
