#include "bst.h"
#include "rbtree.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char *argv[]) {
    RedBlackTree rb;
    for (size_t i = 3; i > 0; i--) {
      rb.insertarrbt(i);
    }
    char gol;
    std::cout << "\nRedBlackTree Creado Con Exito\n" << std::endl;
    std::cout << "Desea generar imagen del arbol?(s/n)" << std::endl;
    std::cin >> gol;
    if (gol == 's') {
      FILE * pFile = fopen("rbtree.dot" , "w");
      rb.rbt_print_dot(NULL,pFile);
      fclose(pFile);
      system("dot -Tpng rbtree.dot -o rbt.png");
      //x system("rm rbtree.dot");
    }
    rb.disp();

}
