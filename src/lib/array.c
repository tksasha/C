#include <stdio.h>

#include "array.h"
#include "integer.h"

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
          integer_swap(&array[i], &array[j]);
        }
      } else {
        if(array[i] < array[j]) {
          integer_swap(&array[i], &array[j]);
        }
      }
    }
  }
}

int array_shift(int *array, size_t size) {
  int result = array[0];

  for(int i = 0; i < size - 1; i++) {
    array[i] = array[i + 1];
  }

  array[size - 1] = 0;

  return result;
}

void array_unshift(int *array, int el, size_t size) {
  for(int i = size - 1; i >= 0; i--) {
    if(i == 0) {
      array[i] = el;
    } else {
      array[i] = array[i - 1];
    }
  }
}

void array_inspect(int *array, size_t size) {
  putchar('[');

  for(int i = 0; i < size; i++) {
    printf("%d", array[i]);

    if(i < size - 1) {
      printf(", ");
    }
  }

  printf("]\n");
}
