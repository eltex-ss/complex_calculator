#include "complex.h"

// Addition
struct Complex add(struct Complex first, struct Complex second)
{
  struct Complex result;
  result.re = first.re + second.re;
  result.im = first.im + second.im;
  return result;
}

// Subtraction
struct Complex sub(struct Complex minuend, struct Complex subtrahend)
{
  struct Complex result;
  result.re = minuend.re - subtrahend.re;
  result.im = minuend.im - subtrahend.im;
  return result;
}

// Multiplication
struct Complex mul(struct Complex first, struct Complex second)
{
  struct Complex result;
  result.re = first.re * second.re - first.im * second.im;
  result.im = first.im * second.re + first.re * second.im;
  return result;
}

// Division
struct Complex div(struct Complex dividend, struct Complex devider)
{
  struct Complex result;
  float denom = devider.re * devider.re + devider.im * devider.im;
  result.re = (dividend.re * devider.re + dividend.im * devider.im) / denom;
  result.im = (dividend.im * devider.re - dividend.re * devider.im) / denom;
  return result;
}
