#include <stdio.h>

int factorial(int num) {
  return num == 1 ? 1 : num * factorial(num-1);
}

int main() {
  printf("%d \n", factorial(6));
}