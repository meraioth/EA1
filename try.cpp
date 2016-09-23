//#include "bst.h"
#include <iostream>
#include "bst.h"
#include "avl.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int main(int argc, char *argv[]) {
srand(0);

AVL aldo ;
aldo.insertar(100);
aldo.imprimir(NULL);
aldo.insertar(101);
aldo.imprimir(NULL);
aldo.insertar(103);
aldo.imprimir(NULL);
// aldo.insertar(102);
// aldo.imprimir(NULL);
// aldo.dis();



FILE * pFile;
    pFile = fopen ("myfile.dot" , "w");
    aldo.bst_print_dot(NULL,pFile);
    system("dot -Tpng myfile.dot -o arbol.png");
    fclose (pFile);




return 0;}