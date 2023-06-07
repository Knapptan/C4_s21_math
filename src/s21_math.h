#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_MIN 0.0000001
#define S21_MAX 9999999999999999.0
#define S21_PI 3.1415926535897932
#define S21_PI_2 1.57079632679489661923
#define S21_LN10 2.30258509299404568402
#define S21_LN2 0.69314718056
#define S21_INFINITY 1.0 / 0.0
#define S21_MINUS_INFINITY -1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_NINF -1.0 / 0.0
#define S21_EPS 1e-16
#define EULER_CONST 2.718281828459045235
#define TAYLOR_ITERATIONS 300

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
int s21_isinf(double x);
int s21_isnan(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double superBaza, double power);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
double helper(double base, double exp);
long double fast_pow(double base, long long int exp);
