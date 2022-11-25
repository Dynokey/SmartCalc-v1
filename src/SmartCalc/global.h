#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>


namespace global {
  //! значение "х"
  extern double x_value;
  //! флаг отслеживания поступления "х" в выражение
  extern bool flag_x_value;
  //! строка для обработки знака "=" в окне "х"
  extern  QString str_for_x_eq;
  //! строка для обработки в окне графика
  extern QString str_for_graf;
  //! флаг для кнопки окрытия окна депозитного или кредитного калькулятора
  extern int flag_dep_or_credit;
}

#endif // GLOBAL_H
