#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 9
#define WIDTH 4
#define TRIPLE(x) ((x) * 3)

int matrix1[LENGTH][WIDTH], matrix2[WIDTH][LENGTH];
int length = LENGTH, width = WIDTH;

int getRandom(int start, int end) {
  return rand() % end + start;
}

void fillRandomColumn(int matrix[][width], int column) {
  for(int i = 0; i < length; i++) {
    matrix[i][column] = getRandom(1,10);
  }
}

void fillColumn(int matrix[][width], int column) {
  for(int i = 0; i < length; i++) {
    matrix[i][column] = TRIPLE(matrix[i][column - 1]);
  }
}

void transposeMatrix(int matrix[][width], int transpose[][length]){
  for(int i = 0; i < width; i++) {
    for(int j = 0; j < length; j++) {
      transpose[i][j] = matrix[j][i];
    }
  }
}

void printMatrix(int matrix[][width]) {
  for(int i = 0; i < length; i++) {
    printf("|  ");
    for(int j = 0; j < width; j++) {
      printf("%8d", matrix[i][j]);
    }
    printf("  | \n");
  }
}

int main() {
  srand(time(NULL));
  // Generar aleatoreamente los elementos de la primera columna
  fillRandomColumn(matrix1, 0);
  // Generar la matriz con base a los elementos de la primera columna
  for(int i = 1; i < WIDTH; i++) {
    fillColumn(matrix1, i);
  }

  printf("Matriz generada \n");
  printMatrix(matrix1);

  transposeMatrix(matrix1, matrix2);
  length = WIDTH;
  width = LENGTH;

  printf("\n\nMatriz transpuesta\n");
  printMatrix(matrix2);

  return 0;
}