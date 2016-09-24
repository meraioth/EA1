#include "avl.h"
#include <iostream>
using namespace std;

BinarySearchTree::tree_node* AVL::insertar_avl(int data)
{
<<<<<<< HEAD
    tree_node* nodo = insertar(data);
    balance(nodo);
=======
    if(isEmpty()) {
        BinarySearchTree::tree_node* child = new tree_node;
        child->data = data;
        child->left = NULL;
        child->right = NULL;
        root=child;
        return root;


    }
    if( !p){ 
    
	    	BinarySearchTree::tree_node* child = new tree_node;
		    child->data = data;
		    child->left = NULL;
		    child->right = NULL;
		    return child;
			}
    if( data<p->data ){
        p->left = insert(p->left,data);
    }
    else{
        p->right = insert(p->right,data);
    }

    tree_node * t=balance(p);
    root=t;

    
    
    return t;
}

BinarySearchTree::tree_node* AVL::insertar(int data){
    
    return insert(root,data);
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
>>>>>>> ad7cca7c866716ef5d6f6951d2c78531d732571a
}

int AVL::bfactor(BinarySearchTree::tree_node* temp)
{
<<<<<<< HEAD
    int l_height,r_height;
    if(temp->left){
        l_height = temp->left->height;
    }else{
        l_height = 0;
    }
    if(temp->right){
        r_height = temp->right->height;
    }else{
        r_height = 0;
    }
    int b_factor= l_height - r_height;
    return b_factor;
}

void AVL::balance(BinarySearchTree::tree_node* node)
{
    int b_factor;
    while (node){
        b_factor = bfactor(node);
        if(b_factor >1){
            if(bfactor(node->left) >= 0){
                right_rotate(node);
            }else{
                left_rotate(node->left);
                right_rotate(node);
            }

        }else if(b_factor < -1){
            if(bfactor(node->right) > 0){
                right_rotate(node->right);
                left_rotate(node);
            }else{
                left_rotate(node);
            }
        }
        node = node->parent;
=======
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
    return temp;


}


BinarySearchTree::tree_node* AVL::ll_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->left;
    p->left=temp->right;
    temp->right=p;
    return temp;
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

>>>>>>> ad7cca7c866716ef5d6f6951d2c78531d732571a

    }
}

<<<<<<< HEAD
void AVL::left_rotate( tree_node* node ) {
    tree_node* x = node->right;
    tree_node* grandparent = node->parent;
    if(x){
        tree_node* b = x->left;
        node->right = b;
        if(b){
            b->parent = node;
        }
        x->parent = grandparent;
        x->left = node;
        node->parent = x;
    }
    if(grandparent){
        if(node == grandparent->right){
            grandparent->right = x;
        }else{
            grandparent->left = x;
        }
    }else{
        root = x;
=======

BinarySearchTree::tree_node* AVL::balance(BinarySearchTree::tree_node* p)
{   
    int b_factor=bfactor(p);
    if( b_factor>1)
    {
        if( bfactor(p->left) > 0 ){
            p = ll_rotation(p);
        }
        else {
            p=lr_rotation(p);
        }
    }
    else if( b_factor < -1 )
    {
        if( bfactor(p->right) > 0  ){
            p = rl_rotation(p);
        }
        else {
            tree_node * temp=p;
            p=rr_rotation(temp);
        }
>>>>>>> ad7cca7c866716ef5d6f6951d2c78531d732571a
    }
    fix_height(node);
}

void AVL::right_rotate( tree_node* node ) {
    tree_node* x = node->left;
    tree_node* grandparent = node->parent;
    if(x){
        tree_node* b = x->right;
        node->left = b;
        if(b){
            b->parent = node;
        }
        x->parent = grandparent;
        x->right = node;
        node->parent = x;
    }
    if(grandparent){
        if(node == grandparent->right){
            grandparent->right = x;
        }else{
            grandparent->left = x;
        }
    }else{
        root = x;
    }
    fix_height(node);
 }
