objects = main.o

TARGET = complexCalculator

CFLAGS = -g -Wall -pedantic -ansi

LDFLAGS = -L.
LDLIBS = -lcomplex_calc

LIB_NAME = libcomplex_calc.a
LIB_TARGET = calc_lib

LIB_OBJECTS = complex.o

all : $(objects) $(LIB_TARGET)
		$(CC) -o $(TARGET) $(objects) $(LDFLAGS) $(LDLIBS)

release : CFLAGS -= -g
release : all

main.o : complex.h
main.o : main.c
		$(CC) -c $(CFLAGS) $<

$(LIB_TARGET) : complex.o
		ar rc $(LIB_NAME) $?

complex.o : complex.c
		$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean : 
		rm $(TARGET) $(objects) $(LIB_OBJECTS) $(LIB_NAME) 
