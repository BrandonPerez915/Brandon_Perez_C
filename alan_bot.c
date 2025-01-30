#include <stdio.h>

int main() {
  int i_edad;
  float f_estatura;
  char c_nombre, c_estado_civil;

  printf("Hola, soy AlanBot?\n");
  printf("Ingrese su nombre:\n");
  scanf("%s", &c_nombre);
  printf("Ingrese su estatura:\n");
  scanf("%f", &f_estatura);
  printf("Ingrese su edad:\n");
  scanf("%d", &i_edad);
  printf("Ingrese su estado civil:\n");
  scanf(" %c", &c_estado_civil);
}