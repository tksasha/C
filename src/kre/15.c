#include <stdio.h>

float fahrenheit(int *celsius);

int main() {
  printf("Celsius Fahrenheit\n");

  for(int i = 300; i >= 0; i -= 20) {
    printf("%7d %10.2f\n", i, fahrenheit(&i));
  }

  return 0;
}

float fahrenheit(int *celsius) {
  return *celsius * 9.0/5.0 + 32.0;
}
