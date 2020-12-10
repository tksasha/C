CC = \
	clang \
		-Wall \
		-Wextra  \
		-Wmissing-prototypes \
		-Wstrict-prototypes \
		-Wold-style-definition \
		-pedantic \
		# -Weverything

AR = ar -cq
RM = rm -f

INCLUDE = -Iinclude

CLIBS = array char integer string

LFLAGS = -Llib $(foreach lib,$(CLIBS),-l$(lib))

MAINC = src/main.c
MAIN  = bin/main

.PHONY: libs main src/**/*.c
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

src/**/*.c:
	@echo "Compiling: $@ to $(MAIN)"
	@$(CC) $@ -o $(MAIN)
