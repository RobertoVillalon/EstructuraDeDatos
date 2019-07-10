#include <stdio.h>
#include <stdlib.h>

typedef struct Arbol{
  int dato;
  struct Arbol *hizq,*hder;
}arbol;

arbol *CrearNodo(int n){
  arbol *aux = malloc(sizeof(arbol));

  aux->dato = n;
  aux->hizq = NULL;
  aux->hder = NULL;

  return aux;
}

arbol *CrearArbol(FILE *archivo){
  arbol *aux;
  int c;

  while((c = fgetc(archivo)) != EOF){
    putchar(c);
    c = c -'\0';

    if(c == 'N' || c == 30){
      return(NULL);
    }
    else{
      aux = CrearNodo(c);
      aux->hizq = CrearArbol(archivo);
      aux->hder = CrearArbol(archivo);

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
    n = 1 + max(AlturaArbol(aux->hder),AlturaArbol(aux->hizq));
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

void PreOrden(arbol *aux){

  if(aux == NULL){
    return NULL;
  }
  else{
    printf("%c ",aux->dato);
    PreOrden(aux->hizq);
    PreOrden(aux->hder);
  }

}
