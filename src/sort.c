#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define SIZE 10

void sort_asc(int *array, long size);

void sort_desc(int *array, long size);

//
// Sorting Example
//
int main() {
  int array[SIZE];

  for(int i = 0; i < SIZE; i++) {
    array[i] = rand() % 100;
  }

  sort_asc(array, SIZE);

  printf("ASC\n");

  for(int i = 0; i < SIZE; i++) {
    printf("%d\n", array[i]);
  }

  sort_desc(array, SIZE);

  printf("DESC\n");

  for(int i = 0; i < SIZE; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}

void sort_asc(int *array, long size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(array[j] > array[i]) {
        swap(&array[i], &array[j]);
      }
    }
  }
}

void sort_desc(int *array, long size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(array[i] > array[j]) {
        swap(&array[i], &array[j]);
      }
    }
  }
}
