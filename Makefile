CC = clang
CFLAGS = -O0 -Wall

INCLUDE = include

MAIN = bin/main
TEST = bin/test

MAINC = src/main.c
TESTC = src/test.c

UTILSC = src/utils.c
UTILSO = lib/utils.o
UTILSA = lib/libutils.a
UTILSL = -Llib -lutils

UTESTC = src/utils/test.c
UTESTO = lib/utils/test.o
UTESTA = lib/utils/libtest.a
UTESTL = -Llib/utils -ltest

AR = ar
ARFLAGS = -cvq

RM = rm
RMFLAGS = -f

all:
	$(CC) $(CFLAGS) -I$(INCLUDE) $(MAINC) $(UTILSL) -o $(MAIN)

everything: libs all testlibs test

libs:
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(UTILSC) -o $(UTILSO)
	$(AR) $(ARFLAGS) $(UTILSA) $(UTILSO)
	$(RM) $(RMFLAGS) $(UTILSO)

test:
	$(CC) $(CFLAGS) -I$(INCLUDE) $(TESTC) $(UTILSL) $(UTESTL) -o $(TEST)
	$(TEST)

testlibs:
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(UTESTC) -o $(UTESTO)
	$(AR) $(ARFLAGS) $(UTESTA) $(UTESTO)
	$(RM) $(RMFLAGS) $(UTESTO)

clean:
	$(RM) $(RMFLAGS) $(MAIN)
	$(RM) $(RMFLAGS) $(TEST)
	$(RM) $(RMFLAGS) $(UTILSA)
	$(RM) $(RMFLAGS) $(UTESTA)
