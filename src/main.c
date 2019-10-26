#include <stdio.h>

#include "utils.h"

int main() {
  /* char a[] = "apple"; */
  /* char b[] = "book"; */
  /* char c[] = "concurrency"; */

  char d[] = "apple12";
  char e[] = "apple2";

  /* printf("%11s max('%s', '%s')\n", max_string(a, b), a, b); */
  /* printf("%11s max('%s', '%s')\n", max_string(b, c), b, c); */
  /* printf("%11s max('%s', '%s')\n", max_string(c, a), c, a); */

  printf("%11s max('%s', '%s')\n", max_string(d, e), d, e);

  printf("\n");

  /* printf("%5s min('%s', '%s')\n", min_string(a, b), a, b); */
  /* printf("%5s min('%s', '%s')\n", min_string(b, c), b, c); */
  /* printf("%5s min('%s', '%s')\n", min_string(c, a), c, a); */

  printf("%11s min('%s', '%s')\n", min_string(d, e), d, e);

  return 0;
}
