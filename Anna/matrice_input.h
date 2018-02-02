#ifndef MATRICE_INPUT_H
#define MATRICE_INPUT_H

#include "../Parte_Logica/matrix.h"
#include "../Parte_Logica/square_matrix.h"
#include "../Parte_Logica/scalar_matrix.h"

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QString>
#include <QCheckBox>
#include "tastiera.h"

class Tastiera;

class Matrice_Input : public QWidget
{
    Q_OBJECT
private:
    matrix<double>* mat;
    QTableWidget* tab;
    QLabel* det;
    Tastiera* tast;
    QCheckBox* dg;
public:
    explicit Matrice_Input(int r, int c, QWidget *parent = nullptr);
    QString detText()const;
    matrix<double>* getMat()const;
    static void warning(const QString& qs);
signals:

public slots:
    void plusRow();
    void plusColumn();
    void minusRow();
    void minusColumn();

    void upMat();
    void modEl(QTableWidgetItem *item);
    void newMat(int r,int c);
    void changeCol(QString qs);
    void changeRow(QString qs);

    void trasposta();
    void gauss();
    void gaussJordan();
    void radX(double d);
    void powX(double d);
    void inv();
    void norm();
};

#endif // MATRICE_INPUT_H

