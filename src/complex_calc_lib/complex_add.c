#include "complex.h"

/* Addition */
struct Complex add(struct Complex first, struct Complex second)
{
  struct Complex result;
  result.re = first.re + second.re;
  result.im = first.im + second.im;
  return result;
}
