#include "splaytree.h"
#include <iostream>
using namespace std;

BinarySearchTree::tree_node* SplayTree::insertar_splay(int data){
    BinarySearchTree::tree_node* node = insertar(data);
    splay(node);
}

void SplayTree::splay(tree_node* node){
    while (node->parent){
        //caso 1: nodo es hijo izquierdo o derecho de la raíz
        if(node->parent == root){
            if(root->left == node){
                right_rotate(node->parent);
            }else{
                left_rotate(node->parent);
            }
        //caso 2: nodo es hijo izquierdo de su padre y este a su vez hijo izquierdo de su padre o viceversa.
    }else if(node->parent->left == node && node->parent->parent->left == node->parent){
            right_rotate(node->parent->parent);
            right_rotate(node->parent);
        }else if(node->parent->right == node && node->parent->parent->right == node->parent){
            left_rotate(node->parent->parent);
            left_rotate(node->parent);
        }
        //caso 3: nodo es hijo izquierdo de su padre y este a su vez hijo derecho de su padre o viceversa
        else if(node->parent->left == node && node->parent->parent->right == node->parent){
            right_rotate(node->parent);
            left_rotate(node->parent);
        }
        else{
            left_rotate(node->parent);
            right_rotate(node->parent);
        }
    }
}

void SplayTree::left_rotate(tree_node* node){
    tree_node* x = node->right;
    tree_node* y = x->left;
    if(y){
        node->right = y;
        y->parent = node;
    }
    x->parent = node->parent;
    node->parent = x;
    x->left = node;
}

void SplayTree::right_rotate(tree_node* node){
    tree_node* x = node->left;
    tree_node* y = x->right;
    if(y){
        node->left = y;
        y->parent = node;
    }
    x->parent = node->parent;
    node->parent = x;
    x->right = node;
}
