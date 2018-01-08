#ifndef MATINPUT_H
#define MATINPUT_H

#include "../matrix.h"
#include "../square_matrix.h"

#include <QWidget>
#include <QLineEdit>


class InputBox: public QLineEdit{
Q_OBJECT
friend class MatInput;
private:
    int r;
    int c;
public:
    InputBox(int rr =0, int cc =0, QWidget* parent =0);
signals:
    void valueChangedSig(const QString &str,int rr, int cc);
public slots:
    void valueChanged(const QString &str);


};


class MatInput: public QWidget{
Q_OBJECT
private:
    matrix<double>* mat;
public:
    MatInput(matrix<double>* m, QWidget* parent =0);

public slots:
    void setMatrixValue(const QString& str, int r, int c);
};




#endif
