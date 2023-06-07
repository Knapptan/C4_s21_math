#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = x / 2;
  if (x < 0.0 || x == S21_NAN) {
    res = S21_NAN;
  } else if (x == 0.0) {
    res = 0.0;
  } else {
    long double new_prib = 0;

    for (int i = 0; i < TAYLOR_ITERATIONS; i++) {
      new_prib = (res + (x / res)) / 2;
      res = new_prib;
    }
  }

  return res;
}
