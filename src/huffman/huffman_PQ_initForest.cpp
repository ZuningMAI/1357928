
/*DSA*/#include "Huffman_PQ.h"
#include <memory>
/******************************************************************************************
 * 初始化Huffman森林：根据传入的频率统计表freq，为每个字符创建一棵树
 ******************************************************************************************
 * forest基于优先级队列实现，此算法适用于符合PQ接口的任何实现方式
 * 为Huffman_PQ_List、Huffman_PQ_ComplHeap和Huffman_PQ_LeftHeap共用
 * 编译前对应工程只需设置相应标志：DSA_PQ_List、DSA_PQ_ComplHeap或DSA_PQ_LeftHeap
 ******************************************************************************************/
HuffForest* initForest ( unsigned int * freq ) {
   HuffForest* forest = new HuffForest; //以PQ实现的Huffman森林
   for ( int i = 0; i < N_CHAR; i++ ) { //为每个字符
      BinTree<HuffChar>* tree = new BinTree<HuffChar>(); //生成一棵树，并将字符集频率
      tree->insert ( HuffChar ( 0x20 + i, freq[i] ) ); //存入其中
      forest->insert ( *tree ); //再将新树插入森林
      delete tree; //释放临时分配的树对象
   }
   return forest;
}
// HuffForest* initForest ( unsigned int * freq ) {
//    HuffForest* forest = new HuffForest; //以PQ实现的Huffman森林
   
//    // 直接在森林中创建树，避免后续删除导致的悬空指针问题
//    for ( int i = 0; i < N_CHAR; i++ ) {
//       HuffTree tree;
//       tree.insert ( HuffChar ( 0x20 + i, freq[i] ) );
//       forest->insert ( tree );
//    }
   
//    return forest;
// }
/*DSA*///课后：实现PQ_ComplHeap和PQ_LeftHeap的Robert Floyd算法，将本算法的效率提高至O(n)
