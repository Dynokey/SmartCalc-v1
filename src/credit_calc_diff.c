#include "s21_SmartCalc.h"

double credit_calc_diff(char* str, int mounth, double percent) {
  double sum = atof(str);
  double pay_mounth_max = 0.0;
  double pay_mounth_min = 0.0;
  double over_pay = 0.0;

  double sum_gen = sum / mounth;

  for (int i = 0; i < mounth; i++) {
    double rem_debt = sum - (sum_gen * i);
    over_pay += rem_debt * percent / 100 / 12;
    if(i == 0)
        pay_mounth_max = sum_gen + rem_debt * percent / 100 / 12;
    if(i == mounth - 1)
        pay_mounth_min = sum_gen + rem_debt * percent / 100 / 12;
  }
  double general_pay = sum + over_pay;
  printf("%f\n", sum);
  printf("%f\n", over_pay);
  printf("%f\n", pay_mounth_min);
  printf("%f\n", pay_mounth_max);
  printf("%f\n", general_pay);

  return sum;
}
