#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lab5.h"

int main(){
  FILE *archivo = fopen("serial.txt","r");
  arbol *unArbol;
  char *arreglo;

  arreglo = malloc(sizeof(char)*pow(2,AlturaArbol(unArbol)));

  unArbol = CrearArbol(archivo);

  arreglo = crearArbolEnArreglo(unArbol);

  //imprimirArreglo((pow(2,AlturaArbol(unArbol))),arreglo);

  muestraArbolEnTerminal(unArbol);

  PreOrden(unArbol);

  return 0;
}
