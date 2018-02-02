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
    QPushButton* diff = new QPushButton("Differenza",this);
    QPushButton* molt = new QPushButton("Moltiplicazione",this);
    QPushButton* copy = new QPushButton("<- Copia <-",this);

    connect(copy,SIGNAL(released()),this,SLOT(copy()));
    connect(somma,SIGNAL(released()),this,SLOT(somma()));
    connect(diff,SIGNAL(released()),this,SLOT(diff()));
    connect(molt,SIGNAL(released()),this,SLOT(molt()));


    tasti->addWidget(copy);
    tasti->addWidget(somma);
    tasti->addWidget(molt);
    tasti->addWidget(diff);

    QHBoxLayout* b = new QHBoxLayout();
    b->addWidget(w);
    b->addLayout(tasti);
    b->addWidget(y);


    setLayout(b);
};


void MainCalc::somma(){
    if((*(princ->getMat())).sameDim(*(aux->getMat()))){
        *(princ->getMat()) = *(princ->getMat()) + *(aux->getMat());
        princ->upMat();
    }
    else
        Matrice_Input::warning("Non puoi sommare due matrici con dimensioni diverse");
}

void MainCalc::diff(){
    if((*(princ->getMat())).sameDim(*(aux->getMat()))){
        *(princ->getMat()) = *(princ->getMat()) - *(aux->getMat());
        princ->upMat();
    }
    else
        Matrice_Input::warning("Non puoi fare la differnza fra due matrici con dimensioni diverse");
}

void MainCalc::molt(){
    if((princ->getMat())->isMultBy(*(aux->getMat()))){
        *(princ->getMat()) = (*(princ->getMat())) * (*(aux->getMat()));
        matrix<double> cp = *(princ->getMat());
        princ->newMat(princ->getMat()->getH(),princ->getMat()->getL());
        *(princ->getMat()) = cp;
        princ->upMat();
    }
    else
        Matrice_Input::warning("L'altezza dalla prima matrice deve essere "
                "uguale alla lunghezza della seconda");
}

void MainCalc::copy(){
    princ->newMat((*(aux->getMat())).getH(),(*(aux->getMat())).getL());
    *(princ->getMat()) = *(aux->getMat());
    princ->upMat();

}




