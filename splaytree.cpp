#include "splaytree.h"
#include <iostream>
#include <random>
using namespace std;

BinarySearchTree::tree_node* SplayTree::insertar_splay(int data){
    tree_node* node = insertar(data);
    if(node){
        splay(node);
    }

}

BinarySearchTree::tree_node* SplayTree::busqueda_splay(int data){
    tree_node* node = busqueda(data);
    splay(node);
}

void SplayTree::splay(tree_node* node){
    while (node->parent){
        //caso 1: node es hijo izquierdo o derecho de la raíz
        if(!node->parent->parent){
            if(node->parent->left == node){
                right_rotate(node->parent);
            }else{
                left_rotate(node->parent);
            }
        //caso 2: node es hijo izquierdo de su padre y este a su vez hijo izquierdo de su padre o viceversa.
        }else if(node->parent->left == node && node->parent->parent->left == node->parent){
            right_rotate(node->parent->parent);
            right_rotate(node->parent);
        }else if(node->parent->right == node && node->parent->parent->right == node->parent){
            left_rotate(node->parent->parent);
            left_rotate(node->parent);
        }
        //caso 3: node es hijo izquierdo de su padre y este a su vez hijo derecho de su padre o viceversa
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
