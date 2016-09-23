#ifndef BST
#define BST
#include <iostream>

class BinarySearchTree
{
protected:
    struct tree_node
    {
       tree_node* left;
       tree_node* right;
       tree_node* parent;
       int data;
    };
    tree_node* root;

public:
    BinarySearchTree();
    bool isEmpty();
    tree_node* busqueda(int data);
    tree_node* insertar(int data);
    void bst_print_dot_null(int data, int nullcount, FILE* stream);
    void bst_print_dot_aux(tree_node* node, FILE* stream);
    void bst_print_dot(tree_node* tree, FILE* stream);
};
#endif
