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

lista *CreaListaNumerosLlena(lista *L){
    srand(time(NULL));
    lista *tmp;
    tmp = L;
    int i;

    for (i = 0; i < tmp->tamano; i++) {
        tmp->arreglo[i] = rand()%10000;
        tmp->cantidad++;
    }

    return (tmp);
}

lista *CreaListaNumerosyOrden(lista *L){
  srand(time(NULL));
  lista *tmp;
  tmp = L;
  int i,j,k,aux;

    for (i = 0; i < tmp->tamano; i++){
        tmp->arreglo[i] = rand()%10000 + rand()%100000;
        tmp->cantidad++;
    }

    for (j = 0; j < tmp->tamano; j++){
      for(k = 0; k < tmp->tamano; k++){
        if(tmp->arreglo[j] < tmp->arreglo[k]){
          aux = tmp->arreglo[j];
          tmp->arreglo[j] = tmp->arreglo[k];
          tmp->arreglo[k] = aux;
        }
      }
    }

  return (tmp);
}

int CompararParaQuicksort(const void *p, const void *q){
	int x, y;
	x = *(int *) p;
	y = *(int *) q;
	if(x < y){
		return -1;
	}
	if(x == y ){
		return 0;
	}
	return 1;
}

lista *CreaListaNumerosQuicksort(lista *L){
    lista *tmp;
    tmp = L;
    int i,aux;
    for (i = 0; i < tmp->tamano; i++){
        tmp->arreglo[i] = rand()%10000 + rand()%100000;
        aux = i + 1;
        qsort(tmp->arreglo,aux,sizeof(int),&CompararParaQuicksort);
    }

    tmp->cantidad = tmp->tamano;

}

lista *EliminarListaNumeros(lista *L){
    lista *tmp;
    tmp = L;

    free(tmp->arreglo);
    free(tmp);
    tmp->cantidad = 0;

}

int BusquedaSecuencial(lista *L,int numero){
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
        printf("%i\n",tmp->arreglo[i]);
      }
    }
}

int BusquedaBinaria(lista *L, int numero){
  lista *tmp;
  tmp = L;
	int inf,sup,mitad;

	inf = 0;
	sup = tmp->tamano - 1;
	mitad = (sup + 1)/2;

	while(tmp->arreglo[mitad] != numero && inf<sup){
		if(tmp->arreglo[mitad] > numero){
			sup = mitad -1;
		}else{
			inf = mitad + 1;
		}
		mitad = (inf+sup)/2;
	}

	if(tmp->arreglo[mitad] == numero){
		return 1;
	}
	return 0;
}
