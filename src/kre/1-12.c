#include <stdio.h>

//
// Exercise 1-12 from the K&R Book.
//
int main() {
  int chrt = 0;
  int flag = 0;

  while((chrt = getchar()) != EOF) {
    switch(chrt) {
      case '\t':
      case '\n':
      case ' ':
      case '.':
      case ',':
        if(flag == 0) {
          flag = 1;

          putchar('\n');
        }

        break;
      default:
        flag = 0;

        putchar(chrt);
    }
  }

  return 0;
}
