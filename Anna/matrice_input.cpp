#include "matrice_input.h"
#include "../Parte_Logica/matrix.h"
#include "../Parte_Logica/square_matrix.h"
#include "../Parte_Logica/vector.h"
#include "../Parte_Logica/diagonal_matrix.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QItemDelegate>
#include <QValidator>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QRegExpValidator>
#include <QPushButton>
#include <QMessageBox>
#include <QCheckBox>
#include <math.h>
#include "../Parte_Logica/vector.h"
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
    tipo = new QLabel(this);

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
    lay->addWidget(tipo);
    lay->addWidget(tab);
    lay->addWidget(det);
    lay->addWidget(tast);
    setLayout(lay);

    tipo->setText(tipoText());
}


void Matrice_Input::newMat(int r, int c){
    if(!tab){
        tab = new QTableWidget(this);
        tab->setItemDelegate(new Delegate);
    }
    if(mat)
        delete mat;

    mat = new matrix<double>(r,c);
    mat->Fill(0);
    tabRes(mat->getH(),mat->getL());
    upMat();
}

void Matrice_Input::tabRes(int h, int l){
    tab->setRowCount(h);
    tab->setColumnCount(l);
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

using std::cout;
using std::endl;
void Matrice_Input::modEl(QTableWidgetItem *item){
    item->setText(item->text().replace(",","."));
    (*mat)[item->row()*mat->getL()+item->column()] = (item->text()).QString::toDouble();
    det->setText(detText());
    rectify();
    tipo->setText(tipoText());
}


QString Matrice_Input::detText() const{
    square_matrix<double>* p = dynamic_cast<square_matrix<double>*>(mat);
    if (p == 0)
        return ("Determinante non disponibile");
    else
        return "Determinante: " + QString::number(p->Det());
}

#include <typeinfo>
QString Matrice_Input::tipoText() const{
    if(dynamic_cast<vector<double>*>(mat))
        return "Vettore";
    if(dynamic_cast<scalar_matrix<double>*>(mat))
        return "Matrice Scalare";
    if(dynamic_cast<diagonal_matrix<double>*>(mat))
        return "Matrice Diagonale";
    if(dynamic_cast<square_matrix<double>*>(mat))
        return "Matrice Quadrata";
    return "Matrice Ordinaria";
}

matrix<double>* Matrice_Input::getMat()const{
   return mat;
}


void Matrice_Input::trasposta(){
    mat->Trasposta();
    matrix<double> cp = *mat;
    newMat(mat->getH(),mat->getL());
    *mat = cp;
    upMat();
}

void Matrice_Input::gauss(){
    mat->Gauss(-1);
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
    bool ok = false;
    square_matrix<double>* p = dynamic_cast<square_matrix<double>*>(mat);
    if(p){
        if (p->Det() != 0){
            p->Inversa();
            upMat();
            ok = true;
        }
    }
    if (!ok)
        warning("La matrice non è invertibile");
}

void Matrice_Input::norm(){
    vector<double>* p = dynamic_cast<vector<double>*>(mat);
    if(p){
        vector<double> v = *p;
        v.Fill(0);
        if(!(v == *p)){
            p->Normalize();
            upMat();
        }
        else
            warning("Non puoi normalizzare lo zero!");
    }
    else
        warning("La matrice che vuoi normalizzare non è un vettore");
};

void Matrice_Input::matResize(int r, int c){
    if (r > 0){
        matrix<double> temp(r,mat->getL());
        temp.Fill(0);
        mat->AppendDown(temp);
    }
    else if (r < 0){
        mat->Cut(0,mat->getH()+r,0,mat->getL());
    }

    if (c > 0){
        matrix<double> temp(mat->getH(),c);
        temp.Fill(0);
        mat->Append(temp);
    }
    else if (c < 0){
        mat->Cut(0,mat->getH(),0,mat->getL()+c);
    }

    rectify();
    tabRes(mat->getH(),mat->getL());
    upMat();
}


void Matrice_Input::plusRow(){
    if (mat->getH() < 50)
        matResize(1,0);
}

void Matrice_Input::plusColumn(){
    if (mat->getL() < 50)
        matResize(0,1);
}

void Matrice_Input::minusRow(){
    if (mat->getH() > 1)
        matResize(-1,0);
}

void Matrice_Input::minusColumn(){
    if (mat->getL() > 1)
        matResize(0,-1);
}

void Matrice_Input::warning(const QString& qs){
    /*  Warning, live without warning
    *
    *   Without, alright
    *
    *   This is a public service announcement
    *   This is only a test
    */
    QMessageBox msgBox;
    msgBox.setText(qs);
    msgBox.exec();
}


void Matrice_Input::rectify(){
    int r = mat->getH();
    int c= mat->getL();

    if ( r == 1 || c == 1 ){ //Vettore
        matrix<double>* temp = new vector<double>(*mat);
        delete mat;
        mat = temp;
    }
    else if ( r == c ){ //Matrice non ordinaria
        bool diag = true;
        for(int ir = 0; ir < r && diag; ir++)
            for(int ic = 0; ic < c && diag; ic++)
                if ( ir != ic && (*mat)[ir*c+ic] != 0)
                    diag = false;
        if (diag){ //Diagonale o scalare
            bool scal = true;
            double test = (*mat)[0];
            for(int i = 0; i < r && scal; i++)
                if (test != (*mat)[i*c+i])
                    scal = false;
            if (scal){  //scalare
                matrix<double>* temp = new scalar_matrix<double>(*mat);
                delete mat;
                mat = temp;
            }
            else{   //diagonale
                matrix<double>* temp = new diagonal_matrix<double>(*mat);
                delete mat;
                mat = temp;
            }
        }
        else{ //quadrata
            matrix<double>* temp = new square_matrix<double>(*mat);
            delete mat;
            mat = temp;
        }
    }
    else{ //Matrice ordinaria
        matrix<double>* temp = new matrix<double>(*mat);
        delete mat;
        mat = temp;
    }
}




























