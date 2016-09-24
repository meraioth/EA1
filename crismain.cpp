#include "bst.h"
#include "rbtree.h"
#include "avl.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
    std::clock_t start;
    double duration;

    RedBlackTree rb;
    AVL av;

    int max = 100000;
    int datos[max];
    for (size_t i = 0; i < max; i++) {
      datos[i]=i+1;
    }
    for (size_t i = 0; i < max; i++) {
      int j = rand()%max;
      int aux = datos[i];
      datos[i] = datos[j];
      datos[j] = aux;
    }
    //RBTree
    start = clock();
    for (size_t i = 0; i < max; i++) {
      rb.insertarrbt(datos[i]);
    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"RBTree: "<< duration <<'\n';

    start = clock();
    for (size_t i = 0; i < max; i++) {
      av.insertar(datos[i]);
    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"AVL: "<< duration <<'\n';

    //DESPLEGAR ARBOL PNG
    char gol;
    std::cout << "\nRedBlackTree Creado Con Exito\n" << std::endl;
    std::cout << "Desea generar imagen del arbol?(s/n)" << std::endl;
    std::cin >> gol;
    system("clear");
    std::cout << "espere..." << std::endl;
    if (gol == 's') {
      FILE * pFile = fopen("rbtree.dot" , "w");
      rb.rbt_print_dot(NULL,pFile);
      fclose(pFile);
      system("dot -Tpng rbtree.dot -o rbt.png");
      system("rm rbtree.dot");
    }
    system("clear");

}
