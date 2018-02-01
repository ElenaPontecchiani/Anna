#include "matrice_input.h"
#include "maincalc.h"
#include "../Parte_Logica/matrix.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainCalc fin;
    fin.show();
    return a.exec();
}
