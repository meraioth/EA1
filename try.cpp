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
aldo.insertar(1000);
aldo.dis();
aldo.insertar(102);
// aldo.imprimir(NULL);
// aldo.dis();
aldo.insertar(103);

aldo.insertar(105);

aldo.insertar(1);
aldo.insertar(2);
aldo.insertar(50);
aldo.insertar(60);
aldo.insertar(1010);
aldo.insertar(0);
aldo.insertar(-1);

//for(int i=0 ; i<500 ;i+=50) aldo.insertar(i);


FILE * pFile;
    pFile = fopen ("myfile.dot" , "w");
    aldo.bst_print_dot(NULL,pFile);
    system("dot -Tpng myfile.dot -o arbol.png");
    fclose (pFile);




return 0;}