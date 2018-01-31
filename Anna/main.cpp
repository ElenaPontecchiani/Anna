#include "matrice_input.h"
#include "../Parte_Logica/matrix.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget* w = new Matrice_Input(4,5);
    QWidget* y = new Matrice_Input(5,4);
    QHBoxLayout* b = new QHBoxLayout();
    QWidget *c = new QWidget();
    b->addWidget(w);
    b->addWidget(y);
    c->setLayout(b);
    c->show();

    return a.exec();
}
