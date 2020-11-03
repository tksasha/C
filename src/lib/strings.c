#include "chars.h"
#include "strings.h"

int ssize(char *string) {
  int size = 0;

  while(*string != '\0') {
    size++;

    string++;
  }

  return size;
}

void ssort(char *string, short int mode) {
  int size = ssize(string);

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(mode == DESC) {
        if(string[i] > string[j]) {
          cswap(&string[i], &string[j]);
        }
      } else {
        if(string[j] > string[i]) {
          cswap(&string[i], &string[j]);
        }
      }
    }
  }
}

void sappend(char *string, char character, int size) {
  for(int i = 0; i < size; i++) {
    if((string[i] == '\0') && (i < size - 1)) {
      string[i] = character;

      string[i + 1] = '\0';

      return;
    }
  }
}

void sreverse(char *string) {
  int size = ssize(string);

  for(int i = 0; i < (size / 2); i++) {
    int j = size - i - 1;

    cswap(&string[i], &string[j]);
  }
}
