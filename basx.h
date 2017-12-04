//fino base 10+26

template<class T>
class basex{
private:
    T raw_number;//solo tipi num
    int base;
public:
    virtual basex(T=0,int=10);//vedere pos virtual
    basex operator+(const basex& )const;
    basex operator*(const basex& )const;
    basex operator/(const basex& )const;
    basex operator-(const basex& )const;
    operator string()const;
    basex toBase();
    static T toTen(const basex& n);
    


//overload output






};