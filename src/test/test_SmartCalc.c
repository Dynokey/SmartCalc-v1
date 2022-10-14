#include "test_SmartCalc.h"
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
    char input[SIZE] = " (8.0 + (-2)) - 1 % 2.0";
    int v = validator(input);
    ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_trig_1) {
    char input[SIZE] = "1 % 2 + cos() + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) +l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_2) {
    char input[SIZE] = "1%2+cos(8.0)+sin(-2)+tan(acos(x)+asin(x))+atan(0)+sqrt(1)+l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_trig_3) {
    char input[SIZE] = "1 % 2 + cos8.0) + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) +l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_4) {
    char input[SIZE] = "1x % 2 + cos(8.0) + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) +l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_5) {
    char input[SIZE] = "1 % 2 + cos(x8.0) + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) +l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_6) {
    char input[SIZE] = "1 % 2 + x(8.0) + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) +l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_7) {
    char input[SIZE] = "1 % 2 + x8 + sin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) +l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_8) {
    char input[SIZE] = "1 % 2 + x8 + xsin(-2) +tan(acos(x) + asin(x)) +atan(0) +sqrt(-1) +l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 1);
}
END_TEST

START_TEST(validator_trig_9) {
    char input[SIZE] = "sin(-2)*tan(acos(x)/asin(x))^atan(0)+sqrt(-1)+l_n(log(2))";
    int v = validator(input);
    ck_assert_int_eq(v, 0);
}
END_TEST

START_TEST(validator_trig_10) {
    char input[SIZE] = "l_n(-2)*tan(acos(x)/asin(x))^atan(0)+sqrt(-1)+l_n(log(2))";
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
    credit_calc_ann(str_sum, str_mounth, str_percen, &str_gen_pay,
                        &str_over_pay, &str_pay_mounth);

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
    credit_calc_ann(str_sum, str_mounth, str_percen, &str_gen_pay,
                        &str_over_pay, &str_pay_mounth);

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
    

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
