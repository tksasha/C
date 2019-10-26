#include <string.h>

int sum(int *a, int *b) {
  return(*a + *b);
}

void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

unsigned long int max_ulint(unsigned long int *a, unsigned long int *b) {
  if(*a > *b) {
    return(*a);
  } else {
    return(*b);
  }
}

unsigned long int min_ulint(unsigned long int *a, unsigned long int *b) {
  if(*a < *b) {
    return(*a);
  } else {
    return(*b);
  }
}

unsigned short max_char(char *a, char *b) {
  if(*a > *b) {
    return 1;
  } else {
    return 2;
  }
}

unsigned short min_char(char *a, char *b) {
  if(*a < *b) {
    return 1;
  } else {
    return 2;
  }
}

void char_downcase(char *c) {
  if(*c >= 65 && *c <= 90) {
    *c += 32;
  }
}

void string_downcase(char *string) {
  for(int i = 0; i < strlen(string); i++) {
    char_downcase(&string[i]);
  }
}

char* max_string(char *a, char *b) {
  unsigned long int a_len = strlen(a);
  unsigned long int b_len = strlen(b);

  unsigned long int m_len = min_ulint(&a_len, &b_len);

  for(int i = 0; i < m_len; i++) {
    switch(max_char(&a[i], &b[i])) {
      case 1:
        return a;

        break;
      case 2:
        return b;

        break;
    }
  }

  return a;
}

char* min_string(char *a, char *b) {
  unsigned long int a_len = strlen(a);
  unsigned long int b_len = strlen(b);

  unsigned long int m_len = min_ulint(&a_len, &b_len);

  for(int i = 0; i < m_len; i++) {
    switch(min_char(&a[i], &b[i])) {
      case 1:
        return a;

        break;
      case 2:
        return b;

        break;
    }
  }

  return a;
}
