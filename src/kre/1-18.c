//
// Exercise 1-18 from the K&R Book
//

#include <stdio.h>

#include "strings.h"

#define SIZE 10

void collect(char *string, size_t size);

int main() {
  char string[SIZE];

  collect(string, sizeof(string));

  printf("  \n");
}

void collect(char *string, size_t size) {
  int character;

  printf("<< ");

  while((character = getchar()) != EOF) {
    if(character == '\n') {
      strings_rstrip(string);

      printf(">> `%s`\n", string);

      strings_nullify(string, size);

      printf("<< ");
    } else {
      strings_append(string, character, size);
    }
  }
}
