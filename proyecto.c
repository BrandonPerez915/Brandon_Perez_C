#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s_datos_vehiculo[50];
    char *c_iterador;

    printf("Ingrese los datos del vehiculo (placas, modelo, etc.): \n");
    
    // fgets toma 3 parámetros:
    // 1.- La variable donde se guarda
    // 2.- La cantidad espacio de los datos a recuperar
    // 3.- Tipo de entrada de datos; stdin = standard input
    fgets(s_datos_vehiculo, sizeof(s_datos_vehiculo), stdin);

    // Eliminar el salto de línea, si está presente
    s_datos_vehiculo[strcspn(s_datos_vehiculo, "\n")] = '\0';

    // Separamos usando el espacio como delimitador
    c_iterador = strtok(s_datos_vehiculo, " ");

    // Aseguramos que todas las variables tengan espacio suficiente
    char s_placas[7], c_color[2], c_velocidades[13], c_verificacion_vehicular[2]; 
    int i_longitud_cadena = strlen(c_velocidades);
    
    strcpy(s_placas, c_iterador);
    c_iterador = strtok(NULL, " ");
    strcpy(c_color, c_iterador);
    c_iterador = strtok(NULL, " "); 
    strcpy(c_velocidades, c_iterador);

    // Si se quiere eliminar el primer y último carácter de c_velocidades:
    if (i_longitud_cadena > 2) {
        memmove(c_velocidades, c_velocidades + 1, i_longitud_cadena - 2);
        c_velocidades[i_longitud_cadena - 2] = '\0';
    }

    c_iterador = strtok(NULL, " ");
    strcpy(c_verificacion_vehicular, c_iterador);

    printf("Placas: %s\nColor: %s\nVerificaion vehicular: %s\n", s_placas, c_color, c_velocidades, c_verificacion_vehicular);

    return 0;
}

