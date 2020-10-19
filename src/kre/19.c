#include <stdio.h>

//
// Exercise 1-9 from K&R Book.
//
// Write a program to its input to its output,
// replacing each string of one or more blanks by a single blank.
//
int main() {
  int chrt   = 0;
  int spaces = 0;

  while((chrt = getchar()) != EOF) {
    if(chrt == ' ') {
      spaces++;
    } else {
      spaces = 0;
    }

    if(spaces <= 1) {
      putchar(chrt);
    }
  }

  return 0;
}
