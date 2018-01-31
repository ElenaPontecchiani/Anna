#include "matrice_input.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QItemDelegate>
#include <QValidator>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QRegExpValidator>


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




Matrice_Input::Matrice_Input(int r, int c,QWidget *parent) :QWidget(parent)
{
    mat = 0;
    tab = 0;

    /*QRegExp qr("[1-9]{1,1}[0-9]{1,1}");
    QRegExpValidator* qrv = new QRegExpValidator(qr,this);*/
    QHBoxLayout* size = new QHBoxLayout();
    QLineEdit* rows = new QLineEdit(this);
    QLineEdit* columns = new QLineEdit(this);
    rows->setValidator(new QIntValidator(1,50,rows));
    columns->setValidator(new QIntValidator(1,50,columns));
    rows->setText(QString::number(r));
    columns->setText(QString::number(c));
    connect(rows,SIGNAL(textChanged(QString)),this,SLOT(changeRow(QString)));
    connect(columns,SIGNAL(textChanged(QString)),this,SLOT(changeCol(QString)));
    size->addWidget(rows);
    size->addWidget(columns);

    newMat(r,c);
    det = new QLabel(detText(),this);
    connect(tab,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(modEl(QTableWidgetItem*)));


    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->addLayout(size);
    lay->addWidget(tab);
    lay->addWidget(det);
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
    cout << *mat << endl << endl;
}


QString Matrice_Input::detText(){
    square_matrix<double>* p = dynamic_cast<square_matrix<double>*>(mat);
    if (p == 0)
        return ("Determinante non disponibile");
    else
        return "Determinante: " + QString::number(p->Det());
}
