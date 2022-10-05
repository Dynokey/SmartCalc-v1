CC = gcc 
GFLAGS = -Wall -Werror -Wextra  #-g -fsanitize=address
src = credit_calc_ann.c credit_calc_diff.c new_main.c notation.c validator.c calc.c my_main.c parser.c s21_SmartCalc.h

all: s21_SmartCalc 

s21_SmartCalc: clean $(src)
	$(CC) $(GFLAGS) $(src) -o s21_SmartCalc.o
	./s21_SmartCalc.o
	@rm -rf *.o

clean:
	rm -rf *.o