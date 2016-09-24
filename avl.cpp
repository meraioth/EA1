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
