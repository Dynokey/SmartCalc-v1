#include "s21_SmartCalc.h"

double credit_calc_ann(char* str, int mounth, double percent) {
  double sum = atof(str);
  double pay_mounth = round(every_month(sum, percent, mounth) * 100) / 100;
  double general_pay = round((pay_mounth * mounth) * 100) / 100;
  double over_pay = round((general_pay - sum) * 100) / 100;

  printf("%f\n", sum);
  printf("%f\n", pay_mounth);
  printf("%f\n", over_pay);
  printf("%f\n", general_pay);

  return sum;
}

double every_month(double sum, double percent, int mounth) {
  double per_mounth = percent / 100.0 / 12.0;
  double ret =
      sum * (per_mounth + (per_mounth / (pow((1 + per_mounth), mounth) - 1)));
  return ret;
}
