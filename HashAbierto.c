#include "HashAbierto.h"
#include <time.h>

int main(){
    FILE *archivo = fopen("C:\\users\\ucato\\desktop\\Laboratorios Estructura De Datos\\Lab 9\\listado-palabras1.txt","r");
    char aux2[40];
    int opcion = 1;

    CreaTablaHash(archivo,100);

    return 0;
}
