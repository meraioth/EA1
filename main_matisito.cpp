#include "bst.h"
#include "splaytree.h"
#include "avl.h"
#include "rbtree.h"
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
    FILE *resultados_rbt_insert;
    resultados_rbt_insert = fopen("resultados_rbt_insert.txt", "w+");
    FILE *resultados_rbt_busqueda;
    resultados_rbt_busqueda = fopen("resultados_rbt_busqueda.txt", "w+");
    FILE *resultados_avl_insert;
    resultados_avl_insert = fopen("resultados_avl_insert.txt", "w+");
    FILE *resultados_avl_busqueda;
    resultados_avl_busqueda = fopen("resultados_avl_busqueda.txt", "w+");

    //semilla de random
    srand (time(NULL));

    for(int n = 1000; n <= 100000; n+=1000){
        std::cout << n << std::endl;
        int datos [n];
        int datos2[n];
        SplayTree sp;
        AVL avl;
        RedBlackTree rbt;
        for(int i = 0 ; i < n; i++){
            datos[i] = i+1;
        }
        //se desordenan de forma randomica
        int j;
        for(int i = 0 ; i < n ; i++){
            j = rand()%n;
            int aux = datos[i];
            datos[i] = datos[j];
            datos[j] = aux;
        }
        //Splay Tree
        begin = clock();
        for(int i = 0 ; i < n; i++){
            sp.insertar_splay(datos[i]);
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(resultados_splay_insert,"%d	%lf\n",n,time_spent);
        //AVL
        begin = clock();
        for(int i = 0 ; i < n; i++){
            avl.insertar_avl(datos[i]);
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(resultados_avl_insert,"%d	%lf\n",n,time_spent);
        //Red Black Tree
        begin = clock();
        for(int i = 0 ; i < n; i++){
            rbt.insertarrbt(datos[i]);
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(resultados_rbt_insert,"%d	%lf\n",n,time_spent);
        for(int i = 0 ; i < n ; i++){
            j = rand()%10;
            datos2[i] = datos[n/2+j];
         }
        //splay busqueda
        begin = clock();
        for(int i = 0; i < n ; i++){
            sp.busqueda_splay(datos2[i]);
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(resultados_splay_busqueda,"%d	%lf\n",n,time_spent);
        //AVL
        begin = clock();
        for(int i = 0; i < n ; i++){
            avl.busqueda(datos2[i]);
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(resultados_avl_busqueda,"%d	%lf\n",n,time_spent);
        //Red Black Tree
        begin = clock();
        for(int i = 0; i < n ; i++){
            rbt.busqueda(datos2[i]);
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        fprintf(resultados_rbt_busqueda,"%d	%lf\n",n,time_spent);
    }

    fclose(resultados_rbt_busqueda);
    fclose(resultados_avl_busqueda);
    fclose(resultados_splay_busqueda);
    fclose(resultados_rbt_insert);
    fclose(resultados_splay_insert);
    fclose(resultados_avl_insert);
}
