#include <stdio.h>
#include <stdlib.h>

int main() {
  char a[] = "100";
  int  b = 0;

  b = (int)strtol(a, (char**)NULL, 2);

  printf("%d\n", b);

  b = (int)strtol(a, (char**)NULL, 10);

  printf("%d\n", b);

  return 0;
}
