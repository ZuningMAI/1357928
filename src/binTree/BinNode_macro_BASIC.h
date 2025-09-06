#ifndef BINNODE_MACRO_BASIC_H
#define BINNODE_MACRO_BASIC_H

/******************************************************************************************
 * BinNode状态与性质的判断
 ******************************************************************************************/
#define IsLChild(x) ( ((x)->parent) && ((x) == (x)->parent->lc) )
#define IsLeaf(x) ( (!(x)->lc) && (!(x)->rc) )

/******************************************************************************************
 * 与BinNode具有特定关系的节点及指针
 ******************************************************************************************/
#define sibling( p ) ( ((p) == (p)->parent->lc) ? (p)->parent->rc : (p)->parent->lc ) /*兄弟*/
#define uncle( x ) ( sibling( (x)->parent ) ) /*叔叔*/
#define FromParentTo( x ) /*来自父亲的引用*/ \
   ( (x)->parent ? ( ((x) == (x)->parent->lc) ? (x)->parent->lc : (x)->parent->rc ) : this->_root )

#endif