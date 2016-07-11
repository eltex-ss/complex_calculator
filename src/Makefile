objects = main.o

TARGET = complex_calculator

CFLAGS = -g -Wall -pedantic -ansi -std=c99

LDFLAGS = -L./complex_calc_lib
LDLIBS = -ldl

SUBDIR = complex_calc_lib

all : $(SUBDIR) $(objects)
		$(CC) -o $(TARGET) $(objects) $(LDFLAGS) $(LDLIBS)

main.o : main.c complex_calc_lib/complex.h
		$(CC) -c $(CFLAGS) $<

release : CFLAGS -= -g
release : all

.PHONY : clean subdirs $(SUBDIR)

subdirs : $(SUBDIR)

$(SUBDIR) :
		$(MAKE) -C $@

clean : 
		-rm -rf $(TARGET) $(objects) ./complex_calc_lib/*.o \
			./complex_calc_lib/*.so
