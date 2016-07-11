objects = complex_add.o complex_sub.o \
					complex_mul.o complex_div.o

LIB_TARGETS = complex_add complex_sub \
							complex_mul complex_div

CFLAGS = -Wall -pedantic -ansi -fPIC

LDFLAGS = -shared

all : $(LIB_TARGETS)

complex_add : complex_add.o
		$(CC) -o libcomplex_add.so $(LDFLAGS) $<

complex_sub : complex_sub.o
		$(CC) -o libcomplex_sub.so $(LDFLAGS) $<

complex_mul : complex_mul.o
		$(CC) -o libcomplex_mul.so $(LDFLAGS) $<

complex_div : complex_div.o
		$(CC) -o libcomplex_div.so $(LDFLAGS) $<

$(objects) : complex.h
$(objects) : %.o : %.c
		$(CC) -c $(CFLAGS) $<

.PHONY : clean
clean : 
		-rm $(objects) *.so
