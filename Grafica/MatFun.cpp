#include "MatFun.h"
#include "MatInput.h"

#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

MatFun::MatFun(MatInput* refMat,QWidget *parent):QWidget(parent){
    QGridLayout* buttons = new QGridLayout;

    QPushButton* sqrt = new QPushButton(this);            //Rad quad
    QPushButton* pow = new QPushButton(this);             //Elev. potenza
    QPushButton* GaussJordan = new QPushButton(this);     //GaussJordan
    QPushButton* Gauss = new QPushButton(this);           //Gauss
    QPushButton* Trasp = new QPushButton(this);
    QPushButton* inv = new QPushButton(this);
    QPushButton* mul = new QPushButton(this);
    QPushButton* div = new QPushButton(this);

    QLabel* Det = new QLabel(this);
    connect(refMat,SIGNAL(UpDet(QString)),Det,SLOT(setText(QString)));
    emit refMat->UpDet(refMat->detString());

    sqrt->setText("√");
    pow->setText("x\302\262");
    GaussJordan->setText("GaussJordan");
    Gauss->setText("Gauss");
    Trasp->setText("Trasposta");
    inv->setText("Inversa");
    mul->setText("*");
    div->setText("/");

    inv->setEnabled(false);

    buttons->addWidget(Det,0,0);
    buttons->addWidget(pow,1,1);
    buttons->addWidget(sqrt,1,0);
    buttons->addWidget(GaussJordan,2,0);
    buttons->addWidget(Gauss,2,1);
    buttons->addWidget(inv,3,1);
    buttons->addWidget(Trasp,3,0);
    buttons->addWidget(mul,4,0);
    buttons->addWidget(div,4,1);


    connect(sqrt,SIGNAL(clicked()),refMat,SLOT(sqrt()));
    connect(pow,SIGNAL(clicked()),refMat,SLOT(pow()));
    connect(GaussJordan,SIGNAL(clicked()),refMat,SLOT(GaussJordan()));
    connect(Gauss,SIGNAL(clicked()),refMat,SLOT(Gauss()));
    connect(Trasp,SIGNAL(clicked()),refMat,SLOT(Trasposta()));
    connect(inv,SIGNAL(clicked()),refMat,SLOT(Inversa()));
    connect(mul,SIGNAL(clicked()),refMat,SLOT(mul()));
    connect(div,SIGNAL(clicked()),refMat,SLOT(div()));


    setLayout(buttons);
}
