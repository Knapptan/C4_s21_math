#include "s21_math.h"

// остаток от деления
long double s21_fmod(double x, double y) {
  int flag = 0;
  double res = 0;
  float res2 = 0;
  double trunc_quotient = 0;

  if (s21_isinf(x)) {
    flag = 1;
    res2 = S21_NAN;
  }

  if (s21_isnan(x)) {
    flag = 1;
    res2 = S21_NAN;
  }

  if (y < 0) {
    y = s21_fabs(y);
  }

  double quotient = x / y;

  if (x < 0.0) {
    trunc_quotient = s21_ceil(quotient);
  } else {
    trunc_quotient = s21_floor(quotient);
  }

  res = x - (trunc_quotient * y);

  if (y == S21_INFINITY || y == S21_MINUS_INFINITY) {
    res = x;
  }

  // Если результат равен 0 и x отрицательный, возвращаем -0
  if (res == 0.0 && x < 0.0) {
    res = -0.0;
  }

  return (flag == 0) ? res : res2;
}
