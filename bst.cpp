#include "bst.h"
#include <iostream>
#include <iomanip>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

bool BinarySearchTree::isEmpty()
{
    return root==NULL;
}

void BinarySearchTree::postorder(tree_node* p, int indent)
{
    if(isEmpty()){
        return;
    }
    if(p == NULL){
    	p = root;
    }
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
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
        fprintf(stream, "    %d -> %d;\n", node->data, node->left->data);
        bst_print_dot_aux(node->left, stream);
    }
    else
        bst_print_dot_null(node->data, nullcount++, stream);

    if (node->right)
    {
        fprintf(stream, "    %d -> %d;\n", node->data, node->right->data);
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
