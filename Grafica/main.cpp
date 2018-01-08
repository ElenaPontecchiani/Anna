#include "MatInput.h"
#include "../matrix.h"
#include <iostream>
#include <QApplication>

int main(int argc, char* argv[]){
    QApplication* app = new QApplication(argc,argv);
    matrix<double> a(8,9);
    a.Fill(0);

    MatInput mat(&a);
    mat.show();
    return app->exec();
}
