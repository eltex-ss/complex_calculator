#include "complex.h"

/* Subtraction */
struct Complex sub(struct Complex minuend, struct Complex subtrahend)
{
  struct Complex result;
  result.re = minuend.re - subtrahend.re;
  result.im = minuend.im - subtrahend.im;
  return result;
}
