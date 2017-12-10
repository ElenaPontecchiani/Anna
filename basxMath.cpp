#include "basxMath.h"

template<class T>
T bxm::abs(const T& t){
    if(t < 0)
        return t*-1;
    return t;
}
