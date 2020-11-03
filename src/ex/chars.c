#include <stdio.h>

#include "chars.h"

int main() {
  char a = 'a';

  char b = 'b';

  chars_swap(&a, &b);

  printf("a: %c\n", a);

  printf("b: %c\n", b);
}
