#ifndef AVL
#define AVL
#include "bst.h"

class AVL : public BinarySearchTree{
	public:    
	    int height(tree_node* node);
	    int bfactor(tree_node* node);
	    BinarySearchTree::tree_node* rr_rotation(tree_node* node);
	    BinarySearchTree::tree_node* ll_rotation(tree_node* node);
	    BinarySearchTree::tree_node* lr_rotation(tree_node* node);
	    BinarySearchTree::tree_node* rl_rotation(tree_node* node);
	    BinarySearchTree::tree_node* balance(tree_node* node);
};
#endif
