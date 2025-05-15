# stdlib
La librería stdlib en C (abreviatura de standard library) es una de las bibliotecas estándar más importantes del lenguaje.

## Gestión de memoria dinamica
Permite reservar, redimensionar y liberar memoria en tiempo de ejecución.
La memoria RAM es la que se utiliza durante la ejecución del programa, y es donde se almacenan las variables y estructuras de datos que se utilizan en el programa.

Esta memoria va desde la memoria baja a la alta y se segmenta en diferentes secciones que almacen diferentes tipos de datos.

### Segmentos de memoria

1.- **Segmento de código (text):** 
   - Contiene el código ejecutable del programa.
   - Es de solo lectura y no se puede modificar durante la ejecución.
   - Se define al compilar, por lo que su tamaño es fijo durante ejecución.
  
2.- **Segmento de datos (data):**
  - Contiene las variables globales y estáticas inicializadas.
  - Se reserva al inicio del programa y se libera al finalizar.
  - Se define al compilar, por lo que su tamaño es fijo durante ejecución.

3.- **Segmento BSS**
  - Contiene las variables globales y estáticas no inicializadas.
  - Se reserva al inicio del programa y se libera al finalizar.
  - Se define al compilar, por lo que su tamaño es fijo durante ejecución.

4.- **Heap (montón):**
  - Se utiliza para la asignación dinámica de memoria.
  - Se reserva y libera durante la ejecución del programa.
  - Su tamaño puede crecer y decrecer según sea necesario.
  - No se libera automáticamente al finalizar el programa, por lo que es importante liberar la memoria que ya no se necesita para evitar fugas de memoria.
  - Crece hacia direcciones de memoria altas.

5.- **Stack (pila):**
  - Se utiliza para almacenar variables locales y parámetros de funciones.
  - Se reserva y libera automáticamente al entrar y salir de funciones.
  - Su tamaño es limitado y se define al compilar.
  - Crece hacia direcciones de memoria bajas.

Entre el heap y el stack existe un espacio libre, el cual es utilizado por ambos. Esta es una de las razones por la que es importante liberar la memoria que ya no se necesita, ya que si el heap crece demasiado, puede sobrescribir la memoria del stack y causar un error de segmentación. (segmentation fault), o en el caso de una recursión muy profunda, el stack puede crecer demasiado y sobrescribir la memoria del heap.

### malloc()
La función **"malloc"**, abreviación de **"Memory Allocation"** es una función que reserva una cantidad de memoria en el **"heap"** (montón) y devuelve un puntero al inicio de esa memoria.

```c
// Sintaxis de malloc: 
void *malloc(size_t size);
```

- void: hace referencia a un puntero generico, lo que significa que puede apuntar a cualquier tipo de dato haciendo un casting.
- size_t: es un tipo de dato entero sin signo que representa el tamaño en bytes de la memoria que se desea reservar, se diferencia de un unsigned int ya que el tamaño de un tipo de dato size_t depende de la arquitectura del equipo; 4 bytes en arquitecturas de 32 bits (al igual que un unsigned int) y 8 bytes en arquitecturas de 64 bits.

```c
#include <stdlib.h>

int *ptr = (int *) malloc(sizeof(int));
```

