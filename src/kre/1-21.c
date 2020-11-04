//
// Exercise 1-21 from the K&R Book
//

#include <stdio.h>

#include "strings.h"

int main() {
  char string[] = "a b  c   d    e";

  strings_entab(string, sizeof(string));

  printf("string: %s\n", string);
}
