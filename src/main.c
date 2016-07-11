#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

#include "complex_calc_lib/complex.h"

char operation_list[4][4];
int operations_count = 0;

void LoadOperations(void)
{
  char library_name[4];
  char white_space;

  printf("Please, write operations u want:\n");
  printf("q - quit\n");
  while (1) {
    printf("$ ");
    scanf("%s", library_name);
    scanf("%c", &white_space);
    if (library_name[0] == 'q')
      break;
    strncpy(operation_list[operations_count], library_name, 4);
    ++operations_count;
  }
}

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
  for (int i = 0; i < operations_count; ++i) {
    printf("%d) %s\n", i + 1, operation_list[i]);
  }
  printf("0) Exit\n");
}

void ReadComplex(struct Complex *c)
{
  scanf("%f %f", &c->re, &c->im);
}

struct Complex HandleOperation(char op, struct Complex c1, struct Complex c2)
{
  struct Complex result;
  struct Complex (*operation)(struct Complex, struct Complex);
  char library_prefix[] = "./complex_calc_lib/libcomplex_";
  char library_postfix[] = ".so";
  char library_path[50];
  void *ds;
  int op_num = (int)op;

  sprintf(library_path, "%s%s%s", library_prefix, operation_list[op_num],
          library_postfix);
  ds = dlopen(library_path, RTLD_NOW);
  /*  TODO: why here is the warning? */
  operation = (struct Complex (*)(struct Complex, struct Complex))
              dlsym(ds, operation_list[op_num]);
  result = operation(c1, c2);
  dlclose(ds);
  return result;
}

int main(void)
{
  struct Complex c1, c2, c3;
  char choise;
  char white_space;

  LoadOperations();
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
      c3 = HandleOperation(choise, c1, c2);
      PrintComplexResult("Result:", c3);
      scanf("%c", &white_space);
    }
  }

	return 0;
}
