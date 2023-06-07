#include "s21_math.h"

// округление до наибольшего целого, которое меньше или равно аргументу
long double s21_floor(double x) {
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
    int round_x = (int)x;
    if (x) {
      if (x < 0 && x != round_x) {
        res = round_x - 1.0;
      } else {
        res = round_x;
      }
    }
  }
  return (flag == 0) ? res : res2;
}
