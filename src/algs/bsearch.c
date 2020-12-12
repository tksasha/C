#include <stdio.h>

//
// Complexity O(1)
//
void Swap(int * a, int * b);

//
// Complexity O(n^2)
//
void Sort(int array[], int size);

//
// Complexity O(n)
//
void Inspect(int array[], int size);

//
// Complexity O(log2 n)
//
int Search(int array[], int size, int item);

int main() {
  int array[] = { 'd', 'b', 'e', 'a', 'c' };

  int size = (int)(sizeof(array) / sizeof(int));

  Sort(array, size);

  Inspect(array, size);

  int idx = Search(array, size, 'c');

  printf("idx: %d\n", idx);
}

void Swap(int * a, int * b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void Sort(int array[], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(array[i] < array[j]) {
        Swap(&array[i], &array[j]);
      }
    }
  }
}

void Inspect(int array[], int size) {
  putchar('[');

  for(int i = 0; i < size; i++) {
    printf("%c", array[i]);

    if(i < size - 1) {
      printf(", ");
    }
  }

  puts("]");
}

int Search(int array[], int size, int item) {
  int low  = 0;
  int high = size - 1;

  while(low <= high) {
    int mid = low + (high - low) / 2;

    if(array[mid] == item) {
      return mid;
    } else if(array[mid] < item) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}
