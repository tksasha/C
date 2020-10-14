## How to build
```
cd src
ln -s FILE.c main.c
cd ..
make
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

### integers.h

```
void iswap(int*, int*)
```

### TODO
- implement reverse string;
