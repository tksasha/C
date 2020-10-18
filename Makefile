CC = clang
CFLAGS = -O0 -Wall

CLIBS = \
	arrays \
	chars \
	integers \
	strings \

LFLAGS = -Llib $(foreach lib,$(CLIBS),-l$(lib))

MAINC = src/main.c
MAIN 	= bin/main

AR = ar
ARFLAGS = -cq

RM = rm
RMFLAGS = -f

.PHONY: libs main
all: libs main

libs:
	@for lib in $(CLIBS); do \
		echo Compiling: lib/lib$$lib.a; \
		$(CC) $(CFLAGS) -Iinclude -c src/lib/$$lib.c -o tmp/$$lib.o; \
		$(AR) $(ARFLAGS) lib/lib$$lib.a tmp/$$lib.o; \
		$(RM) $(RMFLAGS) tmp/$$lib.o; \
	done;

main:
	@echo Compiling: bin/main
	@$(CC) $(CFLAGS) -Iinclude $(LFLAGS) $(MAINC) -o $(MAIN)

clean:
	$(RM) $(RMFLAGS) $(MAIN)

	@for file in $(wildcard lib/*.a); do \
		echo $(RM) $(RMFLAGS) $$file; \
		$(RM) $(RMFLAGS) $$file; \
	done;

kre/%.c:
	@echo Compiling: $@ to bin/main
	@$(CC) $(CFLAGS) -Iinclude $(LFLAGS) src/$@ -o $(MAIN)
