void swap(int *x, int *y) {
  *x = *x + *y;

  *y = *x - *y;

  *x = *x - *y;
}

int max(int *array, long size) {
  int max = array[0];

  for(int i = 0; i < size; i++) {
    if(array[i] > max) {
      max = array[i];
    }
  }

  return max;
}
