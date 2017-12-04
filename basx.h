//fino base 10+26

template<class T>
class basex{
private:
    T raw_number;//solo tipi num
    int base;

public:
        
    
    //Costruttori
    basex(T=0,int=10);
    basex(const string& );  //Costruttore attraverso una stringa
                            //Funge anche da conversione implicita da stringa

    //Overload di operatori
    basex operator+(const basex& )const;
    basex operator*(const basex& )const;
    basex operator/(const basex& )const;
    basex operator-(const basex& )const;
    
    //Conversioni
    operator string()const; //Converto *this a stringa
    T toTen(const basex& ); //Converto *this in un numero T in base 10
    /*  Sarà necessario dichiarare dei metodi di conversione per i tipi che T può assumere
        = pinga in culo*/


//overload output






};