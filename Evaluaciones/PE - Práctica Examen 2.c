#include <stdio.h>
#include <math.h>
#define False 0
#define True 1
// Ciclos

// 1. Sumar los números naturales hasta N (se lo damos nosotros)
int sumarNumeros() {
  int cantidad_de_numeros, resultado = 0;
  printf("Ingrese la cantidad de números a sumar: ");
  scanf("%d", &cantidad_de_numeros);

  for(int i = 0; i < cantidad_de_numeros; i++) {
    int numero_actual;
    printf("\nIngrese el numero %d: ", i + 1);
    scanf("%d", &numero_actual);
    resultado += numero_actual;
  }

  return resultado;
}
// 2. Imprime la tabla de multiplicar de N
void tablaDeMultiplicar(int numero, int final) {
  for(int i = 1; i <= final; i++) {
    printf("%d x %d = %d\n", numero, i, numero * i);
  }
}
// 3. Cuenta cuántos números impares hay entre X y Y
int contarImpares(int inicio, int final) {
  int cuenta = 0;
  while(inicio <= final) {
    if(inicio & 1) {
      cuenta++;
    }
    inicio++;
  }
  return cuenta;
}
// 4. Detecta los números primos entre 1 y N
int esPrimo(int numero) {
  if(numero < 2) return False;
  else if(numero == 2 || numero == 3) return True;
  else if(numero % 2 == 0 || numero % 3 == 0) return False;

  int i = 5;
  while(i * i <= numero) {
    if(numero % i == 0 || numero % (i + 2) == 0) return False;
    i+=6;
  }
  return True;
}

void imprimirPrimos(int final) {
  printf("Primos: ");
  for(int i = 0; i < final; i++) {
    if(esPrimo(i)) printf("%d ", i);
  }
  printf("\n");
}
// 5. Calcula el Factorial de N
int factorial(unsigned int numero) {
  unsigned int resultado = 1;
  for(int i = 1; i < numero; i++) {
    resultado *= (i + 1);
  }
  return resultado;
}

// Recursividad

// 1. Sumar los números naturales hasta N (se lo damos nosotros) de forma recursiva.
int sumaRecursiva(int numero) {
  if(numero <= 1) return numero;
  return numero + sumaRecursiva(numero - 1);
}
// 2. Recorrer un array de forma recursiva.
void recorrerArrayRecursivamente(int numeros[], int inicio, int longitud) {
  if(inicio >= longitud) return;
  printf("%d ", numeros[inicio]);
  recorrerArrayRecursivamente(numeros, inicio + 1, longitud);
}
// 3. Buscar un elemento de un array de forma recursiva.
// 4. Invertir una palabra de forma recursiva.
// 5. Calcula la potencia de un numero de forma recursiva, tanto para exponentes
// negativos como positivos.
int potenciaRecursiva(int numero, int exponente) {
  if(exponente == 1) return numero;
  if(exponente == 0) return 1;
  if(exponente < 0) return 1 / potenciaRecursiva(numero, -exponente);
  return numero * potenciaRecursiva(numero, exponente - 1);
}
// 6. Suma los dígitos de un numero de forma recursiva.

int main() {
  // Ciclos
  // Ejercicio 1 -> printf("\nLa suma total de los números ingresados es: %d\n", sumarNumeros());
  // Ejercicio 2 -> tablaDeMultiplicar(8, 20);
  // Ejercicio 3 -> printf("Hay %d impares entre el %d y el %d\n", contarImpares(5, 91), 5, 91);
  // Ejercicio 4 -> imprimirPrimos(90);
  // Ejercicio 5 -> printf("factorial de %d = %d\n", 5, factorial(5));

  // Directivas de pre-procesador
  // 1. Definir una constante con #define
  // #define PI 3.1416

  // 2. Usar #ifdef y #endif para que solo ejecute un código si la constante de 
  // arriba sí está definida.
  // #ifdef PI
  // printf("PI esta definido\n");
  // #else
  // printf("PI no esta definido\n");
  // #endif

  // 3. Crea una macro.
  // #define multiplicacion(x,y) ((x) * (y))
  // printf("Resultado: %d\n", multiplicacion(10, 9));

  // Recursividad
  // Ejercicio 1 -> printf("Suma de los primeros 5 enteros: %d\n", sumaRecursiva(10));
  // Ejercicio 2 -> int numeros[] = {10,98,19,29,10,19,82,17}; recorrerArrayRecursivamente(numeros, 3, 8);
  printf("Potencia de 5^3 = %d\n", potenciaRecursiva(5, 3));

  return 0;
}