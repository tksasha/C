CC = clang
CFLAGS = -O0 -Wall

INCLUDE = include

FARRAYS = -larrays
CARRAYS = src/arrays.c
OARRAYS = src/arrays.o
AARRAYS = lib/libarrays.a

FINTEGERS = -lintegers
CINTEGERS = src/integers.c
OINTEGERS = src/integers.o
AINTEGERS = lib/libintegers.a

LIBS = -Llib $(FARRAYS) $(FINTEGERS)

MAINC = src/main.c
MAIN 	= bin/main

AR = ar
ARFLAGS = -cvq

RM = rm
RMFLAGS = -f

all: libs main

libs:
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(CARRAYS) 		-o $(OARRAYS)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(CINTEGERS) 	-o $(OINTEGERS)

	$(AR) $(ARFLAGS) $(AARRAYS) 	$(OARRAYS)
	$(AR) $(ARFLAGS) $(AINTEGERS) $(OINTEGERS)

	$(RM) $(RMFLAGS) $(OARRAYS)
	$(RM) $(RMFLAGS) $(OINTEGERS)

main:
	$(CC) $(CFLAGS) -I$(INCLUDE) $(LIBS) $(MAINC) -o $(MAIN)

clean:
	$(RM) $(RMFLAGS) $(MAIN)
	$(RM) $(RMFLAGS) $(MAINC)

	$(RM) $(RMFLAGS) $(AARRAYS)
	$(RM) $(RMFLAGS) $(AINTEGERS)
