/// \file
#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define BLUE_P "\033[1;45m"

/**
 * @brief значения параметров для функции deposit_calc.c
 */
typedef enum {
  //! с капитализацией процентов
  cap_yes,
  //! без капитализации процентов
  cap_no,
  //! выплата процентов каждый день
  pay_every_day,
  //! выплата процентов каждый год
  pay_every_year,
  //! выплата процентов в конце срока
  pay_at_the_end,
} type_d;

typedef enum {
  number = 1,
  x = 2,
  plus = 3,        // +
  minus = 4,       // -
  mull = 5,        // *
  del = 6,         // /
  scale = 7,       // ^
  mod = 8,         // m
  s21_sin = 9,     // s
  s21_cos = 10,    // c
  s21_tan = 11,    // t
  s21_acos = 12,   // C
  s21_asin = 13,   // S
  s21_atan = 14,   // T
  s21_sqrt = 15,   // q
  s21_ln = 16,     // l
  s21_log = 17,    // L
  bracket_l = 18,  // (
  bracket_r = 19,  // )
  un_minus = 20,   // u
  delet = -1,
} type_t;

/**
 * @brief Сруктура для записи лексемы
 */
typedef struct {
  //! Числовое значение лексемы если таковое имеется
  double value;
  //! Приоритет лексемы
  int priority;
  //! Тип лексемы
  type_t type;
  //! Порядковый номер структуры в массиве структур
  int num;
} s21_SmartCalc[SIZE];

/**
 * @brief Функция анализа сторки
 *
 * @param str указатель на входящую строку
 * @param data указатель на массив структур для записи результата анализа
 * @param x отдельный аргумент для входящего х
 * @return int 0 в случае успеха
 */
int parser(char* str, s21_SmartCalc data, double x);

/**
 * @brief Фукция инициализации массива структур
 * @param data указатель на массив структур
 */
void init_struct(s21_SmartCalc data);
/**
 * @brief 
 * 
 * @param data 
 * @param a 
 * @param b 
 */
void print_struct(s21_SmartCalc data, int a, int b);
/**
 * @brief Функция обработки цифр. Запускается в int parser() если во входящей
 * строке обнаруживается цифра
 * @param str указатель на входящюю строку
 * @param data указатель на массив структур для записи результата
 * @param a количество обработанных структур, для определения номера структуры с
 * цифрой
 */
void if_digit(char* str, s21_SmartCalc data, int a);
/**
 * @brief Фунция принимает из parser() массив структур и перестраивает его
 * по правилам обратной польской нотации (постфиксная запись)
 * @param src указатель на входящий массив структур
 * @param data указатель на массив структур для записи результата
 * @return int в случае успеха возвращает 0
 */
int notation(s21_SmartCalc src, s21_SmartCalc data);
/**
 * @brief Фук
 *
 * @param digit
 * @param support
 * @return double
 */
double calculate(s21_SmartCalc digit, s21_SmartCalc support);
/**
 * @brief Вспомогательная функция. Выводит на экран из массива структур только
 * поля которые учавствуют в выражении
 * @param src указатель на массив структур
 */
void print_struct_for_str(s21_SmartCalc src);
/**
 * @brief Фукция анализа входищей строки на валидность и ее редакиторавания
 * для обработки в notation()
 * @return int В случае успеха возвращает 0
 */
int validator(char*);
/**
 * @brief Функция подсчета выражения полученного из notation()
 *
 * @param from_notation указатель на вохдящий массив структур
 * @return double возвращает результат подсчета
 */
double calc(s21_SmartCalc from_notation);
/**
 * @brief
 *
 * @param arr
 */
void str(char* arr);
/**
 * @brief
 *
 * @param str
 * @param result
 * @param x
 * @return int
 */
int my_main(char* str, double* result, double x);
/**
 * @brief Крединый калькулятор, аннуитетные платежи
 *
 * @param str_sum сумма кредита
 * @param str_mounth срок кредитования в месяцах
 * @param str_percen процентная ставка
 * @param str_gen_pay ежемесячный платеж
 * @param str_over_pay переплата по кредиту
 * @param str_pay общая выплата
 * @return int В случае успеха возвращает 0
 */
int credit_calc_ann(char* str_sum, char* str_mounth, char* str_percen,
                    double* str_gen_pay, double* str_over_pay, double* str_pay);
/**
 * @brief Кредитный калькулятор, дифференцированные платежи
 *
 * @param str_sum сумма кредита
 * @param str_mounth срок кредитования в месяцах
 * @param str_percen процентная ставка
 * @param str_gen_pay ежемесячный платеж
 * @param str_over_pay переплата по кредиту
 * @param str_pay_min минимальный платеж
 * @param str_pay_max максимальный платеж
 * @return int В случае успеха возвращает 0
 */
int credit_calc_diff(char* str_sum, char* str_mounth, char* str_percen,
                     double* str_gen_pay, double* str_over_pay,
                     double* str_pay_min, double* str_pay_max);
/**
 * @brief Вспомогательная функция credit_calc_ann() для подсчета
 * ежемесячный платежей
 * @param sum сумма
 * @param percent процентная ставка
 * @param mounth срок в месяцах
 * @return double размер платежа
 */
double every_month(double sum, double percent, int mounth);
/**
 * @brief
 *
 * @param sum
 * @param mounth
 * @return double
 */
double over_pay_credit(double sum, double mounth);
/**
 * @brief Депозитный калькулятор
 *
 * @param sum сумма депозита
 * @param day срок размещения
 * @param interest_rate процентная ставка
 * @param tax_rate налоговая ставка
 * @param period_pay период выплат
 * @param cap_percen капитализация процентов да/нет
 * @param transaction пополнения или снятия
 * @param sum_transaction сумма пополнения или снятий
 * @param sum_end сумма в конце срока размещения
 * @param sum_tax сумма налога
 * @param percen начисленные проценты
 * @return int В случае успеха возвращает 0
 */
int deposit_calc(double sum, int day, double interest_rate, double tax_rate,
                 type_d period_pay, type_d cap_percen, int transaction,
                 double sum_transaction, double* sum_end, double* sum_tax,
                 double* percen);
/**
 * @brief Функция создания массива для обработки снятий или пополнений
 *
 * @param day переодичность снятий/пополнений
 * @param transaction снятие или пополнение
 * @param sum_transaction сумма снятий/пополнений
 * @param p_arr
 */
void create_arr(int day, int transaction, double sum_transaction,
                double* p_arr);
/**
 * @brief Рассчет простого депозита
 *
 * @param sum сумма
 * @param day срок
 * @param interest_rate процентная ставка
 * @param tax_rate налоговая ставка
 * @param trans_arr трансакции
 * @param sum_end сумма в конце периода
 * @param sum_tax сумма налогов
 * @param percen начисленные проценты
 */
void simple_deposit_calc(double sum, int day, double interest_rate,
                         double tax_rate, double* trans_arr, double* sum_end,
                         double* sum_tax, double* percen);

/**
 * @brief Капитализация есть, выплаты каждый день
 *
 * @param sum
 * @param day
 * @param interest_rate
 * @param tax_rate
 * @param trans_arr
 * @param sum_end
 * @param sum_tax
 * @param percen
 */
void cap_percent_pay_everyday(double sum, int day, double interest_rate,
                              double tax_rate, double* trans_arr,
                              double* sum_end, double* sum_tax, double* percen);
/**
 * @brief Капитализации нет, выплаты каждый день
 *
 * @param sum
 * @param day
 * @param interest_rate
 * @param tax_rate
 * @param trans_arr
 * @param sum_end
 * @param sum_tax
 * @param percen
 */
void no_cap_percent_pay_everyday(double sum, int day, double interest_rate,
                                 double tax_rate, double* trans_arr,
                                 double* sum_end, double* sum_tax,
                                 double* percen);
/**
 * @brief Капитализация есть, выплаты раз в год
 *
 * @param sum
 * @param day
 * @param interest_rate
 * @param tax_rate
 * @param trans_arr
 * @param sum_end
 * @param sum_tax
 * @param percen
 */
void no_cap_percent_year(double sum, int day, double interest_rate,
                         double tax_rate, double* trans_arr, double* sum_end,
                         double* sum_tax, double* percen);
/**
 * @brief Капитализации нет, выплаты раз в год
 *
 * @param sum
 * @param day
 * @param interest_rate
 * @param tax_rate
 * @param trans_arr
 * @param sum_end
 * @param sum_tax
 * @param percen
 */
void cap_percent_year(double sum, int day, double interest_rate,
                      double tax_rate, double* trans_arr, double* sum_end,
                      double* sum_tax, double* percen);

#endif  // S21_SMARTCALC_H
