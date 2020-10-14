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

FSTRINGS = -lstrings
CSTRINGS = src/strings.c
OSTRINGS = src/strings.o
ASTRINGS = lib/libstrings.a

LIBS = -Llib $(FARRAYS) $(FINTEGERS) $(FSTRINGS)

MAINC = src/main.c
MAIN 	= bin/main

AR = ar
ARFLAGS = -cvq

RM = rm
RMFLAGS = -f

all: libs main

libs:
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(CARRAYS)   -o $(OARRAYS)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(CINTEGERS) -o $(OINTEGERS)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(CSTRINGS)  -o $(OSTRINGS)

	$(AR) $(ARFLAGS) $(AARRAYS)   $(OARRAYS)
	$(AR) $(ARFLAGS) $(AINTEGERS) $(OINTEGERS)
	$(AR) $(ARFLAGS) $(ASTRINGS)  $(OSTRINGS)

	$(RM) $(RMFLAGS) $(OARRAYS)
	$(RM) $(RMFLAGS) $(OINTEGERS)
	$(RM) $(RMFLAGS) $(OSTRINGS)

main:
	$(CC) $(CFLAGS) -I$(INCLUDE) $(LIBS) $(MAINC) -o $(MAIN)

clean:
	$(RM) $(RMFLAGS) $(MAIN)
	$(RM) $(RMFLAGS) $(MAINC)

	@for file in $(wildcard lib/*.a); do \
		echo $(RM) $(RMFLAGS) $$file; \
		$(RM) $(RMFLAGS) $$file; \
	done;
