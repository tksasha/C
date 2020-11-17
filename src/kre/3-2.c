#include <stdio.h>

//
// Exercise 3-2 from the K&R Book
//

void escape(char src[], char dst[], size_t dstsize);

void unescape(char src[], char dst[], size_t dstsize);

void inspect(char str[], size_t size);

int main() {
  char src[] = "Hello\t\nWorld!";

  char dst[16];

  escape(src, dst, sizeof(dst));

  inspect(dst, sizeof(dst));

  unescape(dst, src, sizeof(src));

  inspect(src, sizeof(src));
}

void escape(char src[], char dst[], size_t dstsize) {
  for(int i = 0, j = 0; src[i] != '\0'; i++) {
    if(j > dstsize - 1) {
      break;
    }

    switch(src[i]) {
      case '\t':
        dst[j++] = '\\';

        dst[j++] = 't';

        break;
      case '\n':
        dst[j++] = '\\';

        dst[j++] = 'n';

        break;
      default:
        dst[j++] = src[i];
    }
  }

  dst[dstsize - 1] = '\0';
}

void unescape(char src[], char dst[], size_t dstsize) {
  for(int i = 0, j = 0; src[i] != '\0'; i++) {
    if(j > dstsize - 1) {
      break;
    }

    if(src[i] == '\\') {
      switch(src[i + 1]) {
        case 't':
          dst[j++] = '\t';

          i++;

          break;
        case 'n':
          dst[j++] = '\n';

          i++;

          break;
        default:
          dst[j++] = src[i + 1];
      }

      continue;
    } else {
      dst[j++] = src[i];
    }
  }

  dst[dstsize - 1] = '\0';
}

void inspect(char str[], size_t size) {
  putchar('"');

  for(int i = 0; i < size; i++) {
    switch(str[i]) {
      case '\t':
        printf("\\T");
        break;
      case '\n':
        printf("\\N");
        break;
      case '\0':
        printf("\\0");
        break;
      default:
        putchar(str[i]);
    }
  }

  printf("\"\n");
}
