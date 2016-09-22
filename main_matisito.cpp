#include "bst.h"
#include "splaytree.h"
#include <iostream>
using namespace std;

void bst_print_dot_null(int key, int nullcount, FILE* stream)
{
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %d -> null%d;\n", key, nullcount);
}

void bst_print_dot_aux(bst_node* node, FILE* stream)
{
    static int nullcount = 0;

    if (node->left)
    {
        fprintf(stream, "    %d -> %d;\n", node->key, node->left->key);
        bst_print_dot_aux(node->left, stream);
    }
    else
        bst_print_dot_null(node->key, nullcount++, stream);

    if (node->right)
    {
        fprintf(stream, "    %d -> %d;\n", node->key, node->right->key);
        bst_print_dot_aux(node->right, stream);
    }
    else
        bst_print_dot_null(node->key, nullcount++, stream);
}

void bst_print_dot(bst_node* tree, FILE* stream)
{
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %d;\n", tree->key);
    else
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}

int main(int argc, char *argv[]) {
    BinarySearchTree bi;
    SplayTree sp;
    sp.insertar(30);
    sp.insertar(10);
    sp.insertar(20);
    sp.insertar(12);
    sp.insertar(2);
    //sp.insertar_splay(1);
    sp.insertar(100);
    FILE * pFile;
    pFile = fopen ("myfile.dot" , "w");
    sp.postorder(NULL);
    //cout << bi.busqueda(20)->data << endl;

    //sp.imprimir(NULL);
    //bi.imprimir(NULL);
}
