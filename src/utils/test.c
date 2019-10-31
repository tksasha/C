#include <stdio.h>

#include "utils/test.h"

#define SUCCESS COLOR_BOLD_GREEN
#define FAILURE COLOR_BOLD_RED
#define RESET   COLOR_RESET

void success(char *test) {
  printf("%s: %s%s%s\n", test, SUCCESS, "SUCCESS", RESET);
}

void failure(char *test) {
  printf("%s: %s%s%s\n", test, FAILURE, "FAILURE", RESET);
}
