#include "s21_math.h"

// обработка бесконечности
int s21_isinf(double x) {
  return (x == 1.0 / 0.0 ||
          x == -1.0 / 0.0);  // Проверяем, является ли число INFINITY
}
