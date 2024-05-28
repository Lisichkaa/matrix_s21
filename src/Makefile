CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

FILES = s21_matrix.c

FILE_TESTS = $(wildcard tests/*.c)
TARGET=s21_matrix.a

OS := $(shell uname -s)
TEST_FLAGS = -lcheck

ifeq ($(OS), Linux)
TEST_FLAGS =  -lcheck -lm -lsubunit
endif

TESTS = $(wildcard tests/*.c)
TESTS_OBJ = $(TESTS:.c=.o)

all: gcov_report

$(TARGET): 
	$(CC) ${CFLAGS} -c ${FILES}
	ar rc libs21_matrix.a s21*.o
	ranlib libs21_matrix.a
	cp libs21_matrix.a s21_matrix.a

test: $(TESTS_OBJ) $(TARGET)
	$(CC)  ${CFLAGS} ${FILES} ${TESTS_OBJ} ${TEST_FLAGS} -o s21_matrix --coverage
	@echo "---------------------------TESTS--------------------------------------" 
	./s21_matrix
	@echo "----------------------------------------------------------------------"

test%.o: test%.c
	$(CC) -std=c11 -c $< $(TEST_FLAGS) -o $@

gcov_report: test 
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	open ./report/src/index.html

clean:
	rm -rf s21_matrix
	rm -rf ./tests/*.o
	rm -rf *.out
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gch
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -rf test
	rm -rf gcov_test
	rm -rf test report

