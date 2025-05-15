#include <stdio.h>

void ej01(int x, int y) {
  do {
    if(x % 2 == 0) y *= 2;
    else y += 3;
    printf("%d- j= %d\n", x, y);
    x++;
  }while(x < 5);
}

void ej02() {
  int arreglo[3][3] = {
    {2,4,6},
    {3,5,7},
    {8,9,10}
  };

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if((i + j) % 2 == 0) arreglo[i][j] -= 2;
      else arreglo[i][j] += 5;

      if(i == j) arreglo[i][j] = 0;
    }
  }

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", arreglo[i][j]);
    }
    printf("\n");
  }
}

#define A 3
#define B 4
#define ACTIVO
#ifdef ACTIVO
  #define RESULTADO (A + B)
#else 
  #define RESULTADO (A * B)
#endif

#ifdef IMPRIMIR
  #define IMPRESION "Se imprimirá está línea"
#else
  #define IMPRESION "No se imprimirá está línea"
#endif

void ej03() {
  printf("Resultado: %d\n", RESULTADO);
  printf("%s\n", IMPRESION);
}

int log(int n, int b) {
  if(n <= b) return 1;
  return 1 + log(n / b, b);
}

void conteo_columnas(int matriz[][4], int filas) {
  for(int i = 0; i < 4; i++) {
    int suma = 0;
    for(int j = 0; j < filas; j++) {
      suma += matriz[j][i];
    }
    printf("Columna %d - Sumatoria: %d\n", i + 1, suma);
  }
}

int conteo_impares(int inicio, int final) {
  int conteo = 0;
  for(int i = inicio; i <= final; i++) {
    if(i & 1) conteo++;
  }
  return conteo;
}

int main() {
  int matriz[][4] = {
    {1, 2, 3, 5},
    {7, 8, 9, 3},
    {0, 1, 3, 1}
  };
  printf("%d\n", conteo_impares(3,9));
  return 0;
}