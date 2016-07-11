#include <stdio.h>
#include <dlfcn.h>

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

struct Complex handleOperation(char op, struct Complex c1, struct Complex c2)
{
  struct Complex result;
  struct Complex (*operation)(struct Complex, struct Complex);
  char library_prefix[] = "./complex_calc_lib/libcomplex_";
  char library_operation[3];
  char library_postfix[] = ".so";
  char library_path[50];
  void *ds;
  
  switch (op) {
    case 1:
      sprintf(library_operation, "add");
      break;
    case 2:
      sprintf(library_operation, "sub");
      break;
    case 3:
      sprintf(library_operation, "mul");
      break;
    case 4:
      sprintf(library_operation, "div");
      break;       
  }
  sprintf(library_path, "%s%s%s", library_prefix, library_operation,
          library_postfix);
  ds = dlopen(library_path, RTLD_NOW);
  operation = (struct Complex*) dlsym(ds, library_operation);
  result = operation(c1, c2);
  dlclose(ds);
  return result;
}

int main()
{
  struct Complex c1, c2, c3;
  char choise;
  char white_space;
  while (1) {
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
      c3 = handleOperation(choise, c1, c2);
      PrintComplexResult("Result:", c3);
      scanf("%c", &white_space);
    }
  }

	return 0;
}
