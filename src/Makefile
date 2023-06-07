CC=gcc
COMLFAGS=-Wall -Werror -Wextra -std=c11 -pedantic 
TFLAGS=-o testing -lcheck --coverage 
ifeq ($(shell uname), Linux)
	TFLAGS += -lm -lsubunit
endif

ifeq ($(shell uname), Darwin)
 TFLAGS += -fprofile-arcs -ftest-coverage
endif

all: s21_math.a test gcov_report 

.PHONY: all clean rebuild format test gcov_report

rebuild: clean format build test 

s21_math.a:
	$(CC) $(COMLFAGS) -c *.c
	ar -rc s21_math.a *.o

test: s21_math.a
	@checkmk clean_mode=1  math.check > testing.c
	@$(CC) *.c s21_math.a $(TFLAGS)
	./testing

gcov_report:
	@gcov -b *.c 
	@lcov -d . -c -o coverage.info
	@genhtml -o html_report coverage.info
	@open html_report/index.html

clean:
	@rm -rf *.o testing.c testing *.a *.gcno *.gcda *.gcov *.info
	@rm -rf html_report

format_check:
	find . -type f -name "*.c" -exec clang-format --style=Google -n {} \;
	find . -type f -name "*.h" -exec clang-format --style=Google -n {} \;

format:
	@find . -type f -name "*.c" -exec clang-format --style=Google -i {} \;
	@find . -type f -name "*.h" -exec clang-format --style=Google -i {} \;