#include "bst.h"
#include "splaytree.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    BinarySearchTree bi;
    SplayTree sp;
    //sp.insertar(30);
    //sp.insertar(10);
    //sp.insertar(20);
    //sp.insertar(12);
    //sp.insertar(2);
    sp.insertar_splay(1);
    //sp.insertar(100);
    FILE * pFile;
    pFile = fopen ("myfile.dot" , "w");
    sp.bst_print_dot(NULL,pFile);
    system("dot -Tpng myfile.dot -o arbol.png");
    fclose (pFile);
    //cout << bi.busqueda(20)->data << endl;

    //sp.imprimir(NULL);
    //bi.imprimir(NULL);
}
