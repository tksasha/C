//
// Exercise 1-20 from the K&R Book
//

#include <stdio.h>

#include "strings.h"

int main() {
  char string[10] = "abc\tz";

  strings_detab(string, sizeof(string));

  printf("string: %s\n", string);
}
