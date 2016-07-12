objects = main.o

TARGET = complex_calculator

CFLAGS = -g -Wall -pedantic -ansi -std=c99

LDLIBS = -ldl

SUBDIR = complex_calc_lib

all : $(SUBDIR) COPY $(objects)
		$(CC) -o $(TARGET) $(objects) $(LDLIBS)

main.o : complex_calc_lib/complex.h
main.o : main.c
		$(CC) -c $(CFLAGS) $<

release : CFLAGS -= -g
release : all

.PHONY : clean subdirs $(SUBDIR) COPY

subdirs : $(SUBDIR)

$(SUBDIR) :
		$(MAKE) -C $@

COPY :
		cp $(SUBDIR)/*.so ./plugins

clean : 
		-rm -rf $(TARGET) $(objects) ./complex_calc_lib/*.o \
			./complex_calc_lib/*.so ./plugins/*.so
