#include <stdio.h>

//
// Exercise 1-8 from K&R Book
//
// Write a program to count blanks, tabs and newlines
//
int main() {
  int c = 0;

  long blanks   = 0;
  long tabs     = 0;
  long newlines = 0;

  while((c = getchar()) != EOF) {
    switch(c) {
      case ' ':
        blanks++;
        break;
      case '\t':
        tabs++;
        break;
      case '\n':
        newlines++;
        break;
    }
  }

  printf("blanks  : %ld\n", blanks);
  printf("tabs    : %ld\n", tabs);
  printf("newlines: %ld\n", newlines);

  return 0;
}
