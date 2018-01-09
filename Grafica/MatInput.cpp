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
    std::cout << (*mat) << "\n";
}

double MatInput::getValue(int r, int c){
    return (*mat)[r*mat->getL()+c];
}

#include <math.h>
void MatInput::sqrt(){
    *mat = mat->mathOp(pow,0.5);
    std::cout << *mat << std::endl;

    emit Update();
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


InputBox::InputBox(int rr, int cc, MatInput* parent): r(rr), c(cc), father(parent), QLineEdit(parent){
    setValidator(new QDoubleValidator(this));
    connect(this,SIGNAL(textChanged(const QString &)),this,SLOT(valueChanged(const QString &)));
    connect(this,SIGNAL(valueChangedSig(const QString &,int,int)),parent,SLOT(setMatrixValue(const QString &,int,int)));
    connect(parent,SIGNAL(Update()),this,SLOT(Update()));
}

void InputBox::valueChanged(const QString & str){
    emit valueChangedSig(str,r,c);
    //valueChangedSig(const QString &str,int rr, int cc);
}

void InputBox::focusOutEvent(QFocusEvent *event){
    QLineEdit::focusOutEvent(event);
    setText(QString::number(father->getValue(r,c)));
}

void InputBox::Update(){
    setText(QString::number(father->getValue(r,c)));
}


