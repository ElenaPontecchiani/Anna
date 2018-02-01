#include "tastiera.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "matrice_input.h"
#include <QLineEdit>

Tastiera::Tastiera(Matrice_Input* mm,QWidget *parent) :mi(mm), QWidget(parent)
{

    QVBoxLayout* final = new QVBoxLayout(this);
    QGridLayout* lay = new QGridLayout();

    QPushButton* trasp = new QPushButton("Trasposta",this);
    QPushButton* gauss = new QPushButton("Gauss",this);
    QPushButton* gaussj = new QPushButton("Gauss Jordan",this);
    QPushButton* radx = new QPushButton("RadX",this);
    QPushButton* powx = new QPushButton("Potenza X",this);
    QPushButton* inv = new QPushButton("Inversa",this);

    lay->addWidget(trasp,0,0);  lay->addWidget(gauss,0,1);
    lay->addWidget(gaussj,1,0); lay->addWidget(radx,1,1);
    lay->addWidget(powx,2,0);  lay->addWidget(inv,2,1);

    connect(trasp,SIGNAL(released()),mm,SLOT(trasposta()));
    connect(gauss,SIGNAL(released()),mm,SLOT(gauss()));
    connect(gaussj,SIGNAL(released()),mm,SLOT(gaussJordan()));
    connect(gaussj,SIGNAL(released()),mm,SLOT(gaussJordan()));
    connect(radx,SIGNAL(released()),this,SLOT(sendRad()));
    connect(powx,SIGNAL(released()),this,SLOT(sendPow()));
    connect(inv,SIGNAL(released()),mm,SLOT(inv()));

    connect(this,SIGNAL(powX(double)),mm,SLOT(powX(double)));
    connect(this,SIGNAL(radX(double)),mm,SLOT(radX(double)));

    x = new QLineEdit(this);
    x->setValidator(new QDoubleValidator(x));

    final->addLayout(lay);
    final->addWidget(x);
    setLayout(final);
}


void Tastiera::sendRad(){
    emit radX(x->text().toDouble());
}

void Tastiera::sendPow(){
    emit powX(x->text().toDouble());
}



