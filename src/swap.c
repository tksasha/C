#include <stdio.h>

#include "utils.h"

//
// Swap Example
//
int main() {
  int x = 3;

  int y = 2;

  swap(&x, &y);

  printf("%d\n", x);

  printf("%d\n", y);

  return 0;
}
