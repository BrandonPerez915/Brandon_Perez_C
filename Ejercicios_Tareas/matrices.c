#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 3
#define ROWS 3

unsigned short int columns = COLUMNS;
unsigned short int rows = ROWS;
int matrix1[ROWS][COLUMNS], matrix2[ROWS][COLUMNS], matrix3[ROWS][COLUMNS];

unsigned short int getRandom(int start, int end) {
  return start + rand() % (end - start); 
}

void fillMatrix(int matrix[][columns]) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      matrix[i][j] = getRandom(0,100);
    }
  }
}

void sumMatrix(int firstMatrix[][columns], int secondMatrix[][columns], int resultMatrix[][columns]) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
    }
  }
}

void printMatrix(int matrix[][columns]) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      printf("%3d  ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  fillMatrix(matrix1);
  fillMatrix(matrix2);

  sumMatrix(matrix1, matrix2, matrix3);

  printMatrix(matrix1);
  printf("\n");
  printMatrix(matrix2);
  printf("\n");
  printMatrix(matrix3);

  return 0;
}