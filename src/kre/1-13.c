#include <stdio.h>
#include <stdlib.h>

//
// Exercise 1-13 from the K&R Book.
//

void collect(int *sizes, int *max);

void display(int *sizes, int *max);

int main() {
  int max  = 0;

  int *sizes;

  if((sizes = malloc(sizeof(int))) == NULL) {
    return -1;
  }

  collect(sizes, &max);

  display(sizes, &max);

  return 0;
}

void collect(int *sizes, int *max) {
  int chrt = 0;
  int size = 0;
  int flag = 0;

  while((chrt = getchar()) != EOF) {
    switch(chrt) {
      case '\t':
      case '\n':
      case ' ':
        if(flag == 0) {
          flag = 1;

          sizes[size]++;

          if(size > *max) {
            *max = size;
          }

          size = 0;
        }
        break;
      default:
        flag = 0;

        size++;
    }
  }
}

void display(int *sizes, int *max) {
  for(int i = *max; i >= 1; i--) {
    printf("%d: ", i);

    for(int j = 1; j <= sizes[i]; j++) {
      printf("*");
    }

    printf("\n");
  }
}
