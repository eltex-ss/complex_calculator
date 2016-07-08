#include <stdio.h>

#include "complex.h"

void printComplex(struct Complex c)
{
  printf("%f + %fi", c.re, c.im);
}

void printComplexResult(const char * message, struct Complex c)
{
  printf("%s", message);
  printComplex(c);
  printf("\n");
}

int main()
{
  struct Complex c1, c2, c3;
  c1.re = 2;
  c1.im = 3;

  c2.re = 4;
  c2.im = 0.5;

  c3 = add( c1, c2 );
  printComplexResult("Addition: ", c3);

  c3 = sub( c1, c2 );
  printComplexResult("Substraction: ", c3);

  c3 = mul( c1, c2 );
  printComplexResult("Multiplication: ", c3);

  c3 = div(c1, c2);
  printComplexResult("Division: ", c3);
  

	return 0;
}
