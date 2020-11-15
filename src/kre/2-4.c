#include <stdio.h>

//
// Exercise 2-4 from the K&R Book
//

void squeeze(char one[], char two[]);

int main() {
  char one[] = "abcdefg";

  char two[] = "dbeac";

  squeeze(one, two);

  printf("%s\n", one);
}

void squeeze(char one[], char two[]) {
  int a, b;

  for(int i = 0; two[i] != '\0'; i++) {
    for(a = b = 0; one[a] != '\0'; a++) {
      if(one[a] != two[i]) {
        one[b++] = one[a];
      }
    }

    one[b] = '\0';
  }
}
