#include <stdio.h>

#include "arrays.h"

#define SIZE 10

//
// Maximum Example
//
int main() {
  int array[SIZE];

  for(int i = 0; i < SIZE; i++) {
    array[i] = i;
  }

  printf("%d\n", aimax(array, SIZE));

  return 0;
}
