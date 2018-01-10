#include "MatFun.h"
#include "MatInput.h"

#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

MatFun::MatFun(MatInput* refMat,QWidget *parent):QWidget(parent){
    QGridLayout* buttons = new QGridLayout;

    QPushButton* sqrt = new QPushButton;            //Rad quad
    QPushButton* pow = new QPushButton;             //Elev. potenza
    QPushButton* GaussJordan = new QPushButton;     //GaussJordan
    QPushButton* Gauss = new QPushButton;           //Gauss
    QPushButton* Trasp = new QPushButton;
    QPushButton* det = new QPushButton;
    QPushButton* mul = new QPushButton;
    QPushButton* div = new QPushButton;

    sqrt->setText("√");
    pow->setText("x\302\262");
    GaussJordan->setText("GaussJordan");
    Gauss->setText("Gauss");
    Trasp->setText("Trasposta");
    det->setText("Determinante");
    mul->setText("*");
    div->setText("/");

    det->setEnabled(false);

    buttons->addWidget(pow,0,1);
    buttons->addWidget(sqrt,0,0);
    buttons->addWidget(GaussJordan,1,0);
    buttons->addWidget(Gauss,1,1);
    buttons->addWidget(Trasp,2,0);
    buttons->addWidget(mul,3,0);
    buttons->addWidget(div,3,1);
    buttons->addWidget(det,2,1);

    connect(sqrt,SIGNAL(clicked()),refMat,SLOT(sqrt()));
    connect(pow,SIGNAL(clicked()),refMat,SLOT(pow()));
    connect(GaussJordan,SIGNAL(clicked()),refMat,SLOT(GaussJordan()));
    connect(Gauss,SIGNAL(clicked()),refMat,SLOT(Gauss()));
    connect(Trasp,SIGNAL(clicked()),refMat,SLOT(Trasposta()));
    connect(det,SIGNAL(clicked()),refMat,SLOT(det()));
    connect(mul,SIGNAL(clicked()),refMat,SLOT(mul()));
    connect(div,SIGNAL(clicked()),refMat,SLOT(div()));


    setLayout(buttons);
}
