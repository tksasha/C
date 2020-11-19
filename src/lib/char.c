#include <stdbool.h>

void char_swap(char *a, char *b) {
  *a = *a ^ *b;

  *b = *a ^ *b;

  *a = *a ^ *b;
}

bool char_is_letter(char chr) {
  if((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z')) {
    return true;
  } else {
    return false;
  }
}

bool char_is_downcase(char chr) {
  if(chr >= 'a' && chr <= 'z') {
    return true;
  } else {
    return false;
  }
}

bool char_is_uppercase(char chr) {
  if(chr >= 'A' && chr <= 'Z') {
    return true;
  } else {
    return false;
  }
}

char char_downcase(char chr) {
  char res = chr;

  if(char_is_letter(chr) && char_is_uppercase(chr)) {
    res = chr + 32;
  }

  return res;
}
