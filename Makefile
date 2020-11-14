CC = clang -O0 -Wall -std=gnu11
AR = ar -cq
RM = rm -f

INCLUDE = -Iinclude

CLIBS = array char integer string

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

src/%.c: libs
	@echo "Compiling: $@ to $(MAIN)"
	@$(CC) $(INCLUDE) $(LFLAGS) $@ -o $(MAIN)
