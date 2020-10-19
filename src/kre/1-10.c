#include <stdio.h>

//
// Exercise 1-10 from K&R Book
//
int main() {
  int chrt = 0;

  while((chrt = getchar()) != EOF) {
    switch(chrt) {
      case '\t':
        printf("\\t");
        break;
      case '\b':
        printf("\\b");
        break;
      case '\\':
        printf("\\\\");
        break;
      default:
        putchar(chrt);
    }
  }

  return 0;
}
