#include "all.h"
#include "utils.h"
#include <stdio.h>

int main() {
  struct vector *v = vcreate(0);
  vpush(v, gtype_l(1));
  vpush(v, gtype_l(3));
  vpush(v, gtype_l(5));
  gtype val;
  vtop(v, &val);
  CHECK_MSG(val.l == 5, "dinh = 5");
  vpop(v);
  vtop(v, &val);
  CHECK_MSG(val.l == 3, "dinh = 3");
  vpush(v, gtype_l(7));
  vtop(v, &val);
  CHECK_MSG(val.l == 7, "dinh = 7");
  vpop(vpop(v));
  vtop(v, &val);
  CHECK_MSG(val.l == 1, "dinh = 1");
  TEST_OK();
}
