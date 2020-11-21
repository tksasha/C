#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "char.h"
#include "string.h"

int string_size(char *string) {
  int size = 0;

  while(*string != '\0') {
    size++;

    string++;
  }

  return size;
}

void string_sort(char *string, short int mode) {
  int size = string_size(string);

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(mode == DESC) {
        if(string[i] > string[j]) {
          char_swap(&string[i], &string[j]);
        }
      } else {
        if(string[j] > string[i]) {
          char_swap(&string[i], &string[j]);
        }
      }
    }
  }
}

void string_append(char *string, char character, size_t size) {
  for(int i = 0; i < size - 1; i++) {
    if(string[i] == '\0') {
      string[i] = character;

      string[i + 1] = '\0';

      return;
    }
  }
}

void string_reverse(char *string) {
  int size = string_size(string);

  for(int i = 0; i < (size / 2); i++) {
    int j = size - i - 1;

    char_swap(&string[i], &string[j]);
  }
}

void string_copy(char *src, char *dst, size_t dstsize) {
  for(int i = 0; i < dstsize - 1; i++) {
    if(src[i] != '\0') {
      dst[i] = src[i];
    }
  }

  dst[dstsize - 1] = '\0';
}

void string_nullify(char *string, size_t size) {
  for(int i = 0; i < size; i++) {
    string[i] = '\0';
  }
}

void string_rstrip(char *string) {
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

void string_entab(char *string, size_t size) {
  char temp[size];

  int spaces = 0;

  for(int i = 0; string[i] != '\0'; i++) {
    if(string[i] == SPACE) {
      spaces++;

      if(spaces == TABSTOP) {
        string_append(temp, TAB, size);

        spaces = 0;
      }
    } else {
      while(spaces > 0) {
        string_append(temp, SPACE, size);

        spaces--;
      }

      string_append(temp, string[i], size);
    }
  }

  string_nullify(string, size);

  string_copy(temp, string, size);
}

void string_detab(char *string, size_t size) {
  char temp[size];

  string_nullify(temp, size);

  for(int i = 0; string[i] != '\0'; i++) {
    if(string[i] == TAB) {
      for(int j = 0; j < TABSTOP; j++) {
        string_append(temp, SPACE, size);
      }
    } else {
      string_append(temp, string[i], size);
    }
  }

  string_nullify(string, size);

  string_copy(temp, string, size);
}

void string_only_letters(char str[]) {
  int j = 0;

  for(int i = 0; str[i] != '\0'; i++) {
    if(char_is_letter(str[i])) {
      str[j++] = str[i];
    }
  }

  str[j] = '\0';
}

void string_downcase(char str[]) {
  for(int i = 0; str[i] != '\0'; i++) {
    if(char_is_letter(str[i]) && char_is_uppercase(str[i])) {
      str[i] = char_downcase(str[i]);
    }
  }
}
