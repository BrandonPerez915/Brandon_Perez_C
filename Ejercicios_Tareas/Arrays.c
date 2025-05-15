#include <stdio.h>
#define L 25

// Crea un arreglo de 10 elementos y determinar cuandos elementos 
// son positivos, negativos o 0

void contarPositivosYNegativos(){
  int numeros[10];

  for(int i = 0; i < 10; i++) {
    int numeroActual;
    printf("Ingrese el número %d: ", i + 1);
    scanf("%d", &numeroActual);

    numeros[i] = numeroActual;
  }

  int ceros = 0;
  int positivos = 0;
  int negativos = 0;

  for(int i = 0; i < 10; i++) {
    if(numeros[i] == 0) {
      ceros++;
    }
    else if(numeros[i] > 0) {
      positivos++;
    }
    else {
      negativos++;
    }
  }

  printf("Positivos: %d Negativos: %d Ceros: %d \n", positivos, negativos, ceros);
}

int main() {
  // char letras[L + 1];
  // for(int i = 0; i < L; i++) {
  //   letras[i] = 97 + i;
  //   printf("%c", (char) 97 + i);
  // }
  // printf("\n%s\n", letras);
  contarPositivosYNegativos();
}


