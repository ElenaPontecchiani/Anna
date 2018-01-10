#ifndef MATINPUT_H
#define MATINPUT_H

#include "../matrix.h"
#include "../square_matrix.h"

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>

class MatInput: public QWidget{
Q_OBJECT
private:
    matrix<double>* mat;
    QHBoxLayout* Lyout;
    QLabel * det;

    QHBoxLayout* defLay();
public:
    MatInput(matrix<double>* m, QWidget* parent =0);
    ~MatInput();

    double getValue(int r, int c);
signals:
    void Update();
public slots:
    void newMatrix(int r, int c);
    void setMatrixValue(const QString& str, int r, int c);
    void sqrt();
    void Gauss();
    void GaussJordan();
    void Trasposta();
};


class InputBox: public QLineEdit{
Q_OBJECT
friend class MatInput;
private:
    MatInput* father;
    int r;
    int c;

protected:
    void focusOutEvent(QFocusEvent *event);

public:
    InputBox(int rr =0, int cc =0, MatInput* parent =0);

signals:
    void valueChangedSig(const QString &str,int rr, int cc);

public slots:
    void valueChanged(const QString &str);
    void Update();

};





#endif
