#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//
// Exercise 1-13 from the K&R Book.
//

bool isSeparator(int *chrt);

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

bool isSeparator(int *chrt) {
  switch(*chrt) {
    case '\n':
    case '\t':
    case ' ' :
    case ':' :
    case '.' :
    case ',' :
    case '!' :
    case '?' :
      return true;
      break;
    default:
      return false;
  }
}

void collect(int *sizes, int *max) {
  int chrt = 0;
  int size = 0;

  int isFirstSpace = false;

  while((chrt = getchar()) != EOF) {
    if(isSeparator(&chrt)) {
      if(isFirstSpace == false) {
        isFirstSpace = true;

        sizes[size]++;

        if(size > *max) {
          *max = size;
        }

        size = 0;
      }
    } else {
      isFirstSpace = false;

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
