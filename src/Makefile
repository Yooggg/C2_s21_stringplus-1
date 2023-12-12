# Это фиктивные (виртуальные) цели, они не соответствуют реальным файлам
.PHONY: all s21_string.a test gcov_report clean

# Компилятор и флаги компиляции
CC=gcc
STDFLAGS= -Wall -Werror -Wextra -std=c11
GCOV_FLAGS= -fprofile-arcs -ftest-coverage
UBUNTU_FLAGS= -lsubunit -lrt -lpthread -lm
LIBS= -lcheck
LDFLAGS= -L/usr/local/lib -I/usr/local/include

# Определение операционной системы
OS=$(shell uname -s)

# Список исходных файлов для s21_string
SRC=$(wildcard s21_*.c)
# Список объектных файлов
OBJ=$(patsubst %.c,%.o, $(SRC)) 
# Список всех файлов исходного кода
ALL_C_SL=$(SRC)

# Папка с тестовыми файлами
TEST_C_DIR=./unit_tests/
# Список тестовых файлов для s21_string 
TEST_SRC=$(wildcard $(TEST_C_DIR)/test_*.c)
# Список всех тестовых файлов
ALL_C_TEST=$(TEST_C_DIR)all_tests_s21.c $(TEST_SRC)

# Основная цель для сборки всего проекта
all: gcov_report test s21_string.a

# Цель для сборки статической библиотеки s21_string.a
s21_string.a: $(SRC)
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc s21_string.a $(OBJ)


# Цель для компиляции и выполнения тестов
test: s21_string.a
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(LDFLAGS) $(ALL_C_TEST) -o all_tests_s21 $(LIBS) s21_string.a
 else
	$(CC) $(STDFLAGS) $(LDFLAGS) $(ALL_C_TEST) -o all_tests_s21 $(LIBS) $(UBUNTU_FLAGS) s21_string.a
endif
	./all_tests_s21

# Цель для создания отчетов по покрытию кода
gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(LDFLAGS) $(GCOV_FLAGS) $(ALL_C_SL) $(ALL_C_TEST) -o all_tests_s21 $(LIBS)
 else # Флаги для GNU
	$(CC) $(STDFLAGS) $(LDFLAGS) $(GCOV_FLAGS) $(ALL_C_SL) $(ALL_C_TEST) -o all_tests_s21 $(LIBS) $(UBUNTU_FLAGS)
endif 
	./all_tests_s21
	mkdir -p unit_tests
	mv *.gc* unit_tests
	lcov -o ./unit_tests/all_tests_s21.info -c -d unit_tests
	genhtml -o test_report ./unit_tests/all_tests_s21.info
	open ./test_report/index.html




rebuild: clean all

# Цель для очистки всех временных файлов и сгенерированных отчетов

clean:
	rm -f all_tests_s21 *.o *.a *.gcno *.gcda unit_tests/*.gc* unit_tests/*.info
	rm -rf test_report/
	rm -f s21_*.gcda s21_*.gcno
