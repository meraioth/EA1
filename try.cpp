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
AVL al ;
cout<<al.isEmpty()<<endl;
al.insertar(10);
//al.imprimir(al.root);
al.insertar(11);
//al.imprimir(al.root);
al.insertar(12);
// al.insertar(9);
// al.insertar(13);
// al.insertar(14);



for (int i = 0; i< 10; i++){
	int a = rand();
	al.insertar(i);

}
al.dis();
al.imprimir(NULL);
FILE * pFile;
    pFile = fopen ("myfile.dot" , "w");
    al.bst_print_dot(NULL,pFile);
    system("dot -Tpng myfile.dot -o arbol.png");
    fclose (pFile);




return 0;}