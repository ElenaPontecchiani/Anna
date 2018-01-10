#include "../matrix.h"
#include "../square_matrix.h"

#include "MatInput.h"

#include <iostream>

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <string>
#include <QString>
#include <QDoubleValidator>

MatInput::MatInput(matrix<double>* m, QWidget* parent): mat(m), QWidget(parent){
    Lyout = new QHBoxLayout;
    setLayout(defLay());

}

MatInput::~MatInput(){
    delete mat;
    delete num_grid;
}


void MatInput::setMatrixValue(const QString& str, int r, int c){
    int lol = (*mat).getL();
    (*mat)[r*lol+c] = str.QString::toDouble();
}

double MatInput::getValue(int r, int c){
    return (*mat)[r*mat->getL()+c];
}

void MatInput::newMatrix(int r, int c){
    QList<QWidget *> widgets = findChildren<QWidget *>();
    foreach(QWidget * widget, widgets)
    {
        delete widget;
    }
    matrix<double> *p = mat;
    QGridLayout* q = num_grid;
    delete p;
    delete q;
    if (r == c)
        mat = new square_matrix<double>(c);
    else
        mat = new matrix<double>(r,c);
    mat->Fill(0);
    num_grid = new QGridLayout;

    setLayout(defLay());
}

QHBoxLayout* MatInput::defLay(){
    QHBoxLayout* lay =  new QHBoxLayout(this);
    InputBox** numbers = new InputBox*[mat->getH()*mat->getL()];
    for(int r = 0; r < mat->getH(); r++)
        for(int c = 0; c < mat->getL(); c++){
            numbers[r*mat->getL()+c] = new InputBox(r,c,this);
            numbers[r*mat->getL()+c]->setText(QString::number((*mat)[r*mat->getL()+c]));
        }
    QGridLayout* num_grid = new QHBoxLayout(this);
    for(int r = 0; r < mat->getH(); r++)
        for(int c = 0; c < mat->getL(); c++){
            num_grid->addWidget(numbers[r*mat->getL()+c],r,c);
        }
    lay->addLayout(num_grid);
    return lay;
}


#include <math.h>
void MatInput::sqrt(){
    *mat = mat->mathOp(pow,0.5);
    emit Update();
}

void MatInput::Gauss(){
    *mat = mat->Gauss();
    emit Update();
}

void MatInput::GaussJordan(){
    *mat = mat->GaussJordan();
    emit Update();
}

void MatInput::Trasposta(){
    matrix<double> temp = mat->Trasposta();
    newMatrix(mat->getL(),mat->getH());
    *mat = temp;
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


