#ifndef INCREASE_LIST_H
#define INCREASE_LIST_H

/*DSA*/#include "list/list.h"

template <typename T> void increase ( List<T> & L ) //ͳһеĸԪ
{ 
    Increase<T> a;
    L.traverse ( a );
    
    // V.traverse ( Increase<T>() ); 
} //Increase<T>()Ϊб
#endif
