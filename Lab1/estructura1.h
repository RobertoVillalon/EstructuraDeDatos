#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListaNumeros{
  int cantidad;  //Cantidad actual de elementos que posee el arreglo
  int tamano;    //Cantidad total de elementos que posee el arreglo
  int *arreglo;
}lista;

lista *CreaListaNumerosVacia(int TAMANOMAX){
    lista *tmp;

    tmp = malloc(sizeof(lista));
    tmp->tamano = TAMANOMAX;
    tmp->arreglo = malloc(sizeof(int)*tmp->tamano);
    return (tmp);
}

lista *CreaListaNumerosLlena(lista *L,int max){
    srand(time(NULL));
    lista *tmp;
    tmp = L;
    int i;

    for (i = 0; i < tmp->tamano; i++) {
        tmp->arreglo[i] = rand()%max;
        tmp->cantidad++;
    }

    return (tmp);
}

int EliminaListaNumeros(lista *L){
    lista *tmp;
    tmp = L;

    tmp->cantidad = 0;
    tmp->tamano = 0;
    free(tmp->arreglo);
    free(tmp);

    printf("Lista Eliminada");
}

int BuscaNumerosEnListaNumeros(lista *L,int numero){
    lista *tmp;
    tmp = L;
    int i;

    for(i = 0; i < tmp->tamano; i++){
      if(tmp->arreglo[i] == numero){
        return i;
      }
    }

    return -1;
}

void ImprimirListaNumeros(lista *L){
    lista *tmp;
    tmp = L;
    int i;

    if(tmp->tamano != 0){
      for (i = 0; i < tmp->tamano; i++) {
        printf("\n%i",tmp->arreglo[i]);
      }
    }
}
