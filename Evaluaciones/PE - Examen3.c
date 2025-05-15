/* 
Programacion Estructurada - Primavera 2025
Jueves 15 de Mayo 2025
Evaluación Síncrona #3

  Instrucciones:
  Lee cuidadosamente todo el archivo, sigue las instrucciones y resuelve donde se te pida.
  Solo inserta código dentro de los espacios para respuesta.
*/

//Prohibido añadir cualquier otra librería estándar
#include <stdio.h>
#include <string.h>

char alumno[99] = "Brando Michelle Pérez Saldaña";

/*
  *Ejercicio 1:  /15 puntos
  *Ejercicio 2:  /15 puntos 
  *Ejercicio 3:  /15 puntos
  *Ejercicio 4:  /15 puntos
*/

// EJERCICIO 1 - RH  (15 pts)

// Recursos Humanos te está pidendo ayuda para diseñar las estructuras que serán usadas para guardar la información de los empleados de tu empresa.
// Crea las siguientes estructuras:

//   1. Una estructura Puesto, que contenga los siguientes campos:
//     * Nombre (máximo de 50 caracteres).
//     * Salario mensual (Número positivo con decimales).
//     * Número de vacantes (Entero positivo)

//   2. Una estructura Empleado, que debe contener los siguientes campos:
//     * ID empleado (Entero positivo)
//     * Nombre (máximo de 50 caracteres). 
//     * Puesto (Estructura Puesto)

// En el main, crea un solo empleado con toda la información necesaria. 
// Luego, imprime en la consola la siguiente información de la estructura que creaste:

// 1. Nombre del empleado.
// 2. Salario mensual.
// 3. Nombre de puesto


// INICIO DE RESPUESTA: (Aquí van tus estructuras)
typedef struct {
  char nombre[51];
  float salario;
  unsigned int vacantes;
} Puesto;

typedef struct {
  unsigned int id;
  char nombre[51];
  Puesto puesto;
} Empleado;

// FIN DE RESPUESTA

// EJERCICIO 2 - Concat (15 pts)
// Escribe una función llamada "concat" que reciba dos cadenas de texto target, source.
// La función deberá añadir el contenido de source al final de la cadena target. 
// Suponga que target tiene suficiente espacio para almacenar todo, incluyendo el caracter fin de cadena de source.
// - Prohibido usar funciones de String.h-  
void concat(char target[], char source[]) {
  int i = 0, target_length = 0;
  while(target[i] != '\0') {
    target_length++;
    i++;
  }

  i = 0;
  while(source[i] != '\0') {
    target[target_length + i] = source[i];
    i++;
  }
}
// INICIO DE RESPUESTA: (Aquí va tu función)

// FIN DE RESPUESTA

  // EJERCICIO 3 - (15 pts)

  // La empresa detrás del exitoso juego de Marvel Rivals te ha contratado para que generes un programa para determinar quál el personaje más usado en cada continente del planeta.
  // Crea una funcion llamda "ejercicio3" que reciba los siguientes parámetros en ese orden:
  //   1. La matriz con los votos donde cada fila representa un personaje y cada columna un continente (tamaño de columnas es estático - ver MAX_COLUMNAS)
  //   2. El número de filas
  //   3. Un arreglo con los nombres de los continentes (columnas)(20 caracteres maximos)
  //   4. Un arreglo con los nombres de los superheroes (filas)(20 caracteres maximos)
  
  //   La función deberá revisar cada columna e imprimir en pantalla el nombre del heroe más popular.

  //   Output esperado:
  //   El heroe favorito en Africa es Iron Man
  //   El heroe favorito en America es Spider-Man
  //   El heroe favorito en Asia es Groot
  //   El heroe favorito en Europa es Mantis
  //   El heroe favorito en Oceania es Cloak & Dagger

  #define MAX_COLUMNAS 5
  #define MAX_FILAS 6

  // INICIO DE RESPUESTA: (Aquí va tu función)
  void ejercicio3(int votos[MAX_FILAS][MAX_COLUMNAS], char continentes[][20], char heroes[][20]) {
    for(int i = 0; i < MAX_COLUMNAS; i++) {
      int max_value = 0;
      int max_value_index = 0;

      for(int j = 0; j < MAX_FILAS; j++) {
        if(votos[j][i] > max_value) {
          max_value = votos[j][i];
          max_value_index = j;
        }
      }
      printf("El heroe favorito en %s es %s\n", continentes[i], heroes[max_value_index]);
    }
  }
  // FIN DE RESPUESTA

int main()
{
  printf("\e[1;1H\e[2J");  //limpia contenido de la pantalla
  printf("PROGRAMACION ESTRUCTURADA: EVALUACION SINCRONA #3\n");
  printf("Alumno: %s\n\n", alumno);
  
  printf("\t\t == Ejercicio 1: RH == \n");
  // EJERCICIO 1: (Aquí van la inicialización e impresión de tu "Empleado")
  Puesto puesto_empleado = {"Manager", 70000.570, 7};
  Empleado empleado = {18793, "Jorge", puesto_empleado};
  printf("Nombre: %s\n", empleado.nombre);
  printf("Sueldo: %f\n", empleado.puesto.salario);
  printf("Puesto: %s\n", empleado.puesto.nombre);
  printf("\n");
  // FIN EJERCICIO 1

  printf("\t\t == Ejercicio 2: Concat == \n");
  // EJERCICIO 2
  char tar[30]   = "Ya se acabo"; 
  char src[15]   = " el semestre!"; 
  concat(tar,src); 
  printf("%s\n",tar); //Si tu función concat está bien, esto debe imprimir en pantalla "Ya se acabo el semestre!"
  printf("\n");
  // FIN EJERCICIO 2

    printf("\t\t == Ejercicio 3: Marvel Rivals == \n");
  // EJERCICIO 3
    char continentes[MAX_COLUMNAS][20] = {"Africa", "America", "Asia", "Europa", "Oceania"};
    char heroes[MAX_FILAS][20] = {"Iron Man", "Spider-Man", "Groot", "Mantis", "Cloak & Dagger", "Capitan America"};
    int votos[MAX_FILAS][MAX_COLUMNAS] = {
      {90, 20, 30, 35, 55},
      {15, 95, 50, 10, 20},
      {50, 10, 99, 55, 0},
      {40, 0, 80, 100, 35},
      {30, 20, 30, 25, 105},
      {5, 25, 75, 30, 65}
  };
    ejercicio3(votos,continentes,heroes);
    printf("\n");
  // FIN EJERCICIO 3
}