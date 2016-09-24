#ifndef SPT
#define SPT
#include "bst.h"

class SplayTree : public BinarySearchTree{
public:
    BinarySearchTree::tree_node* insertar_splay(int data);
    BinarySearchTree::tree_node* busqueda_splay(int data);
    void splay(tree_node* node);
};
#endif
