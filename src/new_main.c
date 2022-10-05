#include "s21_SmartCalc.h"

int main() {
char sum [SIZE] = {'1', '0', '0', '0'};
char mounth [SIZE] = {'1', '2'};
char percent [SIZE] = {'1', '0'};
double gen_pay = 0.0;
double over_pay = 0.0;
double pay_min = 0.0;
// double pay_max = 0.0;

// credit_calc_diff(sum, mounth, percent, &gen_pay, &over_pay, &pay_min, &pay_max);
credit_calc_ann(sum, mounth, percent, &gen_pay, &over_pay, &pay_min);
printf("%f %f %f", gen_pay, over_pay, pay_min);

  // double result;
  // char str[SIZE] = {'4', '/', '5'};
  // char str[SIZE] = {'(', '5', '+', 'c', '(', '1', ')', '-', '1', '1', ')',
  // '*', '4', '/', '2', '+', '3', '^', '2', '^', '2'}; 
  // char str[SIZE] = {'(', '0', '-', '2', '-', '5', ')', '^', '(', '0', '-', '2', ')'};
  // char str[SIZE] = {'+', '1', '*', '(', '(', '-', '2', ')', '-', '5', ')', '^', '(', '-', '2', ')'};
  // char str[SIZE] = {'(', '(', '-', '2', '-', '3', ')', '/', '2', '+', '(', 's', '(', '3', ')',  '-', '7', ')', '*', '(', '8', '-', 'L', '(', '1', ')', ')', '^', 'l', '(', '+', '2', ')', ')'};
// 
//   char str[SIZE] = {'s', 's', 'i', 'n', '(', '1', ')'};
//   my_main(str, &result);
//   int valid = validator(str);
//   printf("%sin str = %s%s\n", BLUE, str, RESET);
// // 
//   if (valid == 0) {
//     s21_SmartCalc for_pars;
//     init_struct(for_pars);
//     parser(str, for_pars);

//     s21_SmartCalc for_notation;
//     init_struct(for_notation);
//     notation(for_pars, for_notation);
    
//     print_struct_for_str(for_pars);
//     print_struct_for_str(for_notation);
//     double result = calc(for_notation);
//     printf("%sresult = %f%s\n", RED, result, RESET);

//   } else {
//     printf("%s INCORRECT INPUT%s\n", RED, RESET);
//   }
  return 0;
}

