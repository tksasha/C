#include <stdio.h>

#include "utils.h"
#include "utils/test.h"

void test_max_char();

int main() {
  test_max_char();

  return 0;
}

void test_max_char() {
  char test[] = "test_max_char";

  char a = 'a';
  char b = 'b';

  char res = max_char(&a, &b);

  if(res == b) {
    success(test);
  } else {
    failure(test);
  }
}
