#include "maincalc.h"
#include "matrice_input.h"
#include "../Parte_Logica/matrix.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

MainCalc::MainCalc(QWidget *parent) : QWidget(parent)
{
    QWidget* w = new Matrice_Input(4,5);
    QWidget* y = new Matrice_Input(5,4);

    princ = dynamic_cast<Matrice_Input*>(w);
    aux = dynamic_cast<Matrice_Input*>(y);

    QVBoxLayout* tasti = new QVBoxLayout();

    QPushButton* somma = new QPushButton("Somma",this);
    QPushButton* molt = new QPushButton("Moltiplicazione",this);

    connect(somma,SIGNAL(released()),this,SLOT(somma()));
    connect(molt,SIGNAL(released()),this,SLOT(molt()));


    tasti->addWidget(somma);
    tasti->addWidget(molt);

    QHBoxLayout* b = new QHBoxLayout();
    b->addWidget(w);
    b->addLayout(tasti);
    b->addWidget(y);


    setLayout(b);
};


void MainCalc::somma(){
    *(princ->getMat()) = *(princ->getMat()) + *(aux->getMat());
    princ->upMat();
}

void MainCalc::molt(){
    *(princ->getMat()) = (*(princ->getMat())) * (*(aux->getMat()));
    matrix<double> cp = *(princ->getMat());
    princ->newMat(princ->getMat()->getH(),princ->getMat()->getL());
    *(princ->getMat()) = cp;

    princ->upMat();
}
