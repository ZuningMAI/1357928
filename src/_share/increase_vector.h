#ifndef INCREASE_VECTOR_H
#define INCREASE_VECTOR_H

/*DSA*/#include "vector/vector.h"

template <typename T> void increase ( Vector<T> & V ) //ͳһеĸԪ
{ 
    Increase<T> a;
    V.traverse ( a );
    
    // V.traverse ( Increase<T>() ); 
} //Increase<T>()Ϊб
#endif
