#include <stdio.h>

#include "integers.h"

//
// Swap Example
//
int main() {
  int x = 42;

  int y = 69;

  iswap(&x, &y);

  printf("%d\n", x);

  printf("%d\n", y);

  return 0;
}
