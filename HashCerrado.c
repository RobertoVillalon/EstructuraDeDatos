#include "HashCerrado.h"
#include <time.h>

int main(){
    FILE *archivo = fopen("C:\\users\\ucato\\desktop\\Laboratorios Estructura De Datos\\Lab 10\\listado-palabras1.txt","r");
    char aux2[40];
    int opcion = 1;

    CreaTablaHash(archivo,80);


    return 0;
}
