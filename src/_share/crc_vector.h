#ifndef CRC_VECTOR_H
#define CRC_VECTOR_H

#include "vector/vector.h"
#include "UniPrint/print.h"

template <typename T> void crc ( Vector<T> & V ) { //ͳԪ֮ͣ
   T crc = 0; 
   Crc<T> _crc(crc);
   V.traverse ( _crc );
   // V.traverse ( Crc<T> ( crc ) ); //crcΪб
   printf ( "CRC =" ); print ( crc ); printf ( "\n" ); //
}
#endif
