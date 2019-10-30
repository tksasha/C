#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
  int *array;

  /* TODO: why it works?! */
  if((array = malloc(sizeof(int))) == NULL) {
    return -1;
  }

  for(int i = 0; i <= SIZE; i++) {
    array[i] = i * i;
  }

  for(int i = 0; i <= SIZE; i++) {
    printf("%d\n", array[i]);
  }

  free(array);

  return 0;
}
