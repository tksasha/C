## How to build and run `src/main.c`:
```
make
bin/main
```

## How to build and run `src/ex/*.c`:
```
make src/ex/FILE.c
bin/main
```

## How to build and run exercises from K&R book:
```
make src/kre/EXERCISE.c
bin/main
```

To cleanup
```
make clean
```

## API

### arrays.h
```
int aimax(int *array, int size)
```

```
void aisort(int *array, int size, short int mode)
```

### chars.h
```
void cswap(char*, char*)
```

### integers.h

```
void iswap(int*, int*)
```

### strings.h
```
int ssize(char *string)

void ssort(char *string, short int mode)

void strings_append(char *string, char character, size_t size);

void strings_nullify(char *string, size_t size);

void strings_rstrip(char *string);
```

### TODO
-
