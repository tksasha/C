CC = clang -O0 -Wall -std=gnu11
AR = ar -cq
RM = rm -f

INCLUDE = -Iinclude

CLIBS = arrays chars integers strings

LFLAGS = -Llib $(foreach lib,$(CLIBS),-l$(lib))

MAINC = src/main.c
MAIN  = bin/main

.PHONY: libs main
all: main

libs:
	@for lib in $(CLIBS); do \
		echo Compiling: lib/lib$$lib.a; \
		$(CC) $(INCLUDE) -c src/lib/$$lib.c -o tmp/$$lib.o; \
		$(AR) lib/lib$$lib.a tmp/$$lib.o; \
		$(RM) tmp/$$lib.o; \
	done;

main:
	@echo Compiling: $(MAINC) to $(MAIN)
	@$(CC) $(MAINC) -o $(MAIN)

clean:
	$(RM) $(MAIN)

	@for file in $(wildcard lib/*.a); do \
		echo $(RM) $$file; \
		$(RM) $$file; \
	done;

src/ex/%.c: libs
	@echo "Compiling: $@ to $(MAIN)"
	@$(CC) $(INCLUDE) $(LFLAGS) $@ -o $(MAIN)

src/kre/%.c: clean
	@echo "Compiling: $@ to $(MAIN)"
	@$(CC) $(INCLUDE) $@ -o $(MAIN)

libchars.a:
	@echo Compiling: src/lib/chars.c to lib/libchars.a
	@$(CC) $(INCLUDE) -c src/lib/chars.c -o tmp/chars.o
	@$(AR) lib/libchars.a tmp/chars.o
	@$(RM) tmp/chars.o

libstrings.a:
	@echo Compiling: src/lib/strings.c to lib/libstrings.a
	@$(CC) $(INCLUDE) -c src/lib/strings.c -o tmp/strings.o
	@$(AR) lib/libstrings.a tmp/strings.o
	@$(RM) tmp/strings.o

src/kre/1-18.c: libchars.a libstrings.a
	@echo "Compiling: $@ to $(MAIN)"
	@$(CC) $(INCLUDE) -Llib -lchars -lstrings $@ -o $(MAIN)

src/kre/1-19.c: libchars.a libstrings.a
	@echo "Compiling: $@ to $(MAIN)"
	@$(CC) $(INCLUDE) -Llib -lchars -lstrings $@ -o $(MAIN)
