#include <stdio.h>
#include <string.h>

#define NULO -1
// Para aumentar el tamaño del inventario modificar este define
#define NUMERO_PRODUCTOS 25 
// Para aumentar el numero de ordenes modificar este define
#define NUMERO_ORDENES 10

typedef enum {

  Ninguno = 'N',
  Fragil = 'F',
  Alcohol = 'A',
  Peligroso = 'P',
  Comida = 'C'

} Especial;

typedef struct {

  char nombre[31];
  char sku[11];
  float peso;
  Especial tipoEspecial;
  int cajasDisponibles;

} Producto;

typedef struct {

  char sku[11];
  int cajaSolicitadas;

} Orden;

// Variables globales del programa (inventario)
Producto productos[NUMERO_PRODUCTOS];

Producto generarProducto(char nombre[], char sku[], float peso, Especial tipo , int cajasDisponibles) {
  // Inicialización del producto
  Producto producto;

  // Copiar cadenas de texto
  strcpy(producto.nombre, nombre);
  strcpy(producto.sku, sku);

  producto.peso = peso;
  producto.tipoEspecial = tipo;
  producto.cajasDisponibles = cajasDisponibles;

  return producto;
}

void inicializarInventario(int totalProductos) {

  for(int i = 0; i < totalProductos; i++) {
    strcpy(productos[i].nombre, "LIBRE");
    strcpy(productos[i].sku, "LIBRE");

    productos[i].cajasDisponibles = 0;
    productos[i].peso = 0;
    productos[i].tipoEspecial = Ninguno;
  }
}

void mostrarInventario(int totalProductos, char titulo[]) {
  printf("\n====================== %s ======================\n\n", titulo);

  for(int i = 0; i < totalProductos; i++) {
    // Si el espacio esta libre no imprimir nada
    if (strcmp(productos[i].nombre, "LIBRE") == 0) continue;
    
    else {
      printf("%d %s %s\n", 
        productos[i].cajasDisponibles, 
        productos[i].cajasDisponibles > 1 ? "cajas" : "caja",
        productos[i].nombre
      );
    }
  }
}

// Buscar un elemento en los productos, retorna el index de incidencia o NULO
// En caso de no coincidir con ningun elemento
int buscarElemento(Producto productos[], int totalProductos, char sku[]) {
  for(int i = 0; i < totalProductos; i++) {
    if(strcmp(productos[i].sku, sku) == 0) return i;
  }
  return NULO;
}

void llenarTransporte(Orden ordenes[NUMERO_ORDENES], double pesoPermitido, char articulosProhibidos[]) {
  double pesoActual = 0;
  int cajasEnviadas = 0, tiposProductos = 0;

  printf("\n================== Detalles del envio ==================\n\n");
  for(int i = 0; i < NUMERO_ORDENES; i++) {
    int indexElemento = buscarElemento(productos, NUMERO_PRODUCTOS, ordenes[i].sku);

    // Comprobar existencia del elemento
    if(indexElemento != NULO) {

      double pesoOrden = ordenes[i].cajaSolicitadas * productos[indexElemento].peso;
      // Conversión del tipo a una cadena de texto ('\0') para realizar comparaciones 
      char tipoEspecial[] = { productos[indexElemento].tipoEspecial, '\0' };

      // Comprobar que existan productos prohibidos y que el producto no 
      // este prohibido (Es una subcadena strstr())
      if(
        articulosProhibidos != NULL &&
        strstr(articulosProhibidos, tipoEspecial) != NULL
      ) {
        printf("%d %s de %s %s RECHAZADO - Producto especial no permitido\n", 
          ordenes[i].cajaSolicitadas, 
          ordenes[i].cajaSolicitadas > 1 ? "cajas" : "caja",
          productos[indexElemento].nombre,
          productos[indexElemento].sku
        );
      }

      else if(ordenes[i].cajaSolicitadas > productos[indexElemento].cajasDisponibles) {
        printf("%d %s de %s %s RECHAZADO - No hay suficientes cajas\n", 
          ordenes[i].cajaSolicitadas, 
          ordenes[i].cajaSolicitadas > 1 ? "cajas" : "caja",
          productos[indexElemento].nombre,
          productos[indexElemento].sku
        );
      }

      else if(pesoOrden + pesoActual > pesoPermitido) {
        printf("%d %s de %s %s RECHAZADO - Peso excede el limite\n", 
          ordenes[i].cajaSolicitadas, 
          ordenes[i].cajaSolicitadas > 1 ? "cajas" : "caja",
          productos[indexElemento].nombre,
          productos[indexElemento].sku
        );
      }

      else {
        pesoActual += pesoOrden;
        cajasEnviadas += ordenes[i].cajaSolicitadas;
        tiposProductos += 1;
        // Descontar las cajas del pedido aprobado al inventario
        productos[indexElemento].cajasDisponibles -= ordenes[i].cajaSolicitadas;
        printf("%d %s de %s %s APROBADO\n", 
          ordenes[i].cajaSolicitadas, 
          ordenes[i].cajaSolicitadas > 1 ? "cajas" : "caja",
          productos[indexElemento].nombre,
          productos[indexElemento].sku
        );
      }
    }
    // SKU no encontrado en la lista de productos
    else {
      printf("SKU %s RECHAZADO - SKU invalido\n", ordenes[i].sku);
    }
  }
  printf("\n================== Resumen del envio ===================\n\n");
  printf("Total de cajas enviadas: %d\n", cajasEnviadas);
  printf("Peso total: %.2lf\n", pesoActual);
  printf("Tipos diferentes de productos: %d\n", tiposProductos);
}
            
int main(){
  inicializarInventario(NUMERO_PRODUCTOS);
  productos [0] = generarProducto ("Manguerapara casa","RainB-0123",58.2,Ninguno,2);
  productos [1]= generarProducto ("industrial","RainB-0589",121,Peligroso,800);
  productos [2] = generarProducto ("Tequila Don Julio","TDonJ-8945",88.5,Alcohol,180);
  productos [3] = generarProducto ("Tequila Don Julio Añejo","TDonJ-9801",88.5, Alcohol,3);
  productos [4] = generarProducto ("Atun enlatado","Atuny-4321",23.1,Comida,37);
  productos [5] = generarProducto ("Salmon fresco","Atuny-1234",12.8,Comida,50);
  productos [6] = generarProducto ("Vasos para fiesta","Liver-3001",2.0, Fragil,999);
  productos [7] = generarProducto ("Florero de cristal","House-2587",1.8, Fragil,7);
  productos [8] = generarProducto ("Desinfectante industrial B1122","Diall-1122",801.2, Peligroso,621);
  productos [9] = generarProducto ("Computadora portatil","Toshi-8945",18.5, Ninguno,15);
  productos [10] = generarProducto ("Pantalla de 52 pulgadas","Toshi-4512",15.1,Fragil,125);
  productos [11] = generarProducto ("Manzana gala","Apple-5555",3.2,Comida,462);

  Orden ordenes[10] = {
    {"RainB-0589", 100},
    {"TDonJ-8945", 180},
    {"Apple-5555", 100},
    {"Atuny-4321", 40},
    {"Liver-3001", 200},
    {"House-2587", 8},
    {"Diall-1122", 1},
    {"Toshi-8945", 16},
    {"Fake-00001", 5},
    {"TDonJ-9801", 1}
  };

  mostrarInventario(NUMERO_PRODUCTOS, "Inventario");
  llenarTransporte(ordenes, 15000.0, NULL);
  mostrarInventario(NUMERO_PRODUCTOS, "Inventario despues del envio");
}