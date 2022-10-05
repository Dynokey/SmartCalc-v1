#include "s21_SmartCalc.h"

int credit_calc_diff(char* str_sum, char* str_mounth, char* str_percen, double* str_gen_pay, double* str_over_pay, double* str_pay_min, double* str_pay_max) {

  double sum = atof(str_sum);
  int mounth = atoi(str_mounth);
  double percent = atof(str_percen);

  double pay_mounth_max = 0.0;
  double pay_mounth_min = 0.0;
  double over = 0.0;
  double general_pay = 0.0;
  double sum_gen = sum / mounth;

  for (int i = 0; i < mounth; i++) {
    double rem_debt = sum - (sum_gen * i);
    over += rem_debt * percent / 100 / 12;
    if (i == 0) pay_mounth_max = sum_gen + rem_debt * percent / 100 / 12;
    if (i == mounth - 1)
      pay_mounth_min = sum_gen + rem_debt * percent / 100 / 12;
  }

  general_pay = sum + over;

  *str_gen_pay = round(general_pay * 100) / 100;
  *str_over_pay = round(over * 100) / 100;
  *str_pay_max = round(pay_mounth_max * 100) / 100;
  *str_pay_min = round(pay_mounth_min * 100) / 100;

  return 0;
}