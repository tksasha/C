#include <stdio.h>

#define  ASC 0
#define DESC 1

int ssize(char *string);

void ssort(char *string, short int mode);

void strings_append(char *string, char character, size_t size);

void sreverse(char *string);

void scopy(char *src, char *dst, size_t dstsize);

void strings_nullify(char *string, size_t size);

void strings_rstrip(char *string);
