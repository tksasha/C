#include <stdio.h>

#include "utils.h"

int main() {
  int a, b;

  a = 2;
  b = 3;

  printf("%d\n", sum(&a, &b));

  swap(&a, &b);

  printf("a = %d, b = %d\n", a, b);

  return 0;
}
