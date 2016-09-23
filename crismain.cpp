#include "bst.h"
#include "rbtree.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char *argv[]) {
    RedBlackTree rb;
    int max = 1000;
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
    for (size_t i = 0; i < max; i++) {
      rb.insertarrbt(datos[i]);
    }

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
