#ifndef A_V_L
#define A_V_L
#include "bst.h"

class AVL : public BinarySearchTree{
	public:
		BinarySearchTree::tree_node* insertar_avl(int data);
	    int bfactor(tree_node* node);
<<<<<<< HEAD
		void left_rotate(tree_node* node);
	    void right_rotate(tree_node* node);
	    void balance(tree_node* node);
=======
	    void dis();
	    void display(tree_node* node,int level);
	    BinarySearchTree::tree_node* rr_rotation(tree_node* node);
	    BinarySearchTree::tree_node* ll_rotation(tree_node* node);
	    BinarySearchTree::tree_node* lr_rotation(tree_node* node);
	    BinarySearchTree::tree_node* rl_rotation(tree_node* node);
	    BinarySearchTree::tree_node* balance(tree_node* node);
	    
>>>>>>> ad7cca7c866716ef5d6f6951d2c78531d732571a
};
#endif
