#include "s21_SmartCalc.h"

int notation(s21_SmartCalc src, s21_SmartCalc data){
    int count_data = 0;
    int count_stack = 0;
   
    s21_SmartCalc stack;
    init_struct(stack);

    for(int i = 0; src[i].num != -1; i++){

        // если встречаем унарный минус, то кладем в выходную строку велью 0.0, унарный минус меняем на обычный минус
        if((src[i].type == un_minus && src[i - 1].type == bracket_l)){
            data[count_data].num = count_data;
            data[count_data].type = number;
            data[count_data].priority = 0;
            data[count_data].value = 0.0;
            count_data++;
            src[i].type = minus;
        }
        if(src[i].priority == 0){          // если число, сразу кладем в выходную строку
            data[count_data] = src[i];
            data[count_data].num = count_data;
            count_data++;
        } else if(src[i].priority != 0 && count_stack == 0){ 
            stack[count_stack] = src[i];   // иначе, если не число и стек пустой, то кладем оператор в стек
            stack[count_stack].num = count_stack;
            count_stack++;
        } else if((src[i].priority > stack[count_stack - 1].priority) && src[i].type != 19){
            stack[count_stack] = src[i];  // иначе, если приоритет входящего операнда выше, чем приоритет операнда
            stack[count_stack].num = count_stack; // на вершине стека, то кладем его в стек
            count_stack++;
        } else if(src[i].type == 18){     // если встретили '(' кладем в стек
            stack[count_stack] = src[i];
            stack[count_stack].num = count_stack;
            count_stack++;
        } else if(src[i].type == 19){     // если встретили ')' то опускаемся в цикле по стеку до '(' 
            count_stack--;                // выталкивая все в выходную строку
            while(stack[count_stack].type != 18){
                data[count_data] = stack[count_stack];
                data[count_data].num = count_data;
                stack[count_stack].value = 0;
                stack[count_stack].priority = 0;
                stack[count_stack].type = 0;
                stack[count_stack].num = -1;
                count_data++;
                count_stack--;
            }
            stack[count_stack].num = count_stack; 
            stack[count_stack].priority = 0;
            stack[count_stack].type = 0;
            stack[count_stack].value = 0;
        }  
        else {
            count_stack--;
            for(int j = count_stack; j >= 0 && (src[i].priority <= stack[count_stack].priority) && stack[count_stack].type != 18; j--){
                data[count_data] = stack[count_stack]; // спускаемся по стеку и выталкиваем в строку операнды пока приоритет входящего
                data[count_data].num = count_data;     // операнда меньше или равен приоритету операнда на вершине стека
                count_data++;

                stack[count_stack].value = 0;
                stack[count_stack].priority = 0;
                stack[count_stack].type = 0;
                stack[count_stack].num = -1;

                if(count_stack > 0 && src[i].priority <= stack[count_stack - 1].priority) 
                    count_stack--;
            }

            if(src[i].type != 18 && src[i].type != 19){
            stack[count_stack] = src[i];
            stack[count_stack].num = count_stack;
            count_stack++;
            }
        }
    }

    if(count_stack > 0){  // прочитав все значения из входящей строки выталкиваем все операнды из стека
        for(int i = count_stack - 1; i >= 0; i--){
            if(count_stack > 0) 
                count_stack--;
            data[count_data] = stack[count_stack];
            data[count_data].num = count_data;
            count_data++;
        }
    }
    return 0;
}