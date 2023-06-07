#include "s21_math.h"

/*
   Функция s21_log вычисляет натуральный логарифм ln(x)
   путем использования ряда Тейлора.

   Параметры:
     - x: входное значение, для которого нужно вычислить логарифм.

   Возвращаемое значение:
     Натуральный логарифм ln(x).

   Примечания:
     - Если входное значение x не положительное, возвращается NaN.
     - Для повышения точности вычислений можно увеличить количество итераций в
   ряду Тейлора.
     - Входное значение x ограничивается до разумного диапазона перед
   применением ряда Тейлора.
*/

long double s21_log(double x) {
  long double res;
  if (x == -0.0) {
    res = S21_MINUS_INFINITY;
  } else if (x == 0.0 || x == S21_INFINITY) {
    res = S21_INFINITY;
  } else if (x < 0) {
    res = S21_NAN;
  } else {
    int power_adjust = 0;
    while (x >= 1.0) {
      x /= EULER_CONST;
      power_adjust++;
    }
    while (x < 0.25) {
      x *= EULER_CONST;
      power_adjust--;
    }
    x -= 1.0;
    double logarithm = 0.0, term = x, sign = 1.0, power = x;
    for (int k = 1; k <= TAYLOR_ITERATIONS; k++) {
      logarithm += term * sign / k;
      term *= power;
      sign = -sign;
    }
    res = logarithm + power_adjust;
  }
  return res;
}
