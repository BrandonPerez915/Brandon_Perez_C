#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

void encode(char *encoded, const char *placas, char color, uint8_t velocidad_actual, uint8_t velocidad_permitida, char verificacion) {
    encoded[0] = '\0';  // Inicializar la cadena
    
    // La función strcat concatena dos cadenas de texto
    strcat(encoded, placas);

    // Buffer para convertir los valores a una cadena y poder concatenarlos
    char buffer[4];

    // La función sprintf formatea y almacena una cadena en un buffer 
    sprintf(buffer, "%c", color);
    strcat(encoded, buffer);

    sprintf(buffer, "%d", velocidad_actual);
    strcat(encoded, buffer);

    sprintf(buffer, "%c", verificacion);
    strcat(encoded, buffer);

    sprintf(buffer, "%d", velocidad_permitida);
    strcat(encoded, buffer);
}

void central(char *encoded) {
    char placas_obtenidas[7], color_vehiculo[10], color_obtenido, verificacion_obtenida;
    short unsigned int precio_por_km;
    uint8_t velocidad_permitida_obtenida, velocidad_actual_obtenida;
    float multa, multa_extra = 0;

    // sscanf se utiliza para leer datos de una cadena.
    sscanf(encoded, "%6s%c%hhu%c%hhu", placas_obtenidas, &color_obtenido, &velocidad_actual_obtenida, &verificacion_obtenida, &velocidad_permitida_obtenida);
    
    // Calcular el precio por km en relación a la velocidad excedida
    precio_por_km = 50 + 50 * (floor((velocidad_actual_obtenida - velocidad_permitida_obtenida - 1) / 20));

    // Convertir el color del vehículo a una cadena
    switch(color_obtenido) {
        case 'R':
            strcpy(color_vehiculo, "Rojo");
            break;
        case 'A':
            strcpy(color_vehiculo, "Azul");
            break;
        case 'B':
            strcpy(color_vehiculo, "Blanco");
            break;
        case 'N':
            strcpy(color_vehiculo, "Negro");
            break;
    }

    if(velocidad_actual_obtenida > velocidad_permitida_obtenida) {
        multa = precio_por_km * (velocidad_actual_obtenida - velocidad_permitida_obtenida);
        if(verificacion_obtenida == 'N') {
            multa_extra = multa * 0.5;
        }
    }
    else {
        if(verificacion_obtenida == 'N') {
            multa_extra = 1500.00;
        }
    }

    // Generación de la multa con el formato específico
    printf("\n\nInformación y placas del vehiculo:\n");
    printf("\tAuto %s, %s \n\n", color_vehiculo, placas_obtenidas);
    printf("Velocidad actual:                :      %u km / h\n", velocidad_actual_obtenida);
    printf("Limite de velocidad en via:      :      %hhu km / h\n", velocidad_permitida_obtenida);
    printf("Referendo                        :      %s\n\n", verificacion_obtenida == 'N' ? "Vencido":"Vigente");

    if(velocidad_actual_obtenida <= velocidad_permitida_obtenida && multa_extra == 0) {
        printf("No hay multa :) \n");
    }
    else {
        int total = 0;
        printf("Desgloce de multa:\n");
        if (velocidad_actual_obtenida > velocidad_permitida_obtenida) {
            printf("\t -    Exceso de velocidad (%d km x $%hu pesos)\n", velocidad_actual_obtenida - velocidad_permitida_obtenida, precio_por_km);
            printf("\t\t\t\t\t\t\t      $   %.2f MXN\n", multa);
            total += multa;
        }
        if (verificacion_obtenida == 'N') {
            printf("\t -    Sin referendo, 1.5x");
            printf("\t\t\t      $   +%.2f MXN\n", multa_extra);
            total += multa_extra;
        }
        printf("------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t    Total     $   %.2f MXN\n", (float) total);
    }
}

int main() {
    uint8_t velocidad_permitida; // 1 byte
    unsigned int velocidad_actual; // 4 bytes
    char placas[7], color, verificacion; // 7 bytes, 1 byte, 1 byte

    printf("Dame los datos de tu placa: ");
    // %hhu para leer un entero sin signo de 1 byte
    scanf("%6s %c [%d|%hhu] %c", placas, &color, &velocidad_actual, &velocidad_permitida, &verificacion);

    velocidad_actual = (unsigned int) ceil(velocidad_actual / 1000.0);

    // Variable donde se almacenan los datos codificados del vehículo
    char encoded[15]; // 15 bytes 
    encode(encoded, placas, color, (uint8_t) velocidad_actual, velocidad_permitida, verificacion);
    central(encoded);

    return 0;
}