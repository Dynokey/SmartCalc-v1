#include "s21_SmartCalc.h"

int parser(char* str, s21_SmartCalc tmp, double x) {
  int num_struct = 0;
  size_t str_len = strlen(str);
  for (size_t i = 0; i < str_len; i++) {
    if ((str[i] > 47 && str[i] < 58) || str[i] == '.') {
      if_digit(str + i, tmp, num_struct);
      i += strspn(str + i, "1234567890.") - 1;
      num_struct++;
    } else {
      switch (str[i]) {
        case 'x':
          tmp[num_struct].value = x;
          tmp[num_struct].type = number;
          tmp[num_struct].priority = 0;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case '+':
          if (i == 0 || tmp[num_struct - 1].type == bracket_l) {
          } else {
            tmp[num_struct].type = plus;
            tmp[num_struct].priority = 2;
            tmp[num_struct].num = num_struct;
            num_struct++;
          }
          break;
        case '-':
          if (i == 0 || tmp[num_struct - 1].type == bracket_l) {
            tmp[num_struct].type = un_minus;
            tmp[num_struct].priority = 2;
            tmp[num_struct].num = num_struct;
            num_struct++;
          } else {
            tmp[num_struct].type = minus;
            tmp[num_struct].priority = 2;
            tmp[num_struct].num = num_struct;
            num_struct++;
          }
          break;
        case '*':
          tmp[num_struct].type = mull;
          tmp[num_struct].priority = 3;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case '/':
          tmp[num_struct].type = del;
          tmp[num_struct].priority = 3;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case '^':
          tmp[num_struct].type = scale;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'm':
          tmp[num_struct].type = mod;
          tmp[num_struct].priority = 4;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 's':
          tmp[num_struct].type = s21_sin;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'c':
          tmp[num_struct].type = s21_cos;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 't':
          tmp[num_struct].type = s21_tan;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'C':
          tmp[num_struct].type = s21_acos;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'S':
          tmp[num_struct].type = s21_asin;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'T':
          tmp[num_struct].type = s21_atan;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'q':
          tmp[num_struct].type = s21_sqrt;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'l':
          tmp[num_struct].type = s21_ln;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case 'L':
          tmp[num_struct].type = s21_log;
          tmp[num_struct].priority = 5;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case '(':
          tmp[num_struct].type = bracket_l;
          tmp[num_struct].priority = 1;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        case ')':
          tmp[num_struct].type = bracket_r;
          tmp[num_struct].priority = 6;
          tmp[num_struct].num = num_struct;
          num_struct++;
          break;
        default:
          break;
      }
    }
  }
  return 0;
}

void init_struct(s21_SmartCalc src) {
  for (int i = 0; i < SIZE; i++) {
    src[i].value = 0.0;
    src[i].priority = 0;
    src[i].type = 0;
    src[i].num = -1;
  }
}

void if_digit(char* str, s21_SmartCalc src, int n_struct) {
  double digit = atof(str);
  src[n_struct].value = digit;
  src[n_struct].priority = 0;
  src[n_struct].type = 1;
  src[n_struct].num = n_struct;
}

// void print_struct(s21_SmartCalc src, int in, int out) {
//   for (int i = in; i <= out; i++) {
//     if (i % 2 == 0)
//       printf(
//           "%sstruct № %d\nvalue = %.2f priority = %d type = %d num = "
//           "%d%s\n",
//           YELLOW, i, src[i].value, src[i].priority, src[i].type, src[i].num,
//           RESET);
//     else
//       printf(
//           "%sstruct № %d\nvalue = %.2f priority = %d type = %d num = "
//           "%d%s\n",
//           GREEN, i, src[i].value, src[i].priority, src[i].type, src[i].num,
//           RESET);
//   }
// }

// void print_struct_for_str(s21_SmartCalc src) {
//   char mod[] = "mod";
//   char sin[] = "sin";
//   char cos[] = "cos";
//   char tan[] = "tan";
//   char acos[] = "acos";
//   char asin[] = "asin";
//   char atan[] = "atan";
//   char sqrt[] = "sqrt";
//   char ln[] = "ln";
//   char log[] = "log";

//   for (int i = 0; src[i].num != -1; i++) {
//     switch (src[i].type) {
//       case 1:
//         printf("%s%.2f %s ", YELLOW, src[i].value, RESET);
//         break;
//       case 2:
//         printf("%s%c %s ", YELLOW, 'x', RESET);
//         break;
//       case 3:
//         printf("%s%c %s ", YELLOW, '+', RESET);
//         break;
//       case 4:
//         printf("%s%c %s ", YELLOW, '-', RESET);
//         break;
//       case 5:
//         printf("%s%c %s ", YELLOW, '*', RESET);
//         break;
//       case 6:
//         printf("%s%c %s ", YELLOW, '/', RESET);
//         break;
//       case 7:
//         printf("%s%c %s ", YELLOW, '^', RESET);
//         break;
//       case 8:
//         printf("%s%s %s ", YELLOW, mod, RESET);
//         break;
//       case 9:
//         printf("%s%s %s ", YELLOW, sin, RESET);
//         break;
//       case 10:
//         printf("%s%s %s ", YELLOW, cos, RESET);
//         break;
//       case 11:
//         printf("%s%s %s ", YELLOW, tan, RESET);
//         break;
//       case 12:
//         printf("%s%s %s ", YELLOW, acos, RESET);
//         break;
//       case 13:
//         printf("%s%s %s ", YELLOW, asin, RESET);
//         break;
//       case 14:
//         printf("%s%s %s ", YELLOW, atan, RESET);
//         break;
//       case 15:
//         printf("%s%s %s ", YELLOW, sqrt, RESET);
//         break;
//       case 16:
//         printf("%s%s %s ", YELLOW, ln, RESET);
//         break;
//       case 17:
//         printf("%s%s %s ", YELLOW, log, RESET);
//         break;
//       case 18:
//         printf("%s%c %s ", YELLOW, '(', RESET);
//         break;
//       case 19:
//         printf("%s%c %s ", YELLOW, ')', RESET);
//         break;
//       case 20:
//         printf("%s%c %s ", YELLOW, '~', RESET);
//         break;
//       default:
//         break;
//     }
//   }
//   printf("\n");
// }