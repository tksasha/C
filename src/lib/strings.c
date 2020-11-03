#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "chars.h"
#include "strings.h"

int strings_size(char *string) {
  int size = 0;

  while(*string != '\0') {
    size++;

    string++;
  }

  return size;
}

void strings_sort(char *string, short int mode) {
  int size = strings_size(string);

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

void strings_append(char *string, char character, size_t size) {
  for(int i = 0; i < size; i++) {
    if((string[i] == '\0') && (i < size - 1)) {
      string[i] = character;

      string[i + 1] = '\0';

      return;
    }
  }
}

void strings_reverse(char *string) {
  int size = strings_size(string);

  for(int i = 0; i < (size / 2); i++) {
    int j = size - i - 1;

    cswap(&string[i], &string[j]);
  }
}

void scopy(char *src, char *dst, size_t dstsize) {
  for(int i = 0; i < dstsize; i++) {
    printf("i: %c\n", src[i]);

    if(src[i] != '\0') {
      dst[i] = src[i];
    }
  }

  dst[dstsize] = '\0';
}

void strings_nullify(char *string, size_t size) {
  for(int i = 0; i < size; i++) {
    string[i] = '\0';
  }
}

void strings_rstrip(char *string) {
  bool is_space = false;

  int space_idx = 0;

  for(int i = 0; string[i] != '\0'; i++) {
    if(isspace(string[i])) {
      if(is_space == false) {
        space_idx = i;

        is_space = true;
      }
    } else {
      space_idx = 0;

      is_space = false;
    }
  }

  if(is_space) {
    string[space_idx] = '\0';
  }
}
