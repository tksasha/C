CC			=	clang
CFLAGS	=	-Ofast -Wall

AR 			= ar
ARFLAGS =	-cvq

SOURCES		=	src
INCLUDES	=	include
LIBRARIES	=	lib
LFLAGS		=	-lutils

OUTPUT = bin/main

RM 			= rm
RMFLAGS	= -rf

all:
	$(CC) $(CFLAGS) -c $(SOURCES)/utils.c -o $(SOURCES)/utils.o
	$(AR) $(ARFLAGS) $(LIBRARIES)/libutils.a $(SOURCES)/utils.o

	$(CC) -I$(INCLUDES) $(CFLAGS) $(SOURCES)/main.c -L$(LIBRARIES) $(LFLAGS) -o $(OUTPUT)

	$(RM) $(RMFLAGS) $(SOURCES)/*.o

clear:
	$(RM) $(RMFLAGS) $(SOURCES)/*.o

	$(RM) $(OUTPUT)
