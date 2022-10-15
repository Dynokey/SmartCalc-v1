CC = gcc 
FLAGS_ER = -Wall -Wextra -Werror -std=c11 -pedantic -fsanitize=address
FLAGS_GRIND = -Wall -Wextra -Werror -std=c11 -pedantic
FLAGS_COV = -fprofile-arcs -ftest-coverage -lm -lpthread
FLAGS_CHECK = -lcheck -lgcov

VAR = $(shell pkg-config --cflags --libs check)
SRC = $(wildcard *.c)
# SRC = $(calc.c credit_calc_ann.c credit_calc_diff.c my_main.c notation.c parser.c validator.c s21_SmartCalc.h)
OBJ = $(SRC:.c=.o)
OBJT = $(OBJ) ./test/test_SmartCalc.c
TARGET_H = s21_SmartCalc.h

.PHONY: all
all: s21_SmartCalc 

.PHONY: s21_SmartCalc
s21_SmartCalc: $(SRC)
	$(CC) $(FLAGS_GRIND) $(SRC) $(TARGET_H) -o s21_SmartCalc.o
	./s21_SmartCalc.o
	@rm -rf *.o

.PHONY: clean
clean:
	@rm -rf *.o
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
	@rm -rf report


.PHONY: test clean
test: $(OBJT)
	$(CC) $(FLAGS_ER) $(OBJ) $(VAR) ./test/test_SmartCalc.c -o test_Smart
	./test_Smart

gcov_report: clean
	$(CC) -o test_Smart $(SRC) ./test/test_SmartCalc.c  $(VAR) $(FLAGS_COV) $(FLAGS_CHECK)
	./test_Smart
	lcov -t "gcov_report" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html
	rm -rf *.gcno
	rm -rf *.gcda


# VAR = $(shell pkg-config --cflags --libs check) # for check.ru in Galaxy
# SRC = $(wildcard *.c)

# TARGET = qt/calc/calc.app/Contents/MacOS/calc
# TARGET_H = s21_SmartCalc.h

# FLAGS_ER = -Wall -Wextra -Werror -std=c11 -pedantic -fsanitize=address
# FLAGS_GRIND = -Wall -Wextra -Werror -std=c11 -pedantic
# FLAGS_COV = -lcheck -lgcov -fprofile-arcs --coverage
# FLAGS_CHECK = -lcheck -lgcov

# TMP_FILES = *.gcda *.gcno gcov_report.info *.gcda obj/*.gcno obj/*.gcda
# REST_FILES = $(TARGET) report obj/*.o ./test test.dSYM _valgrind-out.txt
# QT_TMP = qt/calc/calc_autogen qt/calc/CMakeFiles qt/calc/cmake_install.cmake qt/calc/CMakeCache.txt qt/calc/Makefile
# QT_APP = qt/calc/calc.app
# QT_BUILD = qt/calc/build-calc-Desktop_x86_darwin_generic_mach_o_64bit-Release
# TAR = calc.tar.gz
# DOCS = doxygen/html doxygen/latex

# .PHONY: all
# all: $(OBJ) install ## install and run program
# 	$(TARGET)

# .PHONY: install
# install: ## generate Makefile from cmake and run it to create executable
# 	cd qt/calc && cmake . && $(MAKE) all

# .PHONY: uninstall
# uninstall: ## remove files: cmake generated
# 	rm -rf $(QT_TMP)

# .PHONY: clean
# clean: uninstall ## remove files: cmake generated, check.h temporary files
# 	rm -rf $(TMP_FILES)

# .PHONY: fclean
# fclean: clean ## remove files: cmake generated, check.h temporary files, executables, dists, docs
# 	rm -rf $(QT_APP) $(TAR) $(DOCS) $(REST_FILES) $(QT_BUILD)

# .PHONY: dvi
# dvi: ## generate and open doc
# 	cd doxygen && ./doxygen Doxyfile && open html/index.html

# .PHONY: dist
# dist: install ## archive executable
# 	tar -zcf $(TAR) $(TARGET)

# obj/%.o: %.c ## generate .o files
# 	gcc $(FLAGS_ER) $(FLAGS_COV) -c $< -o $@


# .PHONY: gcov_report ## generate and open gcov report with coverage
# gcov_report: fclean $(OBJ)
# 	gcc $(OBJ) tests/*.c $(FLAGS_ER) $(FLAGS_CHECK) -o test
# 	gcc -o test $(OBJ) tests/*.c $(FLAGS_ER) $(FLAGS_CHECK)
# 	./test
# 	lcov -t "gcov_report" -o gcov_report.info -c -d ./obj
# 	genhtml -o report gcov_report.info;
# 	$(MAKE) clean
# 	open report/index.html

# .PHONY: lint ## run linters
# lint: $(OBJ)
# 	cp ../materials/linters/CPPLINT.cfg ./
# 	python3 ../materials/linters/cpplint.py --extensions=c *.c
# 	python3 ../materials/linters/cpplint.py --extensions=h $(TARGET_H)
# 	rm -rf ./CPPLINT.cfg
# 	cppcheck --enable=all --suppress=missingIncludeSystem *.c

# .PHONY: grind ## run valgrind
# grind: FLAGS_ER = $(FLAGS_GRIND)
# grind: $(OBJ)
# 	gcc $(OBJ) tests/*.c $(FLAGS_CHECK) -o test
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=_valgrind-out.txt ./test
# 	$(MAKE) clean

# .PHONY: leaks ## run leaks
# leaks: FLAGS_ER = $(FLAGS_GRIND)
# leaks: tests
# 	leaks --atExit -- ./test
# 	$(MAKE) clean
