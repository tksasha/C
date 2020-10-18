void cswap(char *a, char *b) {
  *a = *a + *b;

  *b = *a - *b;

  *a = *a - *b;
}
