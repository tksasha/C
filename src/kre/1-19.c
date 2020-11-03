//
// Exercise 1-19 from the K&R Book
//

#include <stdio.h>

#include "strings.h"

int main() {
  char string[10];

  int character;

  printf("<< ");

  while((character = getchar()) != EOF) {
    if(character == '\n') {
      strings_reverse(string);

      printf(">> %s\n", string);

      strings_nullify(string, sizeof(string));

      printf("<< ");
    } else {
      strings_append(string, character, sizeof(string));
    }
  }

  printf("  \n");
}
