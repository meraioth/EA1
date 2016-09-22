#ifndef AVL
#define AVL
#include "bst.h"

class AVL : public BinarySearchTree{
public:
    BinarySearchTree::tree_node* insert(BinarySearchTree::tree_node* node,int data);
    
    unsigned char height(BinarySearchTree::tree_node* node);
    int bfactor(BinarySearchTree::tree_node* node);
    void fixheight(BinarySearchTree::tree_node* node);
    BinarySearchTree::tree_node* left_rotate(BinarySearchTree::tree_node* node);
    BinarySearchTree::tree_node* right_rotate(BinarySearchTree::tree_node* node);
    BinarySearchTree::tree_node* balance(BinarySearchTree::tree_node* node);
};
#endif
