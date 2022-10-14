#include "s21_SmartCalc.h"

int my_main(char* str, double* res, double x) {
  int valid = validator(str);

  if (valid == 0) {
    s21_SmartCalc for_pars;
    init_struct(for_pars);
    parser(str, for_pars, x);
    print_struct_for_str(for_pars);
    s21_SmartCalc for_notation;
    init_struct(for_notation);
    notation(for_pars, for_notation);
    print_struct_for_str(for_notation);
    *res = calc(for_notation);
  }
  //   printf("%sresult = %.10f%s\n", RED, result, RESET);
  // } else {
  //   printf("%s INCORRECT INPUT%s\n", RED, RESET);
  // }
  return valid;
}