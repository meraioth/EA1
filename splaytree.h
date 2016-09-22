#ifndef SPT
#define SPT
#include "bst.h"

class SplayTree : public BinarySearchTree{
public:
    BinarySearchTree::tree_node* insertar_splay(int data);
    void splay(tree_node* node);
    void left_rotate(tree_node* node);
    void right_rotate(tree_node* node);
};
#endif
