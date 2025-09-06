#ifndef PRINT_ENTRY_H
#define PRINT_ENTRY_H

/******************************************************************************************
 * Entry
 ******************************************************************************************/
template <typename K, typename V>
void UniPrint::p ( Entry<K, V>& e ) //ÒýÓÃ
{  printf ( "-<" ); print ( e.key ); printf ( ":" ); print ( e.value ); printf ( ">-" );  }



#endif
