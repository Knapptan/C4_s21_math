#include "s21_math.h"

// округление в большую сторону
long double s21_ceil(double x) {
  int flag = 0;
  int res = 0;
  float res2 = 0;

  if (s21_isinf(x)) {
    flag = 1;
    res2 = x;
  }

  if (s21_isnan(x)) {
    flag = 1;
    res2 = S21_NAN;
  }

  if (flag == 0) {
    int convert_x = (int)x;
    if (x) {
      if (x > convert_x) {
        res = x + 1;
      } else {
        res = x;
      }
    }
  }

  return (flag == 0) ? res : res2;
}
