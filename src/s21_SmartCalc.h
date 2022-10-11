#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define BLUE_P "\033[1;45m"

typedef enum {
  number = 1,
  x = 2,
  plus = 3,        // +
  minus = 4,       // -
  mull = 5,        // *
  del = 6,         // /
  scale = 7,       // ^
  mod = 8,         // m
  s21_sin = 9,     // s
  s21_cos = 10,    // c
  s21_tan = 11,    // t
  s21_acos = 12,   // C
  s21_asin = 13,   // S
  s21_atan = 14,   // T
  s21_sqrt = 15,   // q
  s21_ln = 16,     // l
  s21_log = 17,    // L
  bracket_l = 18,  // (
  bracket_r = 19,  // )
  un_minus = 20,   // u
  delet = -1
} type_t;

typedef struct {
  double value;
  int priority;
  type_t type;
  int num;
} s21_SmartCalc[SIZE];

int parser(char* str, s21_SmartCalc data, double x);
void init_struct(s21_SmartCalc);
void print_struct(s21_SmartCalc, int, int);
void if_digit(char* str, s21_SmartCalc, int);
int notation(s21_SmartCalc src, s21_SmartCalc data);
double calculate(s21_SmartCalc digit, s21_SmartCalc support);
void print_struct_for_str(s21_SmartCalc src);
int validator(char*);
double calc(s21_SmartCalc from_notation);
void str(char* arr);
int my_main(char* str, double* result, double x);
int credit_calc_ann(char* str_sum, char* str_mounth, char* str_percen,
                       double* str_gen_pay, double* str_over_pay,
                       double* str_pay);
int credit_calc_diff(char* str_sum, char* str_mounth, char* str_percen,
                     double* str_gen_pay, double* str_over_pay,
                     double* str_pay_min, double* str_pay_max);

double every_month(double dum, double percent, int mounth);
double over_pay_credit(double sum, double mounth);

#endif  // S21_SMARTCALC_H
