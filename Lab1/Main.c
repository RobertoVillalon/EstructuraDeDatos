#include <stdio.h>
#include "estructura1.h"

int main(){
  int TAMANOMAX = 10;

  lista *L = CreaListaNumerosVacia(TAMANOMAX);

  CreaListaNumerosLlena(L,1000);

  //EliminaListaNumeros(L);

  ImprimirListaNumeros(L);

  BuscaNumerosEnListaNumeros(L,4);

  return 0;
}
