// v1.3 operador de bits
// Solicitar al usuario un número entero positivo y realizar operaciones
// con bits para contestar:
// a) ¿El número es par? 
// b) ¿El número es potencia de 2?
// c) ¿Cuál es el número multiplicado por 2?

#include <stdio.h>

int main() {
  unsigned int i_number_input;

  printf("Ingrese un número entero positivo: \n");
  scanf("%d", &i_number_input);

  // Si el ultimo bit esta prendido es un número inpar ya que el primer
  // bit representa 2^0, es decir; 1
  if(i_number_input & 1) {
    printf("El número ingresado es inpar \n");
  }
  else {
    printf("El número ingresado es par \n");
  }

  // Para que el número ingresado sea una potencia de 2 tiene que estar
  // unicamente un bit prendido en cualquier posición. Si se tiene el 8
  // cuya representación en binario es 1000, restarle 1 lo convierte a 7
  // y hace que su representación binaria cambie a 0111, por lo que al 
  // hacer una operación and el resultado debe ser 0 siempre y cuando el
  // número original tenga un solo bit prendido, caso contrario podemos 
  // decir que no es una potencia de 2
  if((i_number_input > 0) && ((i_number_input & (i_number_input - 1)) == 0)) {
    printf("El número ingresado es potencia de 2 \n");
  }
  else {
    printf("El número ingresado no es potencia de 2 \n");
  }

  // Debido a la base binaria, multiplicar por 2 se reduce a mover todos 
  // los bits una posición a la derecha.
  printf("El número multiplicado por 2 es: %d \n", i_number_input << 1);
  
  return 0;
}