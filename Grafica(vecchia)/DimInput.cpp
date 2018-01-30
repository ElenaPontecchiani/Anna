#include "DimInput.h"

#include <iostream>

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>


#include "MatInput.h"
#include <QIntValidator>


DimInput::DimInput(MatInput *m, QWidget* parent): QWidget(parent){
    row = new QLineEdit(this);
    column = new QLineEdit(this);
    QPushButton* ok = new QPushButton(this);

    row->setText("4");
    column->setText("3");
    ok->setText("Applica");

    row->setValidator(new QIntValidator(1,20,this));
    column->setValidator(new QIntValidator(1,20,this));

    QHBoxLayout* lay = new QHBoxLayout(this);
    lay->addWidget(row);
    lay->addWidget(column);
    lay->addWidget(ok);
    setLayout(lay);

    connect(ok,SIGNAL(clicked()),this,SLOT(applyDim()));
    connect(this,SIGNAL(setMatrix(int,int)),m,SLOT(newMatrix(int,int)));
}


void DimInput::applyDim(){
    emit setMatrix(row->text().toInt(),column->text().toInt());
}
