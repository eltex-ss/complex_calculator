#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#include "complex_calc_lib/complex.h"

#define currentDirNameSize 150
#define maxPluginCount 4

char plugin_name[maxPluginCount][20];
char operation_name[maxPluginCount][4];
int operations_count = 0;

void LoadOperationPaths(void)
{
  DIR * dir;
  struct dirent * file;
  char current_dir_name[currentDirNameSize];
  char libcomplex[] = "libcomplex_";
  int libcomplex_string_size;
  libcomplex_string_size = strlen(libcomplex);

  if (getcwd(current_dir_name, currentDirNameSize) == NULL) {
    printf("Can't get current dir\n");
    return;
  }

  strcpy(current_dir_name + strlen(current_dir_name), "/plugins");
  dir = opendir(current_dir_name);
  if (!dir) {
    printf("Can't open plugins dir\n");
    return;
  }

  while ((file = readdir(dir)) != NULL) {
    if (file->d_name[0] == '.')
      continue;

    if (strstr(file->d_name, libcomplex) != NULL ) {
      strncpy(operation_name[operations_count],
             file->d_name + libcomplex_string_size, 3);
      strcpy(plugin_name[operations_count], file->d_name);
      ++operations_count;
    }
  }
  closedir(dir);
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
    printf("%d) %s\n", i + 1, operation_name[i]);
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
  char library_prefix[] = "./plugins/";
  char library_path[50];
  void *ds = NULL;
  int op_num = (int)op;
  operation = NULL;

  sprintf(library_path, "%s%s", library_prefix, plugin_name[op_num]);
  ds = dlopen(library_path, RTLD_NOW);
  operation = (struct Complex (*)(struct Complex, struct Complex))
              dlsym(ds, operation_name[op_num]);
  result = operation(c1, c2);
  dlclose(ds);
  return result;
}

int main(void)
{
  struct Complex c1, c2, c3;
  char choise;
  char white_space;

  LoadOperationPaths();
  while (1) {
    PrintMenu();
    choise = '\n';
    while (choise == '\n') {
      printf("$ ");
      scanf("%c", &choise);
    }
    scanf("%c", &white_space);
    if (choise == '0')
      break;
    
    if ('1' > choise || choise > '4') {
      printf("Incorrect input\n");
    } else {
      choise -= ('0' + 1);
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
