#include <stdio.h>

#include "utils.h"

#define SUCCESS COLOR_BOLD_GREEN
#define FAILURE COLOR_BOLD_RED
#define RESET   COLOR_RESET

void success(char*);
void failure(char*);

void test_max_char();

int main() {
  test_max_char();

  return 0;
}

void success(char *test) {
  printf("%s: %s%s%s\n", test, SUCCESS, "SUCCESS", RESET);
}

void failure(char *test) {
  printf("%s: %s%s%s\n", test, FAILURE, "FAILURE", RESET);
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
