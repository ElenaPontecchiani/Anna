#include "MatInput.h"
#include "MatFun.h"
#include "DimInput.h"
#include "../matrix.h"
#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>


int main(int argc, char* argv[]){
    QApplication* app = new QApplication(argc,argv);

    matrix<double>* a= new matrix<double>(4,3);
    a->Fill(0);

    QWidget *window = new QWidget;
    QVBoxLayout *prog = new QVBoxLayout;

    MatInput* mat = new MatInput(a);
    MatFun tast(mat);
    DimInput* dim = new DimInput(mat,window);


    prog->addWidget(dim);
    prog->addWidget(mat);
    prog->addWidget(&tast);

    window->setLayout(prog);
    window->show();

    return app->exec();
}
