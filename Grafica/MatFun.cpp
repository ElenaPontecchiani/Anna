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


    setLayout(buttons);
}
