#include "bst.h"
#include "splaytree.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    SplayTree sp;
    sp.insertar_splay(30);
    sp.insertar_splay(10);
    sp.insertar_splay(20);
    sp.insertar_splay(12);
    sp.insertar_splay(1);
    sp.insertar_splay(2);
    sp.insertar_splay(5);
    sp.insertar_splay(7);
    FILE * pFile;
    pFile = fopen ("myfile.dot" , "w");
    sp.bst_print_dot(NULL,pFile);
    fclose (pFile);
    system("dot -Tpng myfile.dot -o arbol.png");
}
