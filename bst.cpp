#include "bst.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

bool BinarySearchTree::isEmpty()
{
    return root==NULL;
}

BinarySearchTree::tree_node* BinarySearchTree::busqueda(int data){
    tree_node* curr;
    curr = root;
    while(curr)    {
        if(data == curr->data){
            return curr;
        }
        else if(data < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return NULL;
}

void BinarySearchTree::imprimir(BinarySearchTree::tree_node* node){
    if(isEmpty()){
        return;
    }
    if(node == NULL){
    	node = root;
    }
    if(node->left){
    	imprimir(node->left);
    }
    cout << node->data << endl;
	if(node->right){
    	imprimir(node->right);
    }
}

BinarySearchTree::tree_node* BinarySearchTree::insertar(int data)
{
    tree_node* child = new tree_node;
    tree_node* parent;
    child->data = data;
    child->left = NULL;
    child->right = NULL;
    parent = NULL;

    // is this a new tree?
    if(isEmpty()){
        root = child;
        root->parent = NULL;
    }
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(child->data > curr->data){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        if(child->data < parent->data)parent->left = child;
        else parent->right = child;
        parent->height++;
        child->parent = parent;
    }
    return child;
}
