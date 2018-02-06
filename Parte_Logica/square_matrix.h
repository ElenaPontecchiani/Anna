#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"



template<class T>
class square_matrix: public matrix<T>{
public:
    //Ridefinizione dei big3
    square_matrix(int);
    square_matrix(const matrix<T>&);
    //~square_matrix();//ridef distruttore non serve?


    square_matrix<T>* clone()const;
    //Controlli e bool
    bool isSymmetric()const;
    virtual bool isInvertible()const;

    //Matrice inversa e ausiliarie
    virtual void Inversa();
    virtual T Det ()const;

    square_matrix<T> WithOut(int row, int col)const;
    void addId();
};











//////////////////////////////
//  C O S T R U T T O R I   //
//////////////////////////////

template <class T>
square_matrix<T>::square_matrix(int dim): matrix<T>(dim,dim){}

template <class T>
square_matrix<T>::square_matrix(const matrix<T>& m): matrix<T>(m){}

//////////////////////////////
//  M E T O D I   V A R I   //
//////////////////////////////

template <class T>
bool square_matrix<T>::isSymmetric()const{
    return (*this == this->Trasposta());
}


/////////////////////////////////////
//  C A L C O L O  I N V E R S A   //
/////////////////////////////////////

template <class T>
T square_matrix<T>::Det ()const{
    if( this->getH() == 2)
        return( (*this)[0] * (*this)[3] - (*this)[1] * (*this)[2]  );
    T det = 0;
    int sign;
    for(int i = 0; i < this->getL(); i++){
        if ( i % 2 == 0) sign = 1;
        else sign = -1;
        det = det + (*this)[i] * sign * WithOut(0,i).Det();
    }
    return det;
}

template <class T>
square_matrix<T> square_matrix<T>::WithOut(int row, int col)const{
    square_matrix<T> temp(this->getH()-1);
    int pos = 0;
    for(int r = 0; r < this->getH(); r++)
        for(int c = 0; c < this->getL(); c++)
            if (c != col && r != row)
                temp[pos++] = (*this)[r*this->getL()+c];
    return temp;
}

template <class T>
void square_matrix<T>::addId(){
    square_matrix<T> temp(this->getL());
    temp.Fill(0);
    for(int i = 0; i < this->getL()*this->getL(); i += this->getL()+1)
        temp[i] = 1;
    this->Append(temp);
}

template <class T>
void square_matrix<T>::Inversa(){
    //return *(addId().GaussJordan(this->getH())->Cut(0,this->getH(),this->getH(),this->getH()*2));
    this->addId();
    this->GaussJordan(this->getH());
    this->Cut(0,this->getH(),this->getH(),this->getH()*2);
}




template <class T>
bool square_matrix<T>::isInvertible()const{
  return Det() != 0;
}

template <class T>
square_matrix<T>* square_matrix<T>::clone()const{
  return (new square_matrix<T>(*this));
}



#endif
