#include "s21_SmartCalc.h"

int validator(char* str) {
  char sign_full[32] = {'+', '-', '*', '/', '^', 'm', 's', 'c',
                        't', 'C', 'S', 'T', 'q', 'l', 'L', '('};
  char sign_func[16] = {
      's', 'c', 't', 'C', 'S', 'T', 'q', 'l', 'L',
  };
  char sign[16] = {'+', '-', '*', '/', '^', 'm', '.'};
  char sign_m[8] = {'*', '/', '^', 'm', ')'};
  char sign_for_x[16] = {'+', '-', '*', '/', '^', 'm', '.', '('};
  char num[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ')'};
  char symbol_for_back[24] = {'+', '-', '*', '/', '^', '+',
                              '-', '*', '/', '^', 'm', '('};
  int ret = 0;
  int len = strlen(str);
  int count_bracket = 0;

  // проверка на оператор в начале или в конце строки
  if (strchr(sign_full, str[len - 1]) != NULL) ret = 1;
  if (strchr(sign_m, str[0]) != NULL) ret = 1;

  for (int i = 0; i < len; i++) {
    // считаем скобки
    if (str[i] == '(') {
      count_bracket++;
    } else if (str[i] == ')') {
      count_bracket--;
    }
    if (count_bracket < 0) ret = 1;
    // проверка для 'x'
    if(i > 0 && str[i] == 'x' && strchr(sign_for_x, str[i - 1]) == NULL){
      ret = 1;
    }
    // ищем два оператора подряд '+-*/^'
    if (i > 0 && strchr(sign, str[i]) != NULL &&
        strchr(sign, str[i - 1]) != NULL) {
      ret = 1;
    }
    // проверяем на пустые скобки '()'
    if (i > 0 && str[i - 1] == '(' && str[i] == ')') {
      ret = 1;
    }
    // перед и после mod должно быть число
    if (str[i] == '%' &&
        (strchr(sign, str[i - 1]) || strchr(sign, str[i + 1]))) {
      ret = 1;
    }
    // после вызова функции должна быть '('
    // if(strchr(sign_func, str[i]) != NULL && str[i + 3] != '(') {
    //   ret = 1;
    // }
    // перед перед функцией не должно быть точки, числа или ')'
    if (i > 0 && strchr(sign_func, str[i]) != NULL &&
        strchr(num, str[i - 1]) != NULL) {
      ret = 1;
    }
    // перед '(' не может находиться число или точка
    if (i > 0 && str[i] == '(' && strchr(num, str[i - 1]) != NULL) {
      ret = 1;
    }

    // для backSpace перед вызовом функции не может быть букв
    if (i > 0 && strchr(sign_func, str[i]) != NULL &&
        strchr(symbol_for_back, str[i - 1]) == NULL) {
      ret = 1;
    }
    // меняем в строке 'sin' на 's', 'cos' на 'c' и т.д.
    if (str[i] == 's' && i + 2 < len && str[i + 1] == 'i' &&
        str[i + 2] == 'n') {
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      i += 2;
    }
    if (str[i] == 'c' && i + 2 < len && str[i + 1] == 'o' &&
        str[i + 2] == 's') {
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      i += 2;
    }
    if (str[i] == 't' && i + 2 < len && str[i + 1] == 'a' &&
        str[i + 2] == 'n') {
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      i += 2;
    }
    if (str[i] == 'a' && i + 3 < len && str[i + 1] == 's' &&
        str[i + 2] == 'i') {
      str[i] = 'S';
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      str[i + 3] = ' ';
      i += 3;
    }
    if (str[i] == 'a' && i + 3 < len && str[i + 1] == 'c' &&
        str[i + 2] == 'o') {
      str[i] = 'C';
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      str[i + 3] = ' ';
      i += 3;
    }
    if (str[i] == 'a' && i + 3 < len && str[i + 1] == 't' &&
        str[i + 2] == 'a') {
      str[i] = 'T';
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      str[i + 3] = ' ';
      i += 3;
    }
    if (str[i] == 's' && i + 3 < len && str[i + 1] == 'q' &&
        str[i + 2] == 'r') {
      str[i] = 'q';
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      str[i + 3] = ' ';
      i += 3;
    }
    if (str[i] == '%') {
      str[i] = 'm';
    }
    if (str[i] == 'l' && i + 2 < len && str[i + 1] == 'o' &&
        str[i + 2] == 'g') {
      str[i] = 'L';
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      i += 2;
    }
    if (str[i] == 'l' && i + 2 < len && str[i + 1] == '_' &&
        str[i + 2] == 'n') {
      str[i + 1] = ' ';
      str[i + 2] = ' ';
      i += 2;
    }
    // if(str[i] == '√'){
    //   str[i] = 'q';
    // }
  }

  if (count_bracket != 0) ret = 1;

  return ret;
}