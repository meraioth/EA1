#include "avl.h"
#include <iostream>
using namespace std;

BinarySearchTree::tree_node* AVL::insertar_avl(int data)
{
    tree_node* nodo = insertar(data);
    balance(nodo);
}

int AVL::bfactor(BinarySearchTree::tree_node* temp)
{
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
    }
}

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
