#ifndef HUFFMAN_PQ_H
#define HUFFMAN_PQ_H

#include <iostream>
using namespace std;

/*DSA*/#include "UniPrint/print.h"

//Huffman树
#include "Huffman/HuffChar.h" //引入Huffman（超）字符
#include "Huffman/HuffTree.h" //引入Huffman树
#include "Huffman/HuffTable.h" //引入Huffman编码表
#include "Huffman/HuffCode.h" //引入HuffCode二进制编码

// Huffman森林
#if defined(DSA_PQ_LIST)
#include "Huffman_PQ_List/Huffman_Forest_PQ_List.h"
#elif defined(DSA_PQ_COMPLHEAP)
#include "Huffman_PQ_ComplHeap/Huffman_Forest_PQ_ComplHeap.h"
#elif defined(DSA_PQ_LEFTHEAP)
#include "Huffman_PQ_LeftHeap/Huffman_Forest_PQ_LeftHeap.h"
#else //朴素方案：直接用List实现的Huffman森林
#include "Huffman/Huffman_Forest_List.h"
#endif
#endif
