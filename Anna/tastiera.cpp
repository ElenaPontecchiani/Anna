#include "tastiera.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "matrice_input.h"
#include <QLineEdit>

Tastiera::Tastiera(Matrice_Input* mm,QWidget *parent) :mi(mm), QWidget(parent)
{

    QVBoxLayout* final = new QVBoxLayout(this);
    QGridLayout* lay = new QGridLayout();

    QPushButton* trasp = new QPushButton("Trasposta",this);
    QPushButton* gauss = new QPushButton("Gauss",this);
    QPushButton* gaussj = new QPushButton("Gauss Jordan",this);
    QPushButton* radx = new QPushButton("RadX",this);
    QPushButton* powx = new QPushButton("Potenza X",this);
    QPushButton* plusx = new QPushButton("Più X",this);

    lay->addWidget(trasp,0,0);  lay->addWidget(gauss,0,1);
    lay->addWidget(gaussj,1,0); lay->addWidget(radx,1,1);
    lay->addWidget(powx,2,0);  lay->addWidget(plusx,2,1);

    connect(trasp,SIGNAL(released()),mm,SLOT(trasposta()));

    x = new QLineEdit(this);
    x->setValidator(new QDoubleValidator(x));

    final->addLayout(lay);
    final->addWidget(x);
    setLayout(final);
}
