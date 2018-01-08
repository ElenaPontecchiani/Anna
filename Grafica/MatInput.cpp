#include "../matrix.h"
#include "../square_matrix.h"

#include "MatInput.h"

#include <iostream>

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <string>
#include <QString>
#include <QDoubleValidator>

MatInput::MatInput(matrix<double>* m, QWidget* parent): mat(m), QWidget(parent){

    InputBox** numbers = new InputBox*[m->getH()*m->getL()];
    for(int r = 0; r < m->getH(); r++)
        for(int c = 0; c < m->getL(); c++){
            numbers[r*m->getL()+c] = new InputBox(r,c,this);
            numbers[r*m->getL()+c]->setText(QString::number((*m)[r*m->getL()+c]));
        }

    QGridLayout* num_grid = new QGridLayout;
    for(int r = 0; r < m->getH(); r++)
        for(int c = 0; c < m->getL(); c++){
            num_grid->addWidget(numbers[r*m->getL()+c],r,c);
        }
    setLayout(num_grid);

}

void MatInput::setMatrixValue(const QString& str, int r, int c){
    int lol = (*mat).getL();
    (*mat)[r*lol+c] = str.QString::toDouble();
    std::cout << "funzia!!\n";
}



InputBox::InputBox(int rr, int cc, QWidget* parent): r(rr), c(cc), QLineEdit(parent){
    setValidator(new QDoubleValidator(this));
    connect(this,SIGNAL(textChanged(const QString &)),this,SLOT(valueChanged(const QString &)));
    connect(this,SIGNAL(valueChangedSig(const QString &,int,int)),parent,SLOT(setMatrixValue(const QString &,int,int)));
}

void InputBox::valueChanged(const QString & str){
    emit valueChangedSig(str,r,c);
    //valueChangedSig(const QString &str,int rr, int cc);
}


