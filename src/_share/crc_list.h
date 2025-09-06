#ifndef CRC_LIST_H
#define CRC_LIST_H

#include "list/list.h"
#include "UniPrint/print.h"

template <typename T> void crc ( List<T> & L ) { //ͳԪ֮ͣ
   T crc = 0; 
   Crc<T> _crc(crc);
   L.traverse ( _crc );
   // V.traverse ( Crc<T> ( crc ) ); //crcΪб
   printf ( "CRC =" ); print ( crc ); printf ( "\n" ); //
}
#endif
