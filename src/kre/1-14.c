#include <stdio.h>
#include <ctype.h>

//
// Exercise 1-14 from the K&R Book
//

#define SIZE  25 * 2
#define START 97
#define STEP   2

void init(int*);

void incr(int*, char);

void collect(int*);

void inspect(int*);

int maximum(int*);

void display(int*);

int main() {
  int stats[SIZE];

  init(stats);

  collect(stats);

  /* inspect(stats); */

  display(stats);

  return 0;
}

void init(int *array) {
  int letter = START;

  for(int i = 0; i < SIZE; i += STEP) {
    array[i] = letter;

    array[i + 1] = 0;

    letter++;
  }
}

void incr(int *array, char chrt) {
  if(isalpha(chrt) == 0) {
    return;
  }

  chrt = tolower(chrt);

  for(int i = 0; i < SIZE; i += STEP) {
    if(chrt == array[i]) {
      array[i + 1]++;
    }
  }
}

void collect(int *array) {
  int chrt;

  while((chrt = getchar()) != EOF) {
    if(isalpha(chrt)) {
      incr(array, chrt);
    }
  }
}

void inspect(int *array) {
  for(int i = 0; i < SIZE; i += STEP) {
    printf("%c: %d\n", array[i], array[i + 1]);
  }
}

int maximum(int *array) {
  int max = array[1];

  for(int i = 1; i < SIZE; i += STEP) {
    if(array[i] > max) {
      max = array[i];
    }
  }

  return max;
}

void display(int *array) {
  int max = maximum(array);

  for(int i = max; i > 0; i--) {
    printf("%d: ", i);

    for(int j = 1; j < SIZE; j += STEP) {
      if(array[j] >= i) {
        printf("# ");
      } else {
        printf("  ");
      }
    } 

    printf("\n");
  }

  printf("   ");

  for(int j = 0; j < SIZE; j += STEP) {
    printf("%c ", array[j]);
  } 

  printf("\n");
}
