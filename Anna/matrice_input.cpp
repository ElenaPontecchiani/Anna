#include "matrice_input.h"
#include "../Parte_Logica/matrix.h"
#include "../Parte_Logica/square_matrix.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QItemDelegate>
#include <QValidator>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QRegExpValidator>
#include <QPushButton>
#include <math.h>
#include <QHeaderView>


class Delegate : public QItemDelegate
{
public:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem & option,
                      const QModelIndex & index) const
    {
        QLineEdit *lineEdit = new QLineEdit(parent);
        // Set validator
        QDoubleValidator *validator = new QDoubleValidator(lineEdit);
        lineEdit->setValidator(validator);
        return lineEdit;
    }
};




Matrice_Input::Matrice_Input(int r, int c, QWidget *parent) :QWidget(parent)
{
    mat = 0;
    tab = 0;
    tast = new Tastiera(this);

    QHBoxLayout* size = new QHBoxLayout();

    QLabel* rig = new QLabel("Righe",this);
    QLabel* col = new QLabel("Colonne",this);

    QPushButton* plusrow = new QPushButton("+",this);
    QPushButton* minurow = new QPushButton("-",this);
    QPushButton* pluscol = new QPushButton("+",this);
    QPushButton* minucol = new QPushButton("-",this);

    connect(plusrow,SIGNAL(released()),this,SLOT(plusRow()));
    connect(minurow,SIGNAL(released()),this,SLOT(minusRow()));
    connect(pluscol,SIGNAL(released()),this,SLOT(plusColumn()));
    connect(minucol,SIGNAL(released()),this,SLOT(minusColumn()));

    size->addWidget(rig);
    size->addWidget(minurow);
    size->addWidget(plusrow);
    size->addWidget(col);
    size->addWidget(minucol);
    size->addWidget(pluscol);

    newMat(r,c);
    det = new QLabel(detText(),this);
    connect(tab,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(modEl(QTableWidgetItem*)));

    QHeaderView *oriz = new QHeaderView(Qt::Horizontal,tab);
    QHeaderView *vert = new QHeaderView(Qt::Vertical,tab);
    vert->setSectionResizeMode(QHeaderView::Stretch);
    oriz->setSectionResizeMode(QHeaderView::Stretch);
    tab->setHorizontalHeader(oriz);
    tab->setVerticalHeader(vert);


    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->addLayout(size);
    lay->addWidget(tab);
    lay->addWidget(det);
    lay->addWidget(tast);
    setLayout(lay);
}


void Matrice_Input::newMat(int r, int c){
    if(!tab)
        tab = new QTableWidget(this);

    if(mat)
        delete mat;

    if (r == c)
        mat = new square_matrix<double>(r);
    else
        mat = new matrix<double>(r,c);
    mat->Fill(0);
    tab->setRowCount(mat->getH());
    tab->setColumnCount(mat->getL());
    upMat();
}

void Matrice_Input::changeCol(QString qs){
    newMat(mat->getH(),qs.toInt());
}

void Matrice_Input::changeRow(QString qs){
    newMat(qs.toInt(),mat->getL());
}


void Matrice_Input::upMat(){
    tab->clear();
    for(int r = 0; r < mat->getH(); r++)
        for(int c = 0; c < mat->getL(); c++)
            tab->setItem(r, c, new QTableWidgetItem(QString::number((*mat)[r*mat->getL()+c])));
}

#include <iostream>
using std::cout;
using std::endl;
void Matrice_Input::modEl(QTableWidgetItem *item){
    item->setText(item->text().replace(",","."));
    (*mat)[item->row()*mat->getL()+item->column()] = (item->text()).QString::toDouble();
    det->setText(detText());
    //cout << *mat << endl << endl;
}


QString Matrice_Input::detText() const{
    square_matrix<double>* p = dynamic_cast<square_matrix<double>*>(mat);
    if (p == 0)
        return ("Determinante non disponibile");
    else
        return "Determinante: " + QString::number(p->Det());
}

matrix<double>* Matrice_Input::getMat()const{
   return mat;
}


void Matrice_Input::trasposta(){
    mat->Trasposta();
    matrix<double>* cp = mat->clone();
    newMat(mat->getH(),mat->getL());
    delete mat;
    mat = cp;
    upMat();
}

void Matrice_Input::gauss(){
    mat->Gauss();
    upMat();
}

void Matrice_Input::gaussJordan(){
    mat->GaussJordan();
    upMat();
}

void Matrice_Input::radX(double d){
    mat->mathOp(pow,1.0/d);
    upMat();
}

void Matrice_Input::powX(double d){
    mat->mathOp(pow,d);
    upMat();
}

void Matrice_Input::inv(){
    square_matrix<double>* p = dynamic_cast<square_matrix<double>*>(mat);
    if(p){
        if (p->Det() != 0){
            p->Inversa();
            upMat();
        }
    }
}


void Matrice_Input::plusRow(){
    if (mat->getH() < 50)
        newMat(mat->getH()+1,mat->getL());
    upMat();
}

void Matrice_Input::plusColumn(){
    if (mat->getL() < 50)
        newMat(mat->getH(),mat->getL()+1);
    upMat();
}

void Matrice_Input::minusRow(){
    if (mat->getH() > 1)
        newMat(mat->getH()-1,mat->getL());
    upMat();
}

void Matrice_Input::minusColumn(){
    if (mat->getL() > 1)
        newMat(mat->getH(),mat->getL()-1);
    upMat();
}


























