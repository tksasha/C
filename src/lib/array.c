#include <stdio.h>

#include "array.h"
#include "integers.h"

int array_max(int *array, size_t size) {
  int max = array[0];

  for(int i = 0; i < size; i++) {
    if(array[i] > max) {
      max = array[i];
    }
  }

  return max;
}

void array_sort(int *array, size_t size, short int mode) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(mode == DESC) {
        if(array[i] > array[j]) {
          iswap(&array[i], &array[j]);
        }
      } else {
        if(array[i] < array[j]) {
          iswap(&array[i], &array[j]);
        }
      }
    }
  }
}
