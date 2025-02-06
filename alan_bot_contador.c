#include <stdio.h>
#include <math.h>

int main() {
  float f_balance_cuenta, f_ingresos_mensuales, f_gastos_mensuales, f_meta_ahorro;
  int i_bono_anual;

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
  ceil((f_meta_ahorro - f_balance_cuenta) / (f_ingresos_mensuales - f_gastos_mensuales)) );
  }