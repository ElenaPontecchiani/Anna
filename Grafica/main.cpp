#include "MatInput.h"
#include "MatFun.h"
#include "../matrix.h"
#include <iostream>
#include <QApplication>
#include <QVBoxLayout>

int main(int argc, char* argv[]){
    QApplication* app = new QApplication(argc,argv);
    matrix<double> a(8,9);
    a.Fill(0);

    QWidget *window = new QWidget;
    QVBoxLayout *prog = new QVBoxLayout;

    MatInput mat(&a);
    MatFun tast(&mat);

    prog->addWidget(&mat);
    prog->addWidget(&tast);

    window->setLayout(prog);
    window->show();

    return app->exec();
}
