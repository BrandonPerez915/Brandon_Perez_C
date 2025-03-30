#include <stdio.h>
#define L 25

int main() {
  char letras[L + 1];
  for(int i = 0; i < L; i++) {
    letras[i] = 97 + i;
    printf("%c", (char) 97 + i);
  }
  printf("\n%s\n", letras);
}