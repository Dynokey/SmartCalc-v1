#include "s21_SmartCalc.h"

double calc(s21_SmartCalc rpn) {
  double arr[8] = {0};
  int count_arr = 0;

  for (int i = 0; rpn[i].num != -1; i++) {
    if (rpn[i].type == number) {
      arr[count_arr] = rpn[i].value;
      rpn[i].type = delet;
      count_arr++;
    } else if (rpn[i].type > 2) {
      switch (rpn[i].type) {
        case plus:
          arr[count_arr - 2] += arr[count_arr - 1];
          arr[count_arr - 1] = 0.0;
          rpn[i].type = delet;
          if (count_arr > 0) count_arr--;
          break;
        case minus:
          arr[count_arr - 2] -= arr[count_arr - 1];
          arr[count_arr - 1] = 0.0;
          rpn[i].type = delet;
          if (count_arr > 0) count_arr--;
          break;
        case mull:
          arr[count_arr - 2] *= arr[count_arr - 1];
          arr[count_arr - 1] = 0.0;
          rpn[i].type = delet;
          if (count_arr > 0) count_arr--;
          break;
        case del:
          arr[count_arr - 2] /= arr[count_arr - 1];
          arr[count_arr - 1] = 0.0;
          rpn[i].type = delet;
          if (count_arr > 0) count_arr--;
          break;
        case scale:
          arr[count_arr - 2] = pow(arr[count_arr - 2], arr[count_arr - 1]);
          arr[count_arr - 1] = 0.0;
          rpn[i].type = delet;
          if (count_arr > 0) count_arr--;
          break;
        case mod:
          arr[count_arr - 2] = fmod(arr[count_arr - 2], arr[count_arr - 1]);
          arr[count_arr - 1] = 0.0;
          rpn[i].type = delet;
          if (count_arr > 0) count_arr--;
          break;
        case s21_sin:
          arr[count_arr - 1] = sin(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case s21_cos:
          arr[count_arr - 1] = cos(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case s21_tan:
          arr[count_arr - 1] = tan(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case s21_asin:
          arr[count_arr - 1] = asin(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case s21_acos:
          arr[count_arr - 1] = acos(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case s21_atan:
          arr[count_arr - 1] = atan(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case s21_sqrt:
          arr[count_arr - 1] = sqrt(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case s21_ln:
          arr[count_arr - 1] = log(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case s21_log:
          arr[count_arr - 1] = log10(arr[count_arr - 1]);
          rpn[i].type = delet;
          break;
        case un_minus:
          arr[count_arr - 1] = arr[count_arr - 1] * -1;
          rpn[i].type = delet;
          break;
        default:
          break;
      }
    }
  }

  double ret = ((round(arr[0] * 100000000)) / 100000000);
  // while(ret - ret/10 < 0.1){
  //   ret = ret /10;
  // }
  return ret;
}