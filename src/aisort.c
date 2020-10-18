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

  printf(" ASC: ");

  for(int i = 0; i < SIZE; i++) {
    printf("%2d ", array[i]);
  }

  printf("\n");

  aisort(array, SIZE, DESC);

  printf("DESC: ");

  for(int i = 0; i < SIZE; i++) {
    printf("%2d ", array[i]);
  }

  printf("\n");

  return 0;
}
