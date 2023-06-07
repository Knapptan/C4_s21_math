#include "s21_math.h"

// обработка NAN
int s21_isnan(double x) {
  return (x != x);  // NAN не равно ни одному другому числу, даже самому себе
}
