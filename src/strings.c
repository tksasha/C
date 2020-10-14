int ssize(char *string) {
  int size = 0;

  while(*string != '\0') {
    size++;

    string++;
  }

  return size;
}
