#include "s21_SmartCalc.h"

int credit_calc_ann(char* str_sum, char* str_mounth, char* str_percen, double* str_gen_pay,
                        double* str_over_pay, double* str_pay_mounth) {
  int ret = 0;
  
  double sum = atof(str_sum);
  int mounth = atoi(str_mounth);
  double percent = atof(str_percen);
  
  if(sum < 0.0000001 || mounth < 1 || percent < 0.0000001)
    ret = 1;
  if(ret == 0){
  double pay_mounth = round(every_month(sum, percent, mounth) * 100) / 100;
  double general_pay = round((pay_mounth * mounth) * 100) / 100;
  double over_pay = round((general_pay - sum) * 100) / 100;

  *str_gen_pay = general_pay;
  *str_over_pay = over_pay;
  *str_pay_mounth = pay_mounth;
  }
  return ret;
}

double every_month(double sum, double percent, int mounth) {
  double per_mounth = percent / 100.0 / 12.0;
  double ret =
      sum * (per_mounth + (per_mounth / (pow((1 + per_mounth), mounth) - 1)));
  return ret;
}
