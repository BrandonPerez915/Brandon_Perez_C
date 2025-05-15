// Write a function that will return the count of distinct 
// case-insensitive alphabetic characters and numeric digits 
// that occur more than once in the input string. The input 
// string can be assumed to contain only alphabets 
// (both uppercase and lowercase) and numeric digits.

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

short int *duplicate_count(const char *text) {
  short int i = 0;
  short int *characters = (short int*) calloc(36, sizeof(short int));
  while(text[i] != '\0') {
    if(text[i] >= 65 && text[i] <= 90) {
      characters[(int)text[i] - 65]++;
    }
    else if(text[i] >= 97 && text[i] <= 122) {
      characters[(int)text[i] - 97]++;
    }
    i++;
  }

  return characters;
}

int main() {
  char text[] = "aabbbccdde";
  short int *result = duplicate_count(text);
  for(int i = 0; i < 25; i++) {
    if(result[i] > 1) {
      printf("%c: %d\n", (char)(i + 65), result[i]);
    }
  }
  free(result);
  return 0;
}
