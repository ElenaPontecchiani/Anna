#include "tastiera.h"
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "matrice_input.h"
#include <QLineEdit>

Tastiera::Tastiera(Matrice_Input* mm,QWidget *parent) :mi(mm), QWidget(parent)
{

    QVBoxLayout* final = new QVBoxLayout(this);
    QGridLayout* gridel = new QGridLayout();
    QGridLayout* gridin = new QGridLayout();
    QGridLayout* gridvt = new QGridLayout();

    QPushButton* trasp = new QPushButton("Trasposta",this);
    QPushButton* gauss = new QPushButton("Gauss",this);
    QPushButton* gaussj = new QPushButton("Gauss Jordan",this);
    QPushButton* radx = new QPushButton("RadX",this);
    QPushButton* powx = new QPushButton("Potenza X",this);
    QPushButton* inv = new QPushButton("Inversa",this);
    QPushButton* norm = new QPushButton("Norma Euclidea",this);

    gridel->addWidget(radx,0,0);    gridel->addWidget(powx,0,1);

    gridin->addWidget(trasp,0,0);  gridin->addWidget(gauss,0,1);
    gridin->addWidget(gaussj,1,0); gridin->addWidget(inv,1,1);

    gridvt->addWidget(norm,0,0);


    connect(trasp,SIGNAL(released()),mm,SLOT(trasposta()));
    connect(gauss,SIGNAL(released()),mm,SLOT(gauss()));
    connect(gaussj,SIGNAL(released()),mm,SLOT(gaussJordan()));
    connect(radx,SIGNAL(released()),this,SLOT(sendRad()));
    connect(powx,SIGNAL(released()),this,SLOT(sendPow()));
    connect(inv,SIGNAL(released()),mm,SLOT(inv()));
    connect(norm,SIGNAL(released()),mm,SLOT(norm()));

    connect(this,SIGNAL(powX(double)),mm,SLOT(powX(double)));
    connect(this,SIGNAL(radX(double)),mm,SLOT(radX(double)));

    QLabel* elem = new QLabel("Operazioni sui singoli elementi");
    QLabel* inte = new QLabel("Operazioni sull'intera matrice");
    QLabel* vett = new QLabel("Operazioni su vettori");

    QHBoxLayout* xcont = new QHBoxLayout();
    QLabel* xlabel = new QLabel("Valore X ",this);
    x = new QLineEdit("0",this);
    x->setValidator(new QDoubleValidator(x));
    xcont->addWidget(xlabel);
    xcont->addWidget(x);

    final->addWidget(elem);
    final->addLayout(gridel);
    final->addLayout(xcont);
    final->addWidget(inte);
    final->addLayout(gridin);
    final->addWidget(vett);
    final->addLayout(gridvt);
    setLayout(final);
}


void Tastiera::sendRad(){
    emit radX(x->text().toDouble());
}

void Tastiera::sendPow(){
    emit powX(x->text().toDouble());
}



