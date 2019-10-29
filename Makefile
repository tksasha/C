CC = clang
CFLAGS = -O0 -Wall

INCLUDE = include

MAIN = bin/main
TEST = bin/test

MAINC = src/main.c
TESTC = src/test.c

LFLAGS = -Llib -lutils

UTILSC = src/utils.c
UTILSO = lib/utils.o
UTILSA = lib/libutils.a

AR = ar
ARFLAGS = -cvq

RM = rm
RMFLAGS = -f

all: libs
	$(CC) $(CFLAGS) -I$(INCLUDE) $(MAINC) $(LFLAGS) -o $(MAIN)

test:
	$(CC) $(CFLAGS) -I$(INCLUDE) $(TESTC) $(LFLAGS) -o $(TEST)
	$(TEST)

libs:
	$(CC) $(CFLAGS) -c $(UTILSC) -o $(UTILSO)
	$(AR) $(ARFLAGS) $(UTILSA) $(UTILSO)
	$(RM) $(RMFLAGS) $(UTILSO)

clean:
	$(RM) $(RMFLAGS) $(MAINC)
	$(RM) $(RMFLAGS) $(TESTC)
	$(RM) $(RMFLAGS) $(UTILSA)
