#include "MatFun.h"
#include "MatInput.h"

#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

MatFun::MatFun(MatInput* refMat,QWidget *parent):QWidget(parent){
    QGridLayout* buttons = new QGridLayout;

    QPushButton* sqrt = new QPushButton;

    sqrt->setText("√");

    connect(sqrt,SIGNAL(clicked()),refMat,SLOT(sqrt()));

    buttons->addWidget(sqrt,0,0);



    QPushButton* pow = new QPushButton;

    pow->setText("x\302\262");

    connect(pow,SIGNAL(clicked()),refMat,SLOT(pow()));

    buttons->addWidget(pow,0,1);


    QPushButton* rec = new QPushButton;

    rec->setText("1/x");

    connect(rec,SIGNAL(clicked()),refMat,SLOT(rec()));

    buttons->addWidget(rec,1,0);


    QPushButton* cs = new QPushButton;

    cs->setText("\302\261");

    connect(cs,SIGNAL(clicked()),refMat,SLOT(cs()));

    buttons->addWidget(cs,1,1);


    QPushButton* add = new QPushButton;

    add->setText("+");

    connect(add,SIGNAL(clicked()),refMat,SLOT(add()));

    buttons->addWidget(ass,2,0);



    QPushButton* minus = new QPushButton;

    minus->setText("-");

    connect(minus,SIGNAL(clicked()),refMat,SLOT(minus()));

    buttons->addWidget(minus,2,1);



    QPushButton* mul = new QPushButton;

    mul->setText("*");

    connect(mul,SIGNAL(clicked()),refMat,SLOT(mul()));

    buttons->addWidget(mul,3,0);



    QPushButton* div = new QPushButton;

    div->setText("/");

    connect(div,SIGNAL(clicked()),refMat,SLOT(div()));

    buttons->addWidget(div,3,1);



    setLayout(buttons);
}
