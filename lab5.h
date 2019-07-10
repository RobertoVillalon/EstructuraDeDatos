#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Arbol{
  char dato;
  struct Arbol *izq,*der;
}arbol;

char *crearArbolEnArreglo(arbol *);
int AlturaArbol(arbol *);
int max(int,int);
void copiarArbolenArreglo(arbol *,int,char *,int);
void vaciarArreglo(int,char *);
void imprimirArreglo(int,char *);
int muestraArbolEnTerminal(arbol *);

arbol *CrearNodo(int n){
  arbol *aux = malloc(sizeof(arbol));

  aux->dato = n;
  aux->izq = NULL;
  aux->der = NULL;

  return aux;
}

arbol *CrearArbol(FILE *archivo){
  arbol *aux;
  int c;

  while((c = fgetc(archivo)) != EOF){
    c = c -'\0';

    if(c == 'N' ){
      return(NULL);
    }
    else{
      aux = CrearNodo(c);
      aux->izq = CrearArbol(archivo);
      aux->der = CrearArbol(archivo);

      return aux;
    }
  }
}

int AlturaArbol(arbol *aux){
  int n;

  if(aux == NULL){
    return -1;
  }
  else{
    n = max(AlturaArbol(aux->der),AlturaArbol(aux->izq)) + 1;
  }

  return n;
}

int max(int a, int b){
    if(a>b){
      return a;
    }
    else{
      return b;
    }
}

int muestraArbolEnTerminal(arbol *unArbol){
	char *arreglo;
	int h;
	arreglo=crearArbolEnArreglo(unArbol);
	h=AlturaArbol(unArbol);
	int tamano;
	tamano=(pow(2,h+2)-1);

	int contador=0,nivelActual=0,nodosEnNivel=0,nodoActual=0;
							//contador es un indice que recorre los nodos actuales de un nivel
							//mientras que niveles es otro indice recorre los niveles que tiene el arbol
							//nodosEnNivel se usa porque no me deja usar el pow en un if
							//nodoActual es un indice que recorre TODOS los nodos actuales

	while(nivelActual<h+2){
			nodosEnNivel=pow(2,nivelActual);
			contador=0;
			while(contador<nodosEnNivel){
				printf("%c",arreglo[nodoActual]);
				contador++;
				nodoActual++;
			}
			printf("\n");
			nivelActual++;
	}


}

void imprimirArreglo(int tamano,char arreglo[tamano]){
	int i=0;
	while(i<31){
		printf("\narreglo[%i]=%c",i,arreglo[i]);
		i++;
		if(i==1 || i==3 || i==7 || i==15 || i==31){
			printf("\n");
		}
	}
}
void vaciarArreglo(int tamano,char arreglo[tamano]){
	int i=0;
	while(i<tamano){
		arreglo[i]='\0';
		i++;
	}
}

void copiarArbolenArreglo(arbol *unArbol,int tamano,char arreglo[tamano],int pos){
	if(unArbol==NULL){
		arreglo[pos]='N';
		return;
	}
	arreglo[pos]=unArbol->dato;
	copiarArbolenArreglo(unArbol->izq,tamano,arreglo,2*pos+1);
	copiarArbolenArreglo(unArbol->der,tamano,arreglo,2*pos+2);
}

char *crearArbolEnArreglo(arbol *unArbol){
	int h;
	h = AlturaArbol(unArbol);
	int tamano;
	tamano=(pow(2,h+2)-1);		//tamaño maximo de nodo que puede haber en un arbol de altura h
	char *arreglo=malloc(sizeof(char)*tamano);
	vaciarArreglo(tamano,arreglo);
	copiarArbolenArreglo(unArbol,tamano,arreglo,0);

	return arreglo;
}

void PreOrden(arbol *aux){

  if(aux == NULL){
    return NULL;
  }
  else{
    printf("%c ",aux->dato);
    PreOrden(aux->izq);
    PreOrden(aux->der);
  }
}
