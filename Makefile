CC			=	clang
CFLAGS	=	-Ofast -Wall

AR 			= ar
ARFLAGS =	-cvq

SOURCES		=	src
INCLUDES	=	include
LIBRARIES	=	lib
LFLAGS		=	-lsum

OUTPUT = bin/main

RM 			= rm
RMFLAGS	= -rf

all:
	$(CC) $(CFLAGS) -c $(SOURCES)/sum.c -o $(SOURCES)/sum.o

	$(AR) $(ARFLAGS) $(LIBRARIES)/libsum.a $(SOURCES)/sum.o

	$(CC) -I$(INCLUDES) $(CFLAGS) $(SOURCES)/main.c -L$(LIBRARIES) $(LFLAGS) -o $(OUTPUT)

	$(RM) $(RMFLAGS) $(SOURCES)/*.o

clear:
	$(RM) $(RMFLAGS) $(SOURCES)/*.o

	$(RM) $(OUTPUT)
