#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"


int main(){
  FILE *archivo = fopen("serial.txt","r");

  arbol *aux = CrearArbol(archivo);

  printf("\n%i\n",AlturaArbol(aux));

  PreOrden(aux);

  return 0;
}
