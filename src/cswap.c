#include <stdio.h>

#include "chars.h"

int main() {
  char a = 'a';

  char b = 'Z';

  cswap(&a, &b);

  printf("%c\n", a);

  printf("%c\n", b);

  return 0;
}
