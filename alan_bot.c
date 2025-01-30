#include <stdio.h>

int main() {
  int i_edad;
  float f_estatura;
  char c_nombre[50], c_estado_civil;

  printf("Hola, soy AlanBot?\n");
  printf("Ingrese su nombre:\n");
  scanf("%s", c_nombre);
  printf("Ingrese su estatura:\n");
  scanf("%f", &f_estatura);
  printf("Ingrese su edad:\n");
  scanf("%d", &i_edad);
  getchar();
  printf("Ingrese su estado civil:\n");
  scanf(" %c", &c_estado_civil);

  printf("Hola %s \n Su estatura es: %f \n Su edad es: %d \n Su estado civil es: %c \n", c_nombre, f_estatura, i_edad, c_estado_civil);

  return 0;
}