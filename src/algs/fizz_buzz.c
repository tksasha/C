#include <stdio.h>

//
// Complexity O(n)
//
// if digit divided by 3 print "digit: fizz"
//
// if digit divided by 5 print "digit: buzz"
//
// if digit divided by 3 and 5 print "digit: fizz buzz"
//

#define FIZZD 3
#define FIZZT "fizz"

#define BUZZD 5
#define BUZZT "buzz"

void variant_one(int limit);

void variant_two(int limit);

int main() {
  variant_one(16);

  variant_two(16);
}

void variant_one(int limit) {
  putchar('\n');

  puts("Variant #1");

  for(int i = 1; i < limit; i++) {
    if(i % (FIZZD * BUZZD) == 0) {
      printf("%2d: %s %s\n", i, FIZZT, BUZZT);
    } else if(i % FIZZD == 0) {
      printf("%2d: %s\n", i, FIZZT);
    } else if(i % 5 == 0) {
      printf("%2d: %s\n", i, BUZZT);
    }
  }

  putchar('\n');
}

void variant_two(int limit) {
  puts("Variant #2");

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

  putchar('\n');
}
