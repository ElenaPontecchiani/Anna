#ifndef BASEX_H
#define BASEX_H

#include <string>
using std::string;


class basex{
private:
    long double raw_number;//solo tipi num e inbase 10
    unsigned int base;

    static int approx10;
    static int approxx;

    static int charToInt(const char&);//conversione char->int
    static char intToChar(const int&);//conversione int->char
    static long double stringToNum(const string&,const int&);//string->T
    static std::string basxToString(const basex&, const int & =4);//basx->string

public:

    //Costruttori
    basex(const long double& =0.0,int=10); //non eseguo conversioni
    basex(const string&,const int =10);  //Costruttore attraverso una stringa
                                    //Funge anche da conversione implicita da stringa
    basex(const basex&,const int =10);  //Costruttore da basex + cambio base

    //Overload di operatori, base ritorno operando più a sx, this
    basex operator+(const basex&)const;
    basex operator*(const basex&)const;
    basex operator/(const basex&)const;
    basex operator-(const basex&)const;
    //basex& operator=(const basex&);//copia valore ma non base
    basex& operator+=(const basex&);
    bool operator==(const basex&)const;
    //Overload operatori con tipo float
    //basex& operator=(const long double&);
    basex operator+(const long double&)const;
    basex operator*(const long double&)const;
    basex operator/(const long double&)const;
    basex operator-(const long double&)const;

    void Print();   //Solo per debug
    void changeBase(int base);

    //Conversioni
    operator string()const; //Converto *this a stringa
    operator long double()const;
    /*  Questo operatore di conversione fa si che tutte le operazioni
     *  matematiche che accettano numeri in virgola mobile funzionino
     *  anche con i numeri basex
     */
};


std::ostream& operator<<(std::ostream& os, const basex& bx);
std::istream& operator>>(std::istream& is, basex& bx);













#endif
