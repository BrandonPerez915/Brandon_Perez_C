#include <stdio.h>

int main() {
  char c_genero;
  int i_edad;

  printf("Ingrese una edad: \n");
  scanf("%d", &i_edad);
  printf("Ingrese un genero: \n");
  scanf(" %c", &c_genero);

  if(i_edad < 18) {
    printf("No puede entrar al bar, es muy joven \n");
  }
  else if((c_genero == 'M' || c_genero == 'm') && i_edad <= 25) {
    printf("Puede pasar sin pagar cover y recibe 2 bebidas gratis \n");
  }
  else if((c_genero == 'H' || c_genero == 'h') && i_edad <= 28) {
    printf("Paga $200 de cover y recibe 1 bebida gratis \n");
  }
  else if((c_genero == 'M' || c_genero == 'm') && i_edad <= 40) {
    printf("Paga $200 de cover y recibe 1 bebida gratis \n");
  }
  else if((c_genero == 'H' || c_genero == 'h') && i_edad <= 36) {
    printf("Paga $500 de cover \n");
  }
  else {
    printf("No puede entrar al bar, es muy viejo \n");
  }
  
  return 0;
}