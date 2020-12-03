#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// 0: 000
// 1: 001
// 2: 010
// 3: 011

int bits_on_count(int mask);

char * bits(int digit);

void inspect(int * array, size_t size);

void swap(char * a, char * b);

void reverse(char * string, size_t size);

int main() {
  for(int i = 0; i <= 8; i++) {
    char * mask = bits(i);

    printf("%d(10), %s(2) = %d\n", i, mask, bits_on_count(i));

    free(mask);
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

char * bits(int digit) {
  const int DSTSIZE = 9;

  char * dst = malloc(DSTSIZE);

  for(int i = 0; i < DSTSIZE - 1; i++) {
    dst[i] = '0';
  }

  dst[DSTSIZE] = '\0';

  for(int i = 0; i < digit; i++) {
    for(int j = 0; j < DSTSIZE; j++) {
      if(dst[j] == '0') {
        dst[j] = '1';

        break;
      } else {
        dst[j] = '0';
      }
    }
  }

  reverse(dst, DSTSIZE);

  return dst;
}

void inspect(int * array, size_t size) {
  for(int i = 0; i < size; i++) {
    printf("%d", array[i]);
  }

  putchar('\n');
}

void swap(char * a, char * b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void reverse(char string[], size_t size) {
  size--;

  for(int i = 0; i < size / 2; i++) {
    swap(&string[i], &string[size - i - 1]);
  }
}
