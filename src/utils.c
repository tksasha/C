#include "utils.h"

void swap(int *x, int *y) {
  *x = *x + *y;

  *y = *x - *y;

  *x = *x - *y;
}

int max(int *array, int size) {
  int max = array[0];

  for(int i = 0; i < size; i++) {
    if(array[i] > max) {
      max = array[i];
    }
  }

  return max;
}

void sort(int *array, int size, short int mode) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(mode == DESC) {
        if(array[i] > array[j]) {
          swap(&array[i], &array[j]);
        }
      } else {
        if(array[j] > array[i]) {
          swap(&array[i], &array[j]);
        }
      }
    }
  }
}
