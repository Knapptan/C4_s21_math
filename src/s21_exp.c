#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1, i = 1, add_value = 1;
  if (x == S21_MINUS_INFINITY) {
    res = 0;
  } else {
    while (s21_fabs(add_value) > S21_EPS) {
      add_value *= x / i;
      i++;
      res += add_value;
      if (res > DBL_MAX) {
        res = S21_INFINITY;
        break;
      }
    }
  }
  return res;
}
