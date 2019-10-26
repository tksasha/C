#include <stdio.h>

#include "sum.h"

int main() {
  int a, b;

  a = 2;
  b = 3;

  printf("%d\n", sum(&a, &b));

  return 0;
}
