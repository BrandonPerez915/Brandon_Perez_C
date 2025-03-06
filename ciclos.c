#include <stdio.h>

// Serie de ULAM:
// Tomando un número entero positivo, si es par se divide entre 2, si 
// es impar se multiplica por 3 y se le suma 1.

void serie_ulam(int num) {
  while (num > 1) {
    if (num % 2 == 0) {
      num /= 2;
    }
    else {
      num = num * 3 + 1;
    }
    printf("%d ", num);
  }
}

// Solicitar números enteros positivos y imprimir el número mayor captuardo
// hasta el momento, deja de solicitar números cuando se ingresa un número
// negstivo.

void numero_mayor_ingresado() {
  int mayor = 0;
  int num2;
  do {
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &num2);
    if (num2 > mayor) {
      mayor = num2;
    }
    printf("El número mayor capturado hasta el momento es: %d\n", mayor);
  } while (num2 >= 0);
}

int potencia_con_multiplicaciones(int base, int exponente) {
  int resultado = 1;
  for (int i = 0; i < exponente; i++) {
    resultado *= base;
  }
  return resultado;
}


int potencia_con_sumas(int base, int exponente) {
  int resultado = 0;
  for (int i = 0; i < exponente; i++) {
    for(int j = 0; j < base; j++) {
      resultado += base;
    }
  }
  return resultado;
}

int main() {
  // serie_ulam(10);
  // numero_mayor_ingresado();
  printf("%d\n", potencia_con_multiplicaciones(5,4));
  printf("%d\n", potencia_con_sumas(5,4));
  return 0;
}