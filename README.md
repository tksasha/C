## How to build and run
```
cd src
ln -s FILE.c main.c
cd ..
make
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
```

```
void ssort(char *string, short int mode)
```

### TODO
-
