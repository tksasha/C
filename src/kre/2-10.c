#include <stdio.h>

//
// Exercise 2-10 from the K&R Book
//

char lower(char letter);

int main() {
  for(int i = 'A'; i <= 'Z'; i++) {
    printf("%c", lower(i));
  }

  putchar('\n');
}

char lower(char letter) {
  return (letter >= 'A' && letter <= 'Z') ? letter + 32 : letter;
}
