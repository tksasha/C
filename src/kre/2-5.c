#include <stdio.h>

//
// Exercise 2-5 from the K&R Book
//

int any(char one[], char two[]);

int main() {
  char one[] = "abcdefg";

  char two[] = "dbeac";

  printf("%d\n", any(one, two));
}

int any(char one[], char two[]) {
  for(int a = 0; two[a] != '\0'; a++) {
    for(int b = 0; one[b] != '\0'; b++) {
      if(one[b] == two[a]) {
        return b;
      }
    }
  }

  return -1;
}
