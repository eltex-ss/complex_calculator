objects = main.o complex.o

TARGET = complexCalculator

CFLAGS = -c

all : $(objects)
		$(CC) -o $(TARGET) $(objects)


debug : CFLAGS += -g
debug : executable

executable : $(objects)
		$(CC) -o $(TARGET) $(objects)

main.o : main.c complex.h
		$(CC) $(CFLAGS) main.c

complex.o : complex.c
		$(CC) $(CFLAGS) complex.c

.PHONY : clean
clean : 
		rm $(TARGET) $(objects)