#include <stdio.h>

//
// Exercise 1-8 from K&R Book
//
// Write a program to count blanks, tabs and newlines
//
int main() {
  int chrt     = 0;
  int blanks   = 0;
  int tabs     = 0;
  int newlines = 0;

  while((chrt = getchar()) != EOF) {
    switch(chrt) {
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

  printf("blanks  : %d\n", blanks);
  printf("tabs    : %d\n", tabs);
  printf("newlines: %d\n", newlines);

  return 0;
}
