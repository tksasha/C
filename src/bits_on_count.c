#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int bits_on_count(int mask);

char * digit_to_bits(int digit);

void char_swap(char * a, char * b);

void string_reverse(char * string, size_t size);

int main() {
  for(int i = 0; i <= 8; i++) {
    char * bits = digit_to_bits(i);

    printf("%d(10), %s(2) = %d\n", i, bits, bits_on_count(i));

    free(bits);
  }
}

int bits_on_count(int mask) {
  int counter = 0;

  for(int i = 0; i <= log2(mask); i++) {
    if((mask & (int)pow(2, i)) > 0) {
      counter++;
    }
  }

  return counter;
}

char * digit_to_bits(int digit) {
  const int SIZE = 9;

  char * bits = malloc(SIZE);

  for(int i = 0; i < SIZE - 1; i++) {
    bits[i] = '0';
  }

  bits[SIZE] = '\0';

  for(int i = 0; i < digit; i++) {
    for(int j = 0; j < SIZE; j++) {
      if(bits[j] == '0') {
        bits[j] = '1';

        break;
      } else {
        bits[j] = '0';
      }
    }
  }

  string_reverse(bits, SIZE);

  return bits;
}

void char_swap(char * a, char * b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void string_reverse(char string[], size_t size) {
  size--;

  for(int i = 0; i < size / 2; i++) {
    char_swap(&string[i], &string[size - i - 1]);
  }
}
