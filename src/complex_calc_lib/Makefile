objects = complex.o

CFLAGS = -Wall -pedantic -ansi -fPIC

LIB_NAME = libcomplex_calc.so
LIB_TARGET = calc_lib

LIB_OBJECTS = complex.o

LDFLAGS = -shared

all : $(LIB_OBJECTS)
		$(CC) -o $(LIB_NAME) $(LDFLAGS) $(LIB_OBJECTS)

debug : CFLAGS += -g
debug : all

complex.o : complex.c complex.h
		$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean : 
	-rm $(LIB_OBJECTS) $(LIB_NAME)
