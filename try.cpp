//#include "bst.h"
#include <iostream>
#include "avl.cpp"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]) {
srand(0);
AVL al ;
al.insertar(10);
//al.imprimir(al.root);
al.insertar(1);
//al.imprimir(al.root);
al.insertar(11);
al.insertar(998);
al.imprimir(NULL);
for ( int j = 0 ; j<1000; j+=10){
	//cout<<j<<'\t';
	al.insertar(j);
	
}
// for (int i = 0; i< 1000; i++){
// 	int a = rand();
// 	al.insertar(i);

// }
al.imprimir(NULL);

al.busqueda(1);




return 0;}