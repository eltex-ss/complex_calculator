#include "complex.h"

/* Multiplication */
struct Complex mul(struct Complex first, struct Complex second)
{
  struct Complex result;
  result.re = first.re * second.re - first.im * second.im;
  result.im = first.im * second.re + first.re * second.im;
  return result;
}
