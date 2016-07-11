objects = main.o

TARGET = complex_calculator

CFLAGS = -g -Wall -pedantic -ansi

LDFLAGS = -L./complex_calc_lib
LDLIBS = -lcomplex_calc

SUBDIR = complex_calc_lib

all : $(SUBDIR) $(objects)
		$(CC) -o $(TARGET) $(objects) $(LDFLAGS) $(LDLIBS)

release : CFLAGS -= -g
release : all


.PHONY : clean subdirs $(SUBDIR)

subdirs : $(SUBDIR)

$(SUBDIR) :
		$(MAKE) -C $@

main.o : main.c complex_calc_lib/complex.h
		$(CC) -c $(CFLAGS) $<

clean : 
		-rm $(TARGET) $(objects) ./$(SUBDIR)/*.o ./$(SUBDIR)/*.a ./$(SUBDIR)/*.so
