#ifndef HASHTABLE_IMPLEMENTATION_H
#define HASHTABLE_IMPLEMENTATION_H

/******************************************************************************************
 * 将Hashtable各方法的实现部分，简洁地引入Hashtable.h
 * 效果等同于将这些实现直接汇入Hashtable.h
 * 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
 ******************************************************************************************/
// #define PRIME_TABLE "../../_input/prime-1048576-bitmap.txt"
#define PRIME_TABLE "D:/VSCODE_PROJ/Data-Structure/DSA_for_vscode/_input/prime-1048576-bitmap.txt"
#include "_share/util.h"

#include "Hashtable_constructor.h"
#include "Hashtable_destructor.h"
#include "Hashtable_hashCode.h"
#include "Hashtable_probe4Hit.h"
#include "Hashtable_probe4Free.h"
#include "Hashtable_get.h"
#include "Hashtable_put.h"
#include "Hashtable_remove.h"
#include "Hashtable_rehash.h"

#endif
