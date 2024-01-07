#include <math.h>

#include "test_string.h"

// Тест-кейс 1: Указатель на обычную переменную
START_TEST(s21_sprintf_p_1) {
  char result[50];
  int value = 42;
  int *ptr = &value;
  int standard_result = sprintf(result, "%p", (void *)ptr);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%p", (void *)ptr);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 2: NULL-указатель
START_TEST(s21_sprintf_p_2) {
  char result[50];
  void *ptr = NULL;
  int standard_result = sprintf(result, "%p", ptr);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%p", ptr);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 3: Указатель на функцию
START_TEST(s21_sprintf_p_3) {
  char result[50];
  double (*func_ptr)(double, double) = pow;
  int standard_result = sprintf(result, "%p", (void *)func_ptr);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%p", (void *)func_ptr);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 4: Указатель на структуру
START_TEST(s21_sprintf_p_4) {
  char result[50];
  struct Sample {
    int x;
    char y;
  };
  struct Sample sample_instance;
  struct Sample *ptr = &sample_instance;
  int standard_result = sprintf(result, "%p", (void *)ptr);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%p", (void *)ptr);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 5: Указатель на массив
START_TEST(s21_sprintf_p_5) {
  char result[50];
  int array[5];
  int *ptr = array;
  int standard_result = sprintf(result, "%p", (void *)ptr);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%p", (void *)ptr);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_p_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_p");
  TCase *tc;
  tc = tcase_create("TC_sprintf_p");
  tcase_add_test(tc, s21_sprintf_p_1);
  tcase_add_test(tc, s21_sprintf_p_2);
  tcase_add_test(tc, s21_sprintf_p_3);
  tcase_add_test(tc, s21_sprintf_p_4);
  tcase_add_test(tc, s21_sprintf_p_5);
  suite_add_tcase(s, tc);
  return s;
}
