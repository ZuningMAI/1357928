#ifndef DOUBLE_ELEM_H
#define DOUBLE_ELEM_H

template <typename T> struct Double //函数对象：倍增一个T类对象
   { virtual void operator()( T& e ) { e *= 2; } }; //假设T可直接倍增

#endif
