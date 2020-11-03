#include <stdio.h>

#define  ASC 0
#define DESC 1

int strings_size(char *string);

void strings_sort(char *string, short int mode);

void strings_append(char *string, char character, size_t size);

void strings_reverse(char *string);

void scopy(char *src, char *dst, size_t dstsize);

void strings_nullify(char *string, size_t size);

void strings_rstrip(char *string);
