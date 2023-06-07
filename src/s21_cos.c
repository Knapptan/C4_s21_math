#include "s21_math.h"

/* s21_cos вычисляет косинус cos(x)
 путем вычисления синуса sin(x + π/2)
 с использованием ряда Тейлора для синуса.
 */

long double s21_cos(double x) {
  long double result = 0;
  if (x == S21_NAN) {  // проверка на число
    result = S21_NAN;  // если не число - возвращаем -нан
  } else if (x == 0.) {
    result = 1.;  // если ноль, по дефолту косинус 1
  } else if (x == S21_INFINITY || x == S21_MINUS_INFINITY) {
    result = S21_NAN;  // возвращаем - нан по аналогии -нан
  } else {
    // Пока x находится вне диапазона [-2π, 2π]
    for (; x < -2 * S21_PI || x > 2 * S21_PI;) {
      // Если x больше 2π
      if (x > 2 * S21_PI) {
        // Вычитаем 2π из x
        x -= 2 * S21_PI;
      } else {
        // Иначе прибавляем 2π к x
        x += 2 * S21_PI;
      }
    }
    // cos(x) = sin(x + π/2)
    // sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
    result = s21_sin(x + S21_PI / 2.);
  }
  return result;
}
