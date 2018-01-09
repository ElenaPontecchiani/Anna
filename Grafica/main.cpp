#include "MatInput.h"
#include "MatFun.h"
#include "../matrix.h"
#include <iostream>
#include <QApplication>
#include <QVBoxLayout>

int main(int argc, char* argv[]){
    QApplication* app = new QApplication(argc,argv);
    int c;
    int r;
    std:: cin >> r >> c;
    matrix<double>* a= new matrix<double>(r,c);
    a->Fill(0);

    QWidget *window = new QWidget;
    QVBoxLayout *prog = new QVBoxLayout;

    MatInput* mat = new MatInput(a);
    MatFun tast(mat);

    prog->addWidget(mat);
    prog->addWidget(&tast);

    window->setLayout(prog);
    window->show();

    return app->exec();
}
