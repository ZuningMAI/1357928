#ifndef DEPQ_SMMH_IMPLEMENTATION_H
#define DEPQ_SMMH_IMPLEMENTATION_H

/******************************************************************************************
 * 将PQ_DEPQ_SMMH各方法的实现部分，简洁地引入PQ_DEPQ_SMMH.h
 * 效果等同于将这些实现直接汇入PQ_DEPQ_SMMH.h
 * 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
 ******************************************************************************************/
#include "../_share/util.h"

#include "DEPQ_SMMH_Insert.h"
#include "DEPQ_SMMH_delMin.h"
#include "DEPQ_SMMH_delMax.h"
//#include "DEPQ_SMMH_heapify.h"

#endif