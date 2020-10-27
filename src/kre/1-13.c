#include <stdio.h>
#include <ctype.h>

//
// Exercise 1-13 from the K&R Book
//

#define SIZE 10

void nullify(int*);

void increment(int*, int);

void collect(int*);

void inspect(int*);

void horizontal(int*);

void vertical(int*);

int maximum(int*);

int main() {
  int sizes[SIZE];

  nullify(sizes);

  collect(sizes);

  inspect(sizes);

  printf("\nHorizontal:\n");

  horizontal(sizes);

  printf("\nVertical:\n");

  vertical(sizes);

  return 0;
}

void nullify(int *array) {
  for(int i = 0; i < SIZE; i++) {
    array[i] = 0;
  }
}

void collect(int *array) {
  int c;

  int size = 0;

  while((c = getchar()) != EOF) {
    if(isalnum(c)) {
      size++;
    } else {
      increment(array, size);

      size = 0;
    }
  }
}

void increment(int *array, int idx) {
  if(idx < SIZE) {
    array[idx - 1]++;
  } else {
    array[SIZE - 1]++;
  }
}

void inspect(int *array) {
  printf("[ \n");

  for(int i = 0; i < SIZE; i++) {
    printf("\t{ size: ");

    if(i != (SIZE - 1)) {
      printf("%4d", (i + 1));
    } else {
      printf(">=10");
    }

    printf(", count: %2d }\n", array[i]);
  }

  printf("]\n");
}

void horizontal(int *array) {
  for(int i = (SIZE - 1); i >= 0; i--) {
    if(i == (SIZE - 1)) {
      printf(">=10: ");
    } else {
      printf("%4d: ", (i + 1));
    }

    for(int j = 0; j < array[i]; j++) {
      printf("#");
    }

    printf("\n");
  }
}

void vertical(int *array) {
  int max = maximum(array);

  for(int i = max; i > 0; i--) {
    printf("%d: ", i);

    for(int j = 0; j < SIZE; j++) {
      if(array[j] >= i) {
        printf("# ");
      } else {
        printf("  ");
      }
    }

    printf("\n");
  }

  printf("  ");

  for(int i = 0; i < SIZE; i++) {
    if(i == (SIZE - 1)) {
      printf(" >=10");
    } else {
      printf(" %d", (i + 1));
    }
  }

  printf("\n");
}

int maximum(int *array) {
  int max = array[0];

  for(int i = 0; i < SIZE; i++) {
    if(array[i] > max) {
      max = array[i];
    }
  }

  return max;
}
