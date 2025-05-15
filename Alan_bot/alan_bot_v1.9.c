#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAY_LENGTH 20

int numbers[ARRAY_LENGTH];
int invertedNumbers[ARRAY_LENGTH];

void createArray(int length) {
  for(int i = 0; i < length; i++) {
    numbers[i] = rand() % 100;
  }
}

int min(int array[], int length) {
  int min = INT_MAX;
  for(int i = 0; i < length; i++) {
    if(array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

float average(int array[], int length) {
  int sum = 0;
  for(int i = 0; i < length; i++) {
    sum += array[i];
  }
  return (float) sum / length;
}

void invertArray(int originalArray[], int invertedArray[], int length) {
  for(int i = 0; i < length; i++) {
    invertedArray[length - 1 - i] = originalArray[i];
  }
}

int main() {
  srand(time(NULL));

  createArray(ARRAY_LENGTH);

  printf("Elementos del array: ");
  for(int i = 0; i < ARRAY_LENGTH; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n\n");

  printf("Minimo del array: %d \n\n", min(numbers, ARRAY_LENGTH));
  printf("Promedio del array: %.2f \n\n", average(numbers, ARRAY_LENGTH));

  invertArray(numbers, invertedNumbers, ARRAY_LENGTH);
  printf("elementos del array invertido: ");
  for(int i = 0; i < ARRAY_LENGTH; i++) {
    printf("%d ", invertedNumbers[i]);
  }
  printf("\n\n");

  return 0;
}
