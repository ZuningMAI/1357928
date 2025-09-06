

#include "binTree_test.h"
#include <vector>

int testID = 0; //测试编号

// 随机生成期望高度为h的二叉树
template <typename T> bool randomBinTree ( BinTree<T> & btA, BinNodePosi<T> x, int h ) {
   if ( 0 >= h ) return false; //至多h层
   if ( 0 < dice ( h ) ) //以1/h的概率终止当前分支的生长
      randomBinTree ( btA, btA.insert ( x, dice ( ( T ) h * h * h ) ), h - 1 );
   if ( 0 < dice ( h ) ) //以1/h的概率终止当前分支的生长
      randomBinTree ( btA, btA.insert ( dice ( ( T ) h * h * h ), x ), h - 1 );
   return true;
}

// 在二叉树中随机确定一个节点位置
template <typename T> BinNodePosi<T> randomPosiInBinTree ( BinNodePosi<T> root ) {
   if ( IsLeaf ( root ) ) return root;
   if ( !root->lc )
      return dice ( 6 ) ? randomPosiInBinTree ( root->rc ) : root;
   if ( !root->rc )
      return dice ( 6 ) ? randomPosiInBinTree ( root->lc ) : root;
   return dice ( 2 ) ?
          randomPosiInBinTree ( root->lc ) :
          randomPosiInBinTree ( root->rc ) ;
}

template <typename T> void testBinTree ( int h ) { //测试二叉树
   printf ( "\n  ==== Test %2d. Generate a binTree of height <= %d \n", testID++, h );
   BinTree<T> btA; print ( btA );
   btA.insert ( dice ( ( T ) h * h * h ) ); print ( btA );
   randomBinTree<T> ( btA, btA.root(), h ); print ( btA );
   cout << "the height of tree A is:" << btA.root()->height << endl;
   // // /*
   printf ( "\n  ==== Test %2d. Double and increase all nodes by traversal\n", testID++ );
   // btA.travPre ( Double<T>() ); btA.travPre ( Increase<T>() ); print ( btA );
   Double<T> doubler; Increase<T> increaser;
   btA.travPre ( doubler ); btA.travPre ( increaser ); print ( btA );
   Double<T> doubler1; Increase<T> increaser1;
   btA.travIn ( doubler1 ); btA.travIn ( increaser1 ); print ( btA );
   Double<T> doubler2; Increase<T> increaser2;
   btA.travPost ( doubler2 ); btA.travPost (increaser2 ); print ( btA );
   Double<T> doubler3; Increase<T> increaser3;
   btA.travLevel ( doubler3 ); btA.travLevel ( increaser3 ); print ( btA );
   Hailstone<T> hs; btA.travIn ( hs ); print ( btA );

   printf ( "\n  ==== Test %2d. Create a shadow by copying\n", testID++ );
   BinTree<T> btB( btA ); //等效：BinTree<T> btB = btA;
   print( btB );

   printf ( "\n  ==== Test %2d. Create a HART by attaching\n", testID++ );
   BinNodePosi<T> p;
   p = btB.root(); while (p->lc) p = p->lc; btB.attach( btA, p );
   p = btB.root(); while (p->lc) p = p->lc; btB.attach( btA, p );
   BinNodePosi<T> q;
   q = btB.root(); while (q->rc) q = q->rc; btB.attach( q, btA );
   q = btB.root(); while (q->rc) q = q->rc; btB.attach( q, btA );
   print( btB );

   printf ( "\n  ==== Test %2d. Remove subtrees\n", testID++ );
   while ( !btB.empty() ) {
      BinNodePosi<T> p = randomPosiInBinTree ( btB.root() ); //随机选择一个节点
      if ( dice ( 2 ) ) {
         printf ( "removing " ); print ( p->data ); printf ( " ...\n" );
         printf ( "%d node(s) removed\n", btB.remove ( p ) ); print ( btB );
      } else {
         printf ( "releasing " ); print ( p->data ); printf ( " ...\n" );
         BinTree<T>* S = btB.secede ( p ); print ( S );
         printf ( "%d node(s) released\n", S->size() ); S->remove(S->root()); print ( btB );
      }
   }
   // */
}
// /*
// 根据先序和中序序列构建二叉树的辅助函数
template <typename T>
BinNodePosi<T> buildTreeFromPreInHelper(vector<T>& preorder, vector<T>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
   if (preStart > preEnd || inStart > inEnd) return nullptr;
   
   // 先序遍历的第一个节点是根节点
   T rootValue = preorder[preStart];
   BinNodePosi<T> root = new BinNode<T>(rootValue);
   
   // 在中序遍历中找到根节点的位置
   int rootIndex = inStart;
   while (inorder[rootIndex] != rootValue) rootIndex++;
   
   // 计算左子树的节点数量
   int leftSubtreeSize = rootIndex - inStart;
   
   // 递归构建左子树
   root->lc = buildTreeFromPreInHelper(preorder, inorder, 
                                 preStart + 1, preStart + leftSubtreeSize, 
                                 inStart, rootIndex - 1);
   if (root->lc) root->lc->parent = root;
   
   // 递归构建右子树
   root->rc = buildTreeFromPreInHelper(preorder, inorder, 
                                 preStart + leftSubtreeSize + 1, preEnd, 
                                 rootIndex + 1, inEnd);
   if (root->rc) root->rc->parent = root;
   
   return root;
}

// 根据先序和中序序列构建二叉树
template <typename T>
BinTree<T>* buildTreeFromPreIn(vector<T>& preorder, vector<T>& inorder) {
   if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
      return nullptr;
   }
   
   BinTree<T>* tree = new BinTree<T>();
   tree->_root = buildTreeFromPreInHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
   tree->_size = preorder.size();
   
   return tree;
}

// 测试根据先序和中序序列构建二叉树
void testBuildFromPreIn() {
   printf("\n  ==== Test %2d. Build binary tree from preorder and inorder sequence\n", testID++);
   
   // 测试用例：字符类型
   // preorder: a b c d e f
   // inorder:  b a d e c f
   // vector<char> pre = {'K', 'i', 'h', 'b', 'a', 'G','e','C','D','F','J'};
   // vector<char> in = {'i', 'b', 'a', 'h', 'C', 'e','D','G','F','K','J'};
   vector<char> pre = {'v', 'c', 'X', 'Y', 'Z'};
   vector<char> in = {'X', 'c', 'Y', 'v', 'Z'};
   
   BinTree<char> *bt = buildTreeFromPreIn(pre, in);
   print(*bt);

   // 增加在根节点分别进行zag、zig操作

   printf("\n  ==== Test %2d. Perform zig operation on node(K)\n", testID++);
   bt->root()->zig();
   print(*bt);
   
}
// */

int main ( int argc, char* argv[] ) { //测试二叉树
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) );
   //srand( 31415926 ); //固定种子（假种子，调试用）
   testBinTree<int> ( atoi ( argv[1] ) ); //元素类型可以在这里任意选择


   // 添加新的测试
   testBuildFromPreIn();

   system ( "pause" );
   return 0;
}

