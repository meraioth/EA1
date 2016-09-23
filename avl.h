#ifndef A_V_L
#define A_V_L
#include "bst.h"

class AVL : public BinarySearchTree{
	public:    
		BinarySearchTree::tree_node* insertar(int data);
		BinarySearchTree::tree_node* insert(tree_node* p, int data);
	    int height(tree_node* node);
	    int bfactor(tree_node* node);
	    void dis();
	    void display(tree_node* node,int level);
	    BinarySearchTree::tree_node* rr_rotation(tree_node* node);
	    BinarySearchTree::tree_node* ll_rotation(tree_node* node);
	    BinarySearchTree::tree_node* lr_rotation(tree_node* node);
	    BinarySearchTree::tree_node* rl_rotation(tree_node* node);
	    BinarySearchTree::tree_node* balance(tree_node* node);
};
#endif
