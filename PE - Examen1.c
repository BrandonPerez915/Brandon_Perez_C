#include <stdio.h>
/* 
Programacion Estructurada - Primavera 2025
Jueves 27 de Febrero 2025
Examen 1

  Instrucciones:
  Lee cuidadosamente todo el archivo, sigue las instrucciones y resuelve donde se te pida.
  Solo inserta código dentro de los espacios para respuesta.
*/

/*
  *Ejercicio 1:  /20 puntos
  *Ejercicio 2:  /15 puntos 
  *Ejercicio 3:  /15 puntos
*/

char alumno[200]="Brandon Michelle Pérez Salaña";

/* ============================================================ 
  EJERCICIO 1 (20 pts)
  Completa la funcion ejercicio1() para que capture de pantalla
  lo siguiente (con todo y el texto):

      Salario bruto = $512.58 Impuestos = 22%

  Lee el valor numerico del sueldo en una sola linea del scanf, y calcula el sueldo neto despues de restar los impuestos
  Expresa el valor exactamente de la siguiente manera:

      Sueldo neto = $      399.812

  Nota: 
    Hay 9 espacios entre el signo de pesos y donde comienza el numero
    siempre se muestran exactamente 3 decimales.
*/

void ejercicio1()
{
  // INICIO DE RESPUESTA:
    float salario_bruto, salario_neto;
    int impuestos;
    
    printf("Ingrese el salario bruto e impuestos: \n");
    // Leer el salario bruto e impuestos en el formato dado
    scanf("Salario bruto = $%f Impuestos = %d%%", &salario_bruto, &impuestos);
    
    // Calcular el salario neto
    salario_neto = salario_bruto - (salario_bruto * impuestos / 100);

    printf("Sueldo neto = $      %.3f", salario_neto);

  // FIN DE RESPUESTA
}
 

/* ============================================================ 
  EJERCICIO 2 (15 pts)
Define y codifica la funcion ejercicio02 para que reciba 3 numeros enteros
y devuelva cuál de los 3 numeros es el mas pequeño */

// INICIO DE RESPUESTA:
int ejercicio2(int num1, int num2, int num3)
{
  int menor;

  if (num1 < num2 && num1 < num3) {
    menor = num1;
  }
  else if (num2 < num1 && num2 < num3) {
    menor = num2;
  }
  else {
    menor = num3;
  }

  return menor;
}
  // FIN DE RESPUESTA


/* ============================================================ 
  EJERCICIO 3 (15 pts)
  */
  void ejercicio3()
  {
    int estudie = 0;
    int hice_tarea = 0;
    int me_ira_bien;
    int tengo_suerte = 0;
  
    //Convierte los siguientes condicionales en operadores ternarios 
    /*
    if (estudie || hice_tarea == 1) {
      me_ira_bien = 1;
    } else {
      if (!tengo_suerte) {
        me_ira_bien = 0;
      } else {
        me_ira_bien = 1;
      }
    }
    */

  // INICIO DE RESPUESTA
    me_ira_bien = (estudie || hice_tarea == 1) ? 1 : tengo_suerte ? 1 : 0;
  // FIN DE RESPUESTA

    //Convierte el siguiente operador ternario a un condicional simple (ifs) o switch
    //printf("Me fue %s\n", me_ira_bien ? "BIEN! :)" : "MAL :(\n");

  // INICIO DE RESPUESTA
    if (me_ira_bien) {
      printf("Me fue BIEN! :)\n");
    } else {
      printf("Me fue MAL :(\n");
    }
  // FIN DE RESPUESTA
 }

/* ============================================================ 
  Cuando termines el examen, sube tu .c a Canvas y contesta la Encuesta de Medio Termino.
*/

int main()
{
  /* Comenta o Descomenta los ejercicios conforme lo necesites, si alguno no lo logras
  terminar, dejalo comentado para que no de error de compilacion */
  printf("\e[1;1H\e[2J");  //limpia contenido de la pantalla
  printf("PROGRAMACION ESTRUCTURADA: EXAMEN PARCIAL 1\n\n");
  printf("Alumno: %s\n", alumno);
  
  printf("\t\t == Ejercicio 1: == \n");
  ejercicio1();
  printf("\n");

  printf("\t\t == Ejercicio 2: == \n");
  printf("El numero más pequeño es: %d",ejercicio2(10,-4,19));   //prueba con otros numeros, verifica ;) 
  printf("\n");

  printf("\t\t == Ejercicio 3: == \n");
  ejercicio3();
  printf("\n");

}
