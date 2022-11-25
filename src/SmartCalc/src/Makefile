CC = gcc 
FLAGS_ER = -Wall -Wextra -Werror -std=c11 -pedantic -fsanitize=address
FLAGS_GRIND = -Wall -Wextra -Werror -std=c11 -pedantic
FLAGS_COV = -fprofile-arcs -ftest-coverage -lm -lpthread
FLAGS_CHECK = -lcheck -lgcov

VAR = $(shell pkg-config --cflags --libs check)
SRC = $(wildcard *.c)
SRC_T = calc.c credit_calc_ann.c credit_calc_diff.c my_main.c notation.c parser.c validator.c deposit_calc.c
OBJ = $(SRC_T:.c=.o)
OBJT = $(OBJ) ./test/test_SmartCalc.c
TARGET_H = s21_SmartCalc.h

.PHONY: all
all: install run

.PHONY: libs
libs: $(SRC)
	$(CC) $(FLAGS_GRIND) $(SRC) $(TARGET_H) -o libs.o
	ar rcs libs.a libs.o
	ranlib libs.a
	@rm -rf *.o

.PHONY: full_clean
full_clean: clean
	@rm -rf *.o

.PHONY: clean
clean:
	@rm -rf *.out
	@rm -rf *.dSYM
	@rm -rf *.gcno
	@rm -rf *.gcda
	@rm -rf *.info
	@rm -rf *.a
	@rm -rf *.log
	@rm -rf test_Smart
	@rm -rf CPPLINT.cfg
	@rm -rf cpplint.py
	@rm -rf report.*
	@rm -rf *.css
	@rm -rf index.html
	@rm -rf *.gcov
	@rm -rf *.gch
	@rm -rf SmartCalc.tar.gz
	@rm -rf ../build/CMakeCache.txt
	@rm -rf ./report
	@rm -rf .clang-format

.PHONY: test clean
test: $(OBJT)
	$(CC) $(FLAGS_ER) $(OBJ) $(VAR) ./test/test_SmartCalc.c -o test_Smart
	./test_Smart

gcov_report: clean
	$(CC) -o test_Smart $(SRC_T) ./test/test_SmartCalc.c  $(VAR) $(FLAGS_COV) $(FLAGS_CHECK)
	./test_Smart
	lcov -t "gcov_report" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html
	rm -rf *.gcno
	rm -rf *.gcda

install: clean
	cd ../ && cmake . && $(MAKE) all

uninstall:
	@rm -rf ../SmartCalc.app
	@rm -rf ../CMakeCache.txt
	@rm -rf ../CMakeFiles/
	@rm -rf ../Makefile
	@rm -rf ../SmartCalc_autogen/
	@rm -rf ../cmake_install.cmake

run:
	open ../SmartCalc.app

dist: 
	@mkdir SmartCalcDist
	cp *.c SmartCalcDist
	cp *.h SmartCalcDist
	cp ../CMakeLists.txt.user SmartCalcDist
	cp ../*.cpp SmartCalcDist
	cp ../*.ui SmartCalcDist
	cp Makefile SmartCalcDist
	tar -czf SmartCalc.tar.gz SmartCalcDist/
	rm -rf SmartCalcDist

# generatedvi:
# 	cd ../doxygen && ./doxygen Doxyfile

dvi:
	open ../doxygen/html/index.html

check: 
	cp ../../../materials/linters/.clang-format .clang-format
	clang-format -n *.c   *.h
	clang-format -n ../*.cpp  *.h
