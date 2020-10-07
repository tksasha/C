#include <stdio.h>

#include "utils.h"

#define SIZE 10

//
// Maximum Example
//
int main() {
  int array[SIZE];

  for(int i = 0; i < SIZE; i++) {
    array[i] = i;
  }

  printf("%d\n", max(array, SIZE));

  return 0;
}
