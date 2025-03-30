// Escribir un programa que encuentre e imprima todos números primos en un 
// rango de números dado por el usuario.

#include <stdio.h>
#include <math.h>

int esNumeroPrimo(int num) {
  if(num < 2) return 0;

  for(int i = 2; i <= sqrt(num); i++) {
    if(num % i == 0) return 0;
  }

  return 1;
}

int main() {
  int inicio, final;
  do {
  printf("Ingrese el inicio del rango:");
  scanf("%d", &inicio);
  printf("Ingrese el final del rango:");
  scanf("%d", &final);
  } while(final < inicio || final < 0 || inicio < 0);

  for(int i = inicio; i < final; i++) {
    if(esNumeroPrimo(i)) {
      printf("%d ", i);
    }
  }
  return 0;
}