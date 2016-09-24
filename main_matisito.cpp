#include "bst.h"
#include "splaytree.h"
#include "avl.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;


int main(int argc, char *argv[]) {
    //SplayTree sp;
    srand (time(NULL));
    AVL sp;
    int datos [500];
    for(int i = 0 ; i < 500; i++){
        datos[i] = i+1;
    }
    //se desordenan de forma randomica
    int j;
    for(int i = 0 ; i < 500 ; i++){
        j = rand()%500;
        int aux = datos[i];
        datos[i] = datos[j];
        datos[j] = aux;
    }
    for(int i = 0 ; i < 500; i++){
        //j = rand()%100;
        sp.insertar_avl(datos[i]);
    }
    //sp.imprimir(NULL);
    //sleep(10);
    FILE * pFile;
    pFile = fopen ("myfile.dot" , "w");
    sp.bst_print_dot(NULL,pFile);
    fclose (pFile);
    system("dot -Tpng myfile.dot -o arbol.png");
}
