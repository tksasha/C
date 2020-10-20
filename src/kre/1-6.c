#include <stdio.h>

//
// Exercise 1-6 from the K&R Book
//
int main() {
  int c;

  c = getchar() != EOF;

  printf("%d\n", c);

  return 0;
}
