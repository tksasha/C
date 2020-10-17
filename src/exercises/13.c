#include <stdio.h>

float celsius(int fahrenheit);

//
// converts Fahrenheit degrees to Celsius degrees
//
int main() {
  printf("Fahrenheit Celsius\n");

  for(int i = 0; i <= 300; i += 20) {
    printf("%10d %7.1f\n", i, celsius(i));
  }

  return 0;
}

float celsius(int fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}
