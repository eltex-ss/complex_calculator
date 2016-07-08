objects = main.o complex.o

TARGET = complexCalculator

CFLAGS = -g -Wall -pedantic -ansi

all : $(objects)
		$(CC) -o $(TARGET) $(objects)

release : CFLAGS -= -g
release : executable

executable : $(objects)
		$(CC) -o $(TARGET) $(objects)

main.o : complex.h
main.o : main.c
		$(CC) -c $(CFLAGS) $<

complex.o : complex.c
		$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean : 
		rm $(TARGET) $(objects)
