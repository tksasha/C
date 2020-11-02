#include <stdio.h>

//
// Exercise 1-17 from the K&R Book
//

#define SIZE 8
#define MAX 10

int main() {
  char string[MAX];

  int character;

  int counter = 0;

  printf("<< ");

  while((character = getchar()) != EOF) {
    if(character == '\n') {
      string[counter] = '\0';

      if(counter >= SIZE) {
        printf(">> %s\n", string);
      }

      string[0] = '\0';

      counter = 0;

      printf("<< ");

      continue;
    }

    if(counter < (MAX - 1)) {
      string[counter] = character;

      counter++;
    }
  }

  printf("  \n");
}
