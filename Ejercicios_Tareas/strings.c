#include <stdio.h>
#include <string.h>

int main() {
  char password[] = "Contraseña";
  char copy_password[strlen(password) + 1];
  // Copiar contraseña
  strcpy(copy_password, password);
  
  char nombre_usuario[20];
  printf("Ingrese el nombre de usuario: ");
  fgets(nombre_usuario, 20, stdin);

  if(strcmp(nombre_usuario, "admin") == 0){
    char input_password[8];
    printf("La contraseña debe ser de 8 caracteres y contener '#'\n");
    printf("Ingrese la contraseña: ");
    fgets(input_password, 8, stdin);
  }
  else printf("nada\n");
  return 0;
}
