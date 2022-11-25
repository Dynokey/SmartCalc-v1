#include "s21_SmartCalc.h"

int deposit_calc(double sum, int day, double interest_rate, double tax_rate,
                 type_d period_pay, type_d cap_percen, int transaction,
                 double sum_transaction, double* sum_end, double* sum_tax,
                 double* percen) {
  double* trans_arr;
  trans_arr = calloc(day, sizeof(double));

  if (trans_arr == NULL) return 1;
  if (transaction < 1) {
    transaction = 1;
  }

  create_arr(day, transaction, sum_transaction, trans_arr);

  if (cap_percen == cap_no && period_pay == pay_at_the_end) {
    simple_deposit_calc(sum, day, interest_rate, tax_rate, trans_arr, sum_end,
                        sum_tax, percen);
  } else if (cap_percen == cap_yes && period_pay == pay_at_the_end) {
    simple_deposit_calc(sum, day, interest_rate, tax_rate, trans_arr, sum_end,
                        sum_tax, percen);
    *sum_end += *percen;
  } else if (cap_percen == cap_no && period_pay == pay_every_day) {
    no_cap_percent_pay_everyday(sum, day, interest_rate, tax_rate, trans_arr,
                                sum_end, sum_tax, percen);
  } else if (cap_percen == cap_yes && period_pay == pay_every_day) {
    cap_percent_pay_everyday(sum, day, interest_rate, tax_rate, trans_arr,
                             sum_end, sum_tax, percen);
  } else if (cap_percen == cap_no && period_pay == pay_every_year) {
    no_cap_percent_year(sum, day, interest_rate, tax_rate, trans_arr, sum_end,
                        sum_tax, percen);
  } else if (cap_percen == cap_yes && period_pay == pay_every_year) {
    cap_percent_year(sum, day, interest_rate, tax_rate, trans_arr, sum_end,
                     sum_tax, percen);
  }
  free(trans_arr);
  return 0;
}

void create_arr(int day, int transaction, double sum_transaction,
                double* trans_arr) {
  int tmp = day % transaction;
  for (int i = 0; i < day; i++) {
    if ((day - i) % transaction == tmp) {
      trans_arr[i] = sum_transaction;
    } else {
      trans_arr[i] = 0;
    }
  }
}

void simple_deposit_calc(double sum, int day, double interest_rate,
                         double tax_rate, double* trans_arr, double* sum_end,
                         double* sum_tax, double* percen) {
  *sum_end = sum;

  for (int i = 0; i < day; i++) {
    *sum_end += trans_arr[i];
    *percen += ((*sum_end + trans_arr[i]) * interest_rate) / 365 / 100;
  }
  *sum_tax = *percen * tax_rate / 100;

  *sum_end = round(*sum_end * 100) / 100;
  *sum_tax = round(*sum_tax * 100) / 100;
  *percen = round(*percen * 100) / 100;
}

void cap_percent_pay_everyday(double sum, int day, double interest_rate,
                              double tax_rate, double* trans_arr,
                              double* sum_end, double* sum_tax,
                              double* percen) {
  double sum_and_percen = sum;
  double percen_day = 0.0;

  for (int i = 0; i < day; i++) {
    double tmp_percen_day = 0.0;
    tmp_percen_day = (sum_and_percen * interest_rate) / 365 / 100;
    percen_day += tmp_percen_day;
    sum_and_percen += tmp_percen_day + trans_arr[i];
  }
  *sum_end = round((sum_and_percen)*100) / 100;
  *percen = round(percen_day * 100) / 100;
  *sum_tax = round(*percen * tax_rate) / 100;
}

void no_cap_percent_pay_everyday(double sum, int day, double interest_rate,
                                 double tax_rate, double* trans_arr,
                                 double* sum_end, double* sum_tax,
                                 double* percen) {
  double sum_tmp = sum;
  double percen_day = 0.0;

  for (int i = 0; i < day; i++) {
    percen_day += (sum_tmp * interest_rate) / 365 / 100;
    sum_tmp += trans_arr[i];
  }
  *sum_end = sum_tmp;
  *percen = round(percen_day * 100) / 100;
  *sum_tax = round(*percen * tax_rate) / 100;
}

void cap_percent_year(double sum, int day, double interest_rate,
                      double tax_rate, double* trans_arr, double* sum_end,
                      double* sum_tax, double* percen) {
  double out_sum = sum;
  double out_percen = 0.0;

  for (int i = day; i >= 365; i -= 365) {
    out_percen = (out_sum * interest_rate) / 100;
    out_sum += out_percen;
  }

  double tmp_percent = 0.0;
  int tmp_day = day % 365;
  double tmp_tax = 0.0;

  // printf("out_sum %f\n tmp_percent %f\n tmp day %d \n", out_sum, tmp_percent,
  // tmp_day);

  simple_deposit_calc(out_sum, tmp_day, interest_rate, tax_rate,
                      &trans_arr[tmp_day], sum_end, &tmp_tax, &tmp_percent);
  *percen = round((*percen + tmp_percent) * 100) / 100;
  *sum_tax = round((out_sum + *percen - sum) * tax_rate) / 100;
}

void no_cap_percent_year(double sum, int day, double interest_rate,
                         double tax_rate, double* trans_arr, double* sum_end,
                         double* sum_tax, double* percen) {
  double out_sum = sum;
  double out_percen = 0.0;

  if (day > 365) {
    for (int i = 365; i < day; i += 365) {
      out_percen += (out_sum * interest_rate) / 100;

      for (int j = i; j <= i + 364 && (j + i) < day; j++) {
        out_sum += trans_arr[j];
      }
    }
  }

  double tmp_percent = 0.0;
  int tmp_day = day % 365;
  double tmp_tax = 0.0;

  simple_deposit_calc(out_sum, tmp_day, interest_rate, tax_rate,
                      &trans_arr[day - tmp_day], sum_end, &tmp_tax,
                      &tmp_percent);

  // *sum_end += out_sum;
  *percen = out_percen + tmp_percent;
  // printf("sum_tax %f percen %f tax_rate %f tmp_tax %f", sum_tax, percen,
  // tax_rate, tmp_tax);
  *sum_tax = round(*percen * tax_rate) / 100;
}