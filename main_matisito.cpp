#include "bst.h"
#include "splaytree.h"
#include "avl.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

using namespace std;


int main(int argc, char *argv[]) {
    //para medir el tiempo
    clock_t begin, end;
	double time_spent;

    //archivo con los resultados
    FILE *resultados_splay_insert;
	resultados_splay_insert = fopen("resultados_splay_insert.txt", "w+");
    FILE *resultados_splay_busqueda;
	resultados_splay_busqueda = fopen("resultados_splay_busqueda.txt", "w+");



    begin = clock();//tiempo antes de el algoritmo
		enigma(A,n);
		end = clock()
;		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


    srand (time(NULL));
    for(int n = 1000; i < 1000000; i+=1000){
        int datos [n];
        SplayTree sp;
        AVL avl;
        RedBlackTree rbt;
        for(int i = 0 ; i < n; i++){
            datos[i] = i+1;
        }
        //se desordenan de forma randomica
        int j;
        for(int i = 0 ; i < 1000 ; i++){
            j = rand()%1000;
            int aux = datos[i];
            datos[i] = datos[j];
            datos[j] = aux;
        }
    }
    for(int i = 0 ; i < 1000; i++){
        //j = rand()%100;
        sp.insertar_splay(datos[i]);
    }
    //sp.imprimir(NULL);
    //sleep(10);
    FILE * pFile;
    pFile = fopen ("myfile.dot" , "w");
    sp.bst_print_dot(NULL,pFile);
    fclose (pFile);
    system("dot -Tpng myfile.dot -o arbol.png");
}
