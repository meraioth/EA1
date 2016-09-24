#include "bst.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
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
    return curr;
}

BinarySearchTree::tree_node* BinarySearchTree::insertar(int data)
{
    tree_node* child = new tree_node;
    tree_node* parent;
    child->data = data;
    child->left = NULL;
    child->right = NULL;
    child->height = 1;
    parent = NULL;

    // si esta vacio
    if(isEmpty()){
        root = child;
        root->parent = NULL;
    }
    else
    {
        //nodo actual, partimos con la raiz
        tree_node* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(child->data > curr->data){
                curr = curr->right;
            }
            else if(child->data < curr->data){
                curr = curr->left;
            }else{
                return curr;
            }
        }
        curr = parent;
        fix_height(curr);
        if(child->data < parent->data)parent->left = child;
        else parent->right = child;
        child->parent = parent;
    }
    return child;
}

void BinarySearchTree::fix_height(tree_node* node){
    int rheight, lheight;
    while(node){
        if(node->left){
            lheight = node->left->height;
        }else{
            lheight = 1;
        }
        if(node->right){
            rheight = node->right->height;
        }else{
            rheight = 1;
        }
        if(lheight > rheight){
            node->height = lheight + 1;
        }else{
            node->height = rheight + 1;
        }
        node=node->parent;
    }
}

void BinarySearchTree::bst_print_dot_null(int data, int nullcount, FILE* stream)
{
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %d -> null%d;\n", data, nullcount);
}

void BinarySearchTree::bst_print_dot_aux(tree_node* node, FILE* stream)
{
    static int nullcount = 0;

    if (node->left)
    {
        fprintf(stream, "    %d [fontname=\"Arial\" label=\"%d[%d]\"];\n",node->data,node->data,node->height);
        fprintf(stream, "    %d -> %d;\n", node->data, node->left->data);
        //fprintf(stream, "    %d %d -> %d %d;\n", node->height, node->data,node->left->height, node->left->data);
        bst_print_dot_aux(node->left, stream);
    }
    else
        bst_print_dot_null(node->data, nullcount++, stream);

    if (node->right)
    {
        fprintf(stream, "    %d [fontname=\"Arial\" label=\"%d[%d]\"];\n",node->data,node->data,node->height);
        fprintf(stream, "    %d -> %d;\n", node->data, node->right->data);
        //fprintf(stream, "    %d %d -> %d %d;\n", node->height, node->data,node->right->height, node->right->data);
        bst_print_dot_aux(node->right, stream);
    }
    else
        bst_print_dot_null(node->data, nullcount++, stream);
}

void BinarySearchTree::bst_print_dot(tree_node* tree, FILE* stream)
{
    if(isEmpty()){
        return;
    }
    if(tree == NULL){
    	tree = root;
    }
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %d;\n", tree->data);
    else
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}
