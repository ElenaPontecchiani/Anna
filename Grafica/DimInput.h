#ifndef DIMINPUT_H
#define DIMINPUT_H

#include <QLineEdit>
#include <QPushButton>

#include "MatInput.h"



class DimInput: public QWidget{
Q_OBJECT
private:
    QLineEdit* row;
    QLineEdit* column;
public:
    DimInput(MatInput* m, QWidget* parent =0);
signals:
    void setMatrix(int, int);
public slots:
    void applyDim();
};








#endif
