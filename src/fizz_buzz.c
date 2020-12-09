#include <stdio.h>

//
// if digit divided by 3 print "digit: fizz"
//
// if digit divided by 5 print "digit: buzz"
//
// if digit divided by 3 and 5 print "digit: fizz buzz"
//

void variant_one(int limit);

void variant_two(int limit);

int main() {
  variant_one(16);

  variant_two(16);
}

void variant_one(int limit) {
  for(int i = 1; i < limit; i++) {
    if(i % 15 == 0) {
      printf("%2d: fizz buzz\n", i);
    } else if(i % 3 == 0) {
      printf("%2d: fizz\n", i);
    } else if(i % 5 == 0) {
      printf("%2d: buzz\n", i);
    }
  }
}

void variant_two(int limit) {
  short flag = 0;

  for(int i = 1; i < limit; i++) {
    if(i % 3 == 0) {
      printf("%2d: fizz", i);

      flag = 1;
    }

    if(i % 5 == 0) {
      if(flag) {
        puts(" buzz");

        flag = 0;
      } else {
        printf("%2d: buzz", i);

        flag = 1;
      }
    }

    if(flag) {
      putchar('\n');

      flag = 0;
    }
  }
}
