#include <stdio.h>
#include <math.h>

void bienvenida() {
  int i_edad;
  float f_estatura;
  char c_nombre[50], c_estado_civil;

  //v1.0 bienvenida
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
}

void contador() {
  float f_balance_cuenta, f_ingresos_mensuales, f_gastos_mensuales, f_meta_ahorro;
  int i_bono_anual;

  //v1.1 contador
  printf("Hola, soy AlanBot\n");
  printf("Ingrese su balance de cuenta:\n");
  scanf("%f", &f_balance_cuenta);
  printf("Ingrese sus ingresos mensuales:\n");
  scanf("%f", &f_ingresos_mensuales);
  printf("Ingrese sus gastos mensuales:\n");
  scanf("%f", &f_gastos_mensuales);
  printf("Ingrese su bono anual (en porcentaje):\n");
  scanf("%d", &i_bono_anual);
  printf("Ingrese su meta de ahorro:\n");
  scanf("%f", &f_meta_ahorro);

  printf("Considerando sus ingresos y gastos mensuales, su balance de cuenta será de %f para el primer mes \n", 
  f_balance_cuenta + f_ingresos_mensuales - f_gastos_mensuales);

  printf("El balance de su cuenta para el segundo mes, con un gasto inesperado de $1200 es de %f \n", 
  f_balance_cuenta + (f_ingresos_mensuales - f_gastos_mensuales) * 2 - 1200);

  printf("El balance de su cuenta despues de un año será de %f \n",
  f_balance_cuenta + (f_ingresos_mensuales - f_gastos_mensuales) * 12 + (f_ingresos_mensuales - f_gastos_mensuales) * 12 * (i_bono_anual / 100));

  printf("Si desea alcanzar su meta de ahorro deberá trabajar %f meses \n",
  ceil((f_meta_ahorro - f_balance_cuenta) / (f_ingresos_mensuales - f_gastos_mensuales)));
}

void operador_bits() {
  unsigned int i_number_input;
 
  //v1.2 operaciones a nivel de bits
  printf("Ingrese un número entero positivo: \n");
  scanf("%d", &i_number_input);

  if(i_number_input & 1) {
    printf("El número ingresado es inpar \n");
  }
  else {
    printf("El número ingresado es par \n");
  }

  if((i_number_input > 0) && ((i_number_input & (i_number_input - 1)) == 0)) {
    printf("El número ingresado es potencia de 2 \n");
  }
  else {
    printf("El número ingresado no es potencia de 2 \n");
  }

  printf("El número multiplicado por 2 es: %d \n", i_number_input << 1);
}

int main() {
  // bienvenida();
  // contador();
  // operador_bits();
  return 0;
}