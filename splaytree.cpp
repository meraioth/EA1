#include "splaytree.h"
#include <iostream>
using namespace std;

BinarySearchTree::tree_node* SplayTree::insertar_splay(int data){
    BinarySearchTree::tree_node* nodo = insertar(data);
    std::cout << nodo->data << std::endl;
}
