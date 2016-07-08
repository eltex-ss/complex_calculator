#include <stdio.h>

#include "complex_calc_lib/complex.h"

void PrintComplex(struct Complex c)
{
  if (c.re == 0 && c.im != 0) {
    printf("%fi", c.im);
  }
  else if (c.re != 0 && c.im == 0) {
    printf("%f", c.re);
  }
  else if (c.re == 0 && c.im == 0) {
    printf("0");
  } else {
    printf("%f + %fi", c.re, c.im);
  }
}

void PrintComplexResult(const char * message, struct Complex c)
{
  printf("%s", message);
  PrintComplex(c);
  printf("\n");
}

void PrintMenu(void)
{
  printf("Menu:\n");
  printf("1) Add\n");
  printf("2) Sub\n");
  printf("3) Mul\n");
  printf("4) Div\n");
  printf("0) Exit\n");
}

void ReadComplex(struct Complex *c)
{
  scanf("%f %f", &c->re, &c->im);
}

int main()
{
  while (1) {
    struct Complex c1, c2, c3;
    char choise;
    char white_space;
    PrintMenu();
    choise = '\n';
    while (choise == '\n') {
      printf("$ ");
      scanf("%c", &choise);
    }
    scanf("%c", &white_space);

    choise -= '0';

    if (choise == 0)
      break;
    
    if (1 > choise || choise > 4) {
      printf("Incorrect input\n");
    } else {
      printf("Please, write real and imagine parts of the first number\n");
      printf("$ ");
      ReadComplex(&c1);

      printf("Please, write real and imagine parts of the second number\n");
      printf("$ ");
      ReadComplex(&c2);
      switch (choise) {
       case 1:
         c3 = add(c1, c2);
         break;
       case 2:
         c3 = sub(c1, c2);
         break;
       case 3:
         c3 = mul(c1, c2);
         break;
       case 4:
         c3 = div(c1, c2);
         break;       
      }
      PrintComplexResult("Result:", c3);
      scanf("%c", &white_space);
    }
  }

	return 0;
}
