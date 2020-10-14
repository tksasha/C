#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

#define SIZE 10

//
// Sorting Example
//
int main() {
  int array[SIZE];

  for(int i = 0; i < SIZE; i++) {
    array[i] = rand() % 100;
  }

  aisort(array, SIZE, ASC);

  printf("ASC\n");

  for(int i = 0; i < SIZE; i++) {
    printf("%d\n", array[i]);
  }

  aisort(array, SIZE, DESC);

  printf("DESC\n");

  for(int i = 0; i < SIZE; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}
