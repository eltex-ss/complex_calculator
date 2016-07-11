#include "complex.h"

/* Division */
struct Complex div(struct Complex dividend, struct Complex devider)
{
  struct Complex result;
  float denom = devider.re * devider.re + devider.im * devider.im;
  result.re = (dividend.re * devider.re + dividend.im * devider.im) / denom;
  result.im = (dividend.im * devider.re - dividend.re * devider.im) / denom;
  return result;
}
