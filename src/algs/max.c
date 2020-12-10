#include <stdio.h>

//
// Complexity O(n)
//

int main() {
  int array[] = { 1, 2, 3, 4, 5 };

  int max = array[0];

  for(int i = 0; i < (int)(sizeof(array) / sizeof(int)); i++) {
    if(array[i] > max) {
      max = array[i];
    }
  }

  printf("max: %d\n", max);
}
