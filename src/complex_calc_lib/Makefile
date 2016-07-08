objects = complex.o

CFLAGS = -Wall -pedantic -ansi

LIB_NAME = libcomplex_calc.a
LIB_TARGET = calc_lib

LIB_OBJECTS = complex.o

all : $(LIB_OBJECTS)
		ar rc $(LIB_NAME) $(LIB_OBJECTS)

debug : CFLAGS += -g
debug : all

complex.o : complex.c complex.h
		$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean : 
		-rm $(LIB_OBJECTS) $(LIB_NAME) 
