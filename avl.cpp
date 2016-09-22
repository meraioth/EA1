#include "avl.h"
#include <iostream>
using namespace std;

BinarySearchTree::tree_node* AVL::insertar(BinarySearchTree::tree_node* p, int data) // insert k data in a tree with p root
{
    if( !p ){ 
	    	BinarySearchTree::tree_node* child = new tree_node;
		    child->data = data;
		    child->left = NULL;
		    child->right = NULL;
		    return child;
			}
    if( data<p->data )
        p->left = insert(p->left,data);
    else
        p->right = insert(p->right,data);
    return balance(p);
}



int AVL::height(BinarySearchTree::tree_node* temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int AVL::bfactor(BinarySearchTree::tree_node* temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

BinarySearchTree::tree_node* AVL::rr_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->right;
    p->right=temp->left;
    temp->left=p;
    return p;


}


BinarySearchTree::tree_node* AVL::ll_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->left;
    p->left=temp->right;
    temp->right=p;
    p->height= max(p->left.height,p->right.height)+1;
    temp-> height = max(temp->left.height,p.height)+1;

    return p;


}

BinarySearchTree::tree_node* AVL::lr_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->left;
    p->left=rr_rotation(temp);
    
    return ll_rotation(p);


}
BinarySearchTree::tree_node* AVL::rl_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->right;
    p->right=ll_rotation(temp);
    
    return rr_rotation(p);


}


BinarySearchTree::tree_node* AVL::balance(BinarySearchTree::tree_node* p) // balancing the p node
{
    int b_factor=bfactor(p);
    if( b_factor>1)
    {
        if( bfactor(p->left) > 0 )
            p = ll_rotation(p);
        else 
            p=lr_rotation(p);
    }
    else if( b_factor < -1 )
    {
        if( bfactor(p->right) > 0  )
            p = rl_rotation(p);
        else 
            p=rr_rotation(p);
    }
    return p;
}


