#include "bst.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {

    BinarySearchTree bi;
    bi.insertar(20);
    bi.insertar(12);
    bi.insertar(2);
    bi.insertar(1);
    bi.insertar(100);

    bi.imprimir(NULL);
}
