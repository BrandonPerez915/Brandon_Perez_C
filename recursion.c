#include <stdio.h>

int factorial(int num) {
  return num == 1 ? 1 : num * factorial(num-1);
}

// Convertir esta función iterativa a recursiva
int iterativeSum(int num) {
  int i, s = 0;
  for(i = num; i >= 1; i -= 2){
    s += 3 * i;
  }
  return s;
}

int recursiveSum(int num) {
  if(num <= 0) return 0;
  return 3 * num + recursiveSum(num - 2);
}

// Convertir esta función recursiva a iterativa
int recursiveSum2(int i, int n) {
  if(i > n) return 0;
}

int main() {
  printf("%d \n", recursiveSum(5));
}