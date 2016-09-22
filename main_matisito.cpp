#include "bst.h"
#include "splaytree.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
std::cout << "/* message */" << std::endl;
    BinarySearchTree bi;
    std::cout << "/* message */" << std::endl;
    SplayTree sp;
    sp.insertar(30);
    sp.insertar(10);
    sp.insertar(20);
    sp.insertar(12);
    sp.insertar(2);
    sp.insertar_splay(1);
    sp.insertar(100);
    //cout << bi.busqueda(20)->data << endl;

    //sp.imprimir(NULL);
    //bi.imprimir(NULL);
}
