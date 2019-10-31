#include <stdio.h>

#include "utils/test.h"
#include "utils/colors.h"

void success(char *test) {
  printf("%s: %s%s%s\n", test, SUCCESS, "SUCCESS", RESET);
}

void failure(char *test) {
  printf("%s: %s%s%s\n", test, FAILURE, "FAILURE", RESET);
}
