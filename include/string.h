#include <stdio.h>

#define  ASC 0
#define DESC 1

#define SPACE   ' '
#define TAB     '\t'
#define TABSTOP   4

int string_size(char *string);

void string_sort(char *string, short int mode);

void string_append(char *string, char character, size_t size);

void string_reverse(char *string);

void string_copy(char *src, char *dst, size_t dstsize);

void string_nullify(char *string, size_t size);

void string_rstrip(char *string);

void string_entab(char *string, size_t size);

void string_detab(char *string, size_t size);
