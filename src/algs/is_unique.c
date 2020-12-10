#include <stdio.h>
#include <stdbool.h>

//
// Complexity O(n^2)
//

bool is_unique(int array[], size_t size);

int main() {
  int array[] = { 0, 1, 2, 3, 0 };

  printf("%d\n", is_unique(array, sizeof(array) / sizeof(int)));
}

bool is_unique(int array[], size_t size) {
  for(size_t a = 0; a < size - 1; a++) {
    for(size_t b = a + 1; b < size; b++) {
      if(array[a] == array[b]) {
        return true;
      }
    }
  }

  return false;
}
