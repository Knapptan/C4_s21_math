#include "s21_math.h"

#define OK 1000.0;
int isInt(double d) { return d == (int64_t)d; }

double helper(double base, double exp) {
  double res = OK;
  if (base == 0.0) {
    if (s21_isnan(exp)) {
      res = S21_NAN;
    } else if (exp == -S21_NAN) {
      res = -S21_NAN;
    } else if (s21_isinf(exp)) {
      res = S21_INFINITY;
    } else if (exp == 0.0) {
      res = 1.0;
    } else if (exp < 0) {
      res = S21_INFINITY;
    }
  } else if (base == 1.0) {
    res = 1.0;
  } else if (base == -1.0) {
    if (s21_isinf(exp) || s21_isinf(exp)) {
      res = 1.0;
    }
  } else if (!isInt(base) && !s21_isinf(base) && !s21_isinf(base)) {
    if (s21_isinf(exp)) {
      res = 0.0;
    } else if (s21_isinf(exp)) {
      res = S21_INFINITY;
    }
  } else if (isInt(base)) {
    if (s21_isinf(exp) || s21_isinf(exp)) {
      res = S21_INFINITY;
    }
  }
  return res;
}

long double fast_pow(double base, long long int exp) {
  long double ans = 1.0;
  long long copy = s21_fabs(exp);
  while (copy) {
    ans *= base;
    copy--;
  }
  return (exp < 0) ? 1.0 / ans : ans;
}

long double s21_pow(double base, double exp) {
  long double ans = 1.0;
  if (helper(base, exp) == 1000.0) {
    if (isInt(exp)) {
      ans = fast_pow(base, exp);
    } else {  // exp in not int
      if (base < 0) {
        ans = S21_NAN;
      } else {
        ans = s21_exp(exp * s21_log(base));
      }
    }
  } else {
    ans = helper(base, exp);
  }
  return ans;
}
