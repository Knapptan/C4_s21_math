#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0.0;

  if (x == S21_NAN) {  // проверка на число
    result = S21_NAN;  // если не число - возвращаем -нан
  } else if (x == 0.) {
    result = 0.;  // если ноль, по дефолту синус 1
  } else if (x == S21_INFINITY || x == S21_MINUS_INFINITY) {
    result = S21_NAN;  // возвращаем - нан по аналогии -нан
  } else {
    // Нормализуем угол x в диапазоне [-π, π]
    while (x > S21_PI) {
      x -= 2 * S21_PI;
    }
    while (x < -S21_PI) {
      x += 2 * S21_PI;
    }

    long double term = x;  // Первый член ряда   Тейлора - само x
    // long double factorial = 1.0;  // Факториал

    for (int n = 1; n <= 16; ++n) {
      result += term;  // Добавляем текущий член ряда к результату
      term *= (-1) * x * x /
              ((2 * n) * (2 * n + 1));  // Вычисляем следующий член ряда
    }
  }

  return result;
}
