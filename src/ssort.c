#include <stdio.h>

#include "strings.h"

int main() {
  char string[] = "dbeac";

  ssort(string, DESC);

  printf("%s\n", string);

  ssort(string, ASC);

  printf("%s\n", string);

  return 0;
}
