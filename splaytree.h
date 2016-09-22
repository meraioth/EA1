#ifndef SPT
#define SPT
#include "bst.h"

class SplayTree : public BinarySearchTree{
public:
    BinarySearchTree::tree_node* insertar_splay(int data);
    void Splay(tree_node* node);
    void left_rotate();
    void right_rotate();
};
#endif
