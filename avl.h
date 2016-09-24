#ifndef A_V_L
#define A_V_L
#include "bst.h"

class AVL : public BinarySearchTree{
	public:
		BinarySearchTree::tree_node* insertar_avl(int data);
	    int bfactor(tree_node* node);
		void left_rotate(tree_node* node);
	    void right_rotate(tree_node* node);
	    void balance(tree_node* node);
};
#endif
