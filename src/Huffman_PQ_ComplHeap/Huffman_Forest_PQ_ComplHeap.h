#ifndef HUFFMAN_FOREST_PQ_COMPLHEAP_H
#define HUFFMAN_FOREST_PQ_COMPLHEAP_H

#include <memory>

#include "PQ_ComplHeap/PQ_ComplHeap.h" //用PQ_ComplHeap实现
using HuffForest = PQ_ComplHeap<HuffTree>; //Huffman森林//
// using HuffForest = PQ_ComplHeap<std::unique_ptr<HuffTree>>;

#endif
