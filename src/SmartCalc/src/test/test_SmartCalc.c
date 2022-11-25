#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../s21_SmartCalc.h"

START_TEST(validator_1) {
  char input[SIZE] = " -(8 + (-2))) -1 - 2";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_2) {
  char input[SIZE] = "-(8.0009)+(-2.0) -1 - 2";
  int v = validator(input);
  ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_3) {
  char input[SIZE] = "%3-4sin(1)";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_4) {
  char input[SIZE] = " -(-8 * z(-2))) -1 - 2";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_5) {
  char input[SIZE] = " (8.0 + (-2)) -1 - 2(";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_6) {
  char input[SIZE] = " (8.0 + (-2)) -1 -- 2";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_7) {
  char input[SIZE] = "(8+(-2))-1%2";
  int v = validator(input);
  ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_trig_1) {
  char input[SIZE] =
      "1 % 2 + cos() + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) "
      "+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_2) {
  char input[SIZE] =
      "1%2+cos(8.0)+sin(-2)+tan(acos(x)+asin(x))+atan(0)+sqrt(1)+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_trig_3) {
  char input[SIZE] =
      "1 % 2 + cos8.0) + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) "
      "+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_4) {
  char input[SIZE] =
      "1x % 2 + cos(8.0) + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) "
      "+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_5) {
  char input[SIZE] =
      "1 % 2 + cos(x8.0) + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) "
      "+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_6) {
  char input[SIZE] =
      "1 % 2 + x(8.0) + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) "
      "+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_7) {
  char input[SIZE] =
      "1 % 2 + x8 + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) "
      "+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_8) {
  char input[SIZE] =
      "1 % 2 + x8 + xsin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) "
      "+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_9) {
  char input[SIZE] =
      "sin(-2)*tan(acos(x)/asin(x))^atan(0)+sqrt(-1)+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_trig_10) {
  char input[SIZE] =
      "l_n(-2)*tan(acos(x)/asin(x))^atan(0)+sqrt(-1)+l_n(log(2))";
  int v = validator(input);
  ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_other_1) {
  char input[SIZE] = "x + 1";
  int v = validator(input);
  ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_other_2) {
  char input[SIZE] = "xx";
  int v = validator(input);
  ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(credit_ann_1) {
  char str_sum[8] = "150500.0";
  char str_mounth[8] = "2";
  char str_percen[8] = "10";
  double str_gen_pay;
  double str_over_pay;
  double str_pay_mounth;
  // double ori_m_1 = ;
  double orig_gen_pay = 152383.86;
  double orig_over_pay = 1883.86;
  double orig_pay_mounth = 76191.93;
  credit_calc_ann(str_sum, str_mounth, str_percen, &str_gen_pay, &str_over_pay,
                  &str_pay_mounth);

  ck_assert_double_eq_tol(str_gen_pay, orig_gen_pay, 0.01);
  ck_assert_double_eq_tol(str_over_pay, orig_over_pay, 0.01);
  ck_assert_double_eq_tol(str_pay_mounth, orig_pay_mounth, 0.01);
}
END_TEST

START_TEST(credit_ann_2) {
  char str_sum[8] = "150.0";
  char str_mounth[8] = "100";
  char str_percen[8] = "13.2";
  double str_gen_pay;
  double str_over_pay;
  double str_pay_mounth;
  // double ori_m_1 = ;
  double orig_gen_pay = 248;
  double orig_over_pay = 98;
  double orig_pay_mounth = 2.48;
  credit_calc_ann(str_sum, str_mounth, str_percen, &str_gen_pay, &str_over_pay,
                  &str_pay_mounth);

  ck_assert_double_eq_tol(str_gen_pay, orig_gen_pay, 0.01);
  ck_assert_double_eq_tol(str_over_pay, orig_over_pay, 0.01);
  ck_assert_double_eq_tol(str_pay_mounth, orig_pay_mounth, 0.01);
}
END_TEST

START_TEST(credit_ann_3) {
  char str_sum[8] = "0";
  char str_mounth[8] = "0";
  char str_percen[8] = "0";
  double str_gen_pay;
  double str_over_pay;
  double str_pay_mounth;
  int res = credit_calc_ann(str_sum, str_mounth, str_percen, &str_gen_pay,
                            &str_over_pay, &str_pay_mounth);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(credit_diff_1) {
  char str_sum[8] = "150500.0";
  char str_mounth[8] = "2";
  char str_percen[8] = "10";
  double str_gen_pay;
  double str_over_pay;
  double str_pay_min;
  double str_pay_max;
  // double ori_m_1 = ;
  double orig_gen_pay = 152381.25;
  double orig_over_pay = 1881.25;
  double orig_pay_min = 75877.08;
  double orig_pay_max = 76504.17;
  credit_calc_diff(str_sum, str_mounth, str_percen, &str_gen_pay, &str_over_pay,
                   &str_pay_min, &str_pay_max);

  ck_assert_double_eq_tol(str_gen_pay, orig_gen_pay, 0.01);
  ck_assert_double_eq_tol(str_over_pay, orig_over_pay, 0.01);
  ck_assert_double_eq_tol(str_pay_min, orig_pay_min, 0.01);
  ck_assert_double_eq_tol(str_pay_max, orig_pay_max, 0.01);
}
END_TEST

START_TEST(credit_diff_2) {
  char str_sum[8] = "1500.0";
  char str_mounth[8] = "100";
  char str_percen[8] = "13.2";
  double str_gen_pay;
  double str_over_pay;
  double str_pay_min;
  double str_pay_max;
  // double ori_m_1 = ;
  double orig_gen_pay = 2333.25;
  double orig_over_pay = 833.25;
  double orig_pay_min = 15.17;
  double orig_pay_max = 31.5;
  credit_calc_diff(str_sum, str_mounth, str_percen, &str_gen_pay, &str_over_pay,
                   &str_pay_min, &str_pay_max);

  ck_assert_double_eq_tol(str_gen_pay, orig_gen_pay, 0.01);
  ck_assert_double_eq_tol(str_over_pay, orig_over_pay, 0.01);
  ck_assert_double_eq_tol(str_pay_min, orig_pay_min, 0.01);
  ck_assert_double_eq_tol(str_pay_max, orig_pay_max, 0.01);
}
END_TEST

START_TEST(credit_diff_3) {
  char str_sum[8] = "0";
  char str_mounth[8] = "0";
  char str_percen[8] = "0";
  double str_gen_pay;
  double str_over_pay;
  double str_pay_min;
  double str_pay_max;
  int res = credit_calc_diff(str_sum, str_mounth, str_percen, &str_gen_pay, &str_over_pay,
                   &str_pay_min, &str_pay_max);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(notation_1) {
  char str_on[16] = "1+2^2-sqrt4+2%2";
  double res;
  double x = 1;
  my_main(str_on, &res, x);
  ck_assert_double_eq_tol(res, 3, 0.0000001);
}
END_TEST

START_TEST(notation_2) {
  char str_on[16] = "-1+2*x-(2/2-1)";
  double res;
  double x = 1;
  my_main(str_on, &res, x);
  ck_assert_double_eq_tol(res, 1, 0.0000001);
}
END_TEST

START_TEST(notation_3) {
  char str_on[16] = "(-1 )";
  double res;
  double x = 1;
  my_main(str_on, &res, x);
  ck_assert_double_eq_tol(res, -1, 0.0000001);
}
END_TEST

START_TEST(trigonometric_1) {
  char str_on[16] = "sin(1)+cos(1)";
  double res;
  double x = 1;
  my_main(str_on, &res, x);
  ck_assert_double_eq_tol(res, 1.38177329, 0.0000001);
}
END_TEST

START_TEST(trigonometric_2) {
  char str_on[24] = "tan(1)+asin(1)*acos(1)";
  double res;
  double x = 1;
  my_main(str_on, &res, x);
  ck_assert_double_eq_tol(res, 1.55740772, 0.0000001);
}
END_TEST

START_TEST(trigonometric_3) {
  char str_on[24] = "atan(log(l_n(100)))";
  double res;
  double x = 1;
  my_main(str_on, &res, x);
  ck_assert_double_eq_tol(res, 0.58563049, 0.0000001);
}
END_TEST

START_TEST(trigonometric_4) {
  char str_on[24] = ".1";
  double res;
  double x = 1;
  my_main(str_on, &res, x);
  ck_assert_double_eq_tol(res, 0.1, 0.0000001);
}
END_TEST

START_TEST(deposit_calc_1) {
  double sum = 10000;
  int day = 90;
  double interest_rate = 10;
  double tax_rate = 5;
  type_d period_pay = pay_every_day;
  type_d cap_percent = cap_no;
  int transaction = 0;
  double sum_transaction = 0;
  double sum_end;
  double sum_tax;
  double percen; 
  double origin_sum_end = 10000;
  double origin_sum_tax = 12.33;
  double origin_percen = 246.58;
  deposit_calc(sum, day, interest_rate, tax_rate, period_pay, cap_percent, transaction, sum_transaction, &sum_end,&sum_tax, &percen);

  ck_assert_double_eq_tol(sum_end, origin_sum_end, 0.1);
  ck_assert_double_eq_tol(sum_tax, origin_sum_tax, 0.1);
  ck_assert_double_eq_tol(percen, origin_percen, 0.1);
}
END_TEST

START_TEST(deposit_calc_2) {
  double sum = 10000;
  int day = 90;
  double interest_rate = 10;
  double tax_rate = 5;
  type_d period_pay = pay_every_day;
  type_d cap_percent = cap_no;
  int transaction = 0;
  double sum_transaction = 0;
  double sum_end;
  double sum_tax;
  double percen; 
  double origin_sum_end = 10000;
  double origin_sum_tax = 12.33;
  double origin_percen = 246.58;
  deposit_calc(sum, day, interest_rate, tax_rate, period_pay, cap_percent, transaction, sum_transaction, &sum_end,&sum_tax, &percen);

  ck_assert_double_eq_tol(sum_end, origin_sum_end, 0.1);
  ck_assert_double_eq_tol(sum_tax, origin_sum_tax, 0.1);
  ck_assert_double_eq_tol(percen, origin_percen, 0.1);
}
END_TEST

START_TEST(deposit_calc_3) {
  double sum = 10000;
  int day = 90;
  double interest_rate = 10;
  double tax_rate = 5;
  type_d period_pay = pay_at_the_end;
  type_d cap_percent = cap_yes;
  int transaction = 0;
  double sum_transaction = 0;
  double sum_end;
  double sum_tax;
  double percen; 
  double origin_sum_end = 10247;
  double origin_sum_tax = 12.33;
  double origin_percen = 247;
  deposit_calc(sum, day, interest_rate, tax_rate, period_pay, cap_percent, transaction, sum_transaction, &sum_end,&sum_tax, &percen);

  ck_assert_double_eq_tol(sum_end, origin_sum_end, 1);
  ck_assert_double_eq_tol(sum_tax, origin_sum_tax, 1);
  ck_assert_double_eq_tol(percen, origin_percen, 1);
}
END_TEST

START_TEST(deposit_calc_4) {
  double sum = 10000;
  int day = 300;
  double interest_rate = 10;
  double tax_rate = 10;
  type_d period_pay = pay_every_day;
  type_d cap_percent = cap_yes;
  int transaction = 0;
  double sum_transaction = 0;
  double sum_end;
  double sum_tax;
  double percen; 
  double origin_sum_end = 10856;
  double origin_sum_tax = 85;
  double origin_percen = 856;
  deposit_calc(sum, day, interest_rate, tax_rate, period_pay, cap_percent, transaction, sum_transaction, &sum_end,&sum_tax, &percen);

  ck_assert_double_eq_tol(sum_end, origin_sum_end, 1);
  ck_assert_double_eq_tol(sum_tax, origin_sum_tax, 1);
  ck_assert_double_eq_tol(percen, origin_percen, 1);
}
END_TEST

START_TEST(deposit_calc_5) {
  double sum = 10000;
  int day = 600;
  double interest_rate = 10;
  double tax_rate = 10;
  type_d period_pay = pay_every_year;
  type_d cap_percent = cap_no;
  int transaction = 0;
  double sum_transaction = 0;
  double sum_end;
  double sum_tax;
  double percen; 
  double origin_sum_end = 10000;
  double origin_sum_tax = 164;
  double origin_percen = 1643;
  deposit_calc(sum, day, interest_rate, tax_rate, period_pay, cap_percent, transaction, sum_transaction, &sum_end,&sum_tax, &percen);

  ck_assert_double_eq_tol(sum_end, origin_sum_end, 1);
  ck_assert_double_eq_tol(sum_tax, origin_sum_tax, 1);
  ck_assert_double_eq_tol(percen, origin_percen, 1);
}
END_TEST

START_TEST(deposit_calc_6) {
  double sum = 10000;
  int day = 600;
  double interest_rate = 10;
  double tax_rate = 10;
  type_d period_pay = pay_every_year;
  type_d cap_percent = cap_yes;
  int transaction = 30;
  double sum_transaction = 0;
  double sum_end;
  double sum_tax;
  double percen; 
  double origin_sum_end = 11000;
  double origin_sum_tax = 171;
  double origin_percen = 708;
  deposit_calc(sum, day, interest_rate, tax_rate, period_pay, cap_percent, transaction, sum_transaction, &sum_end,&sum_tax, &percen);

  ck_assert_double_eq_tol(sum_end, origin_sum_end, 1);
  ck_assert_double_eq_tol(sum_tax, origin_sum_tax, 1);
  ck_assert_double_eq_tol(percen, origin_percen, 1);
}
END_TEST

START_TEST(deposit_calc_7) {
  double sum = 10000;
  int day = 600;
  double interest_rate = 10;
  double tax_rate = 10;
  type_d period_pay = pay_at_the_end;
  type_d cap_percent = cap_no;
  int transaction = 0;
  double sum_transaction = 0;
  double sum_end;
  double sum_tax;
  double percen; 
  double origin_sum_end = 10000;
  double origin_sum_tax = 164;
  double origin_percen = 1644;
  deposit_calc(sum, day, interest_rate, tax_rate, period_pay, cap_percent, transaction, sum_transaction, &sum_end,&sum_tax, &percen);

  ck_assert_double_eq_tol(sum_end, origin_sum_end, 1);
  ck_assert_double_eq_tol(sum_tax, origin_sum_tax, 1);
  ck_assert_double_eq_tol(percen, origin_percen, 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc);
  tcase_add_test(tc, validator_1);
  tcase_add_test(tc, validator_2);
  tcase_add_test(tc, validator_3);
  tcase_add_test(tc, validator_4);
  tcase_add_test(tc, validator_5);
  tcase_add_test(tc, validator_6);
  tcase_add_test(tc, validator_7);
  tcase_add_test(tc, validator_trig_1);
  tcase_add_test(tc, validator_trig_2);
  tcase_add_test(tc, validator_trig_3);
  tcase_add_test(tc, validator_trig_4);
  tcase_add_test(tc, validator_trig_5);
  tcase_add_test(tc, validator_trig_6);
  tcase_add_test(tc, validator_trig_7);
  tcase_add_test(tc, validator_trig_8);
  tcase_add_test(tc, validator_trig_9);
  tcase_add_test(tc, validator_trig_10);
  tcase_add_test(tc, validator_other_1);
  tcase_add_test(tc, validator_other_2);
  tcase_add_test(tc, credit_ann_1);
  tcase_add_test(tc, credit_ann_2);
  tcase_add_test(tc, credit_ann_3);
  tcase_add_test(tc, credit_diff_1);
  tcase_add_test(tc, credit_diff_2);
  tcase_add_test(tc, credit_diff_3);
  tcase_add_test(tc, notation_1);
  tcase_add_test(tc, notation_2);
  tcase_add_test(tc, notation_3);
  tcase_add_test(tc, trigonometric_1);
  tcase_add_test(tc, trigonometric_2);
  tcase_add_test(tc, trigonometric_3);
  tcase_add_test(tc, trigonometric_4);
  tcase_add_test(tc, deposit_calc_1);
  tcase_add_test(tc, deposit_calc_2);
  tcase_add_test(tc, deposit_calc_3);
  tcase_add_test(tc, deposit_calc_4);
  tcase_add_test(tc, deposit_calc_5);
  tcase_add_test(tc, deposit_calc_6);
  tcase_add_test(tc, deposit_calc_7);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
