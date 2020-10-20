#include <stdio.h>

#define LOWER   0
#define UPPER 300
#define STEP   20

float celsius(int fahrenheit);

//
// Exercise 1-3 from the K&R Book
//
// converts Fahrenheit degrees to Celsius degrees
//
int main() {
  printf("Fahrenheit Celsius\n");

  for(int i = LOWER; i <= UPPER; i += STEP) {
    printf("%10d %7.1f\n", i, celsius(i));
  }

  return 0;
}

float celsius(int fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}
