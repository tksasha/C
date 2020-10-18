#include <stdio.h>

#define LOWER   0
#define UPPER 300
#define STEP   20

float fahrenheit(int *celsius);

int main() {
  printf("Celsius Fahrenheit\n");

  for(int i = LOWER; i <= UPPER; i += STEP) {
    printf("%7d %10.2f\n", i, fahrenheit(&i));
  }

  return 0;
}

float fahrenheit(int *celsius) {
  return *celsius * 9.0/5.0 + 32.0;
}
