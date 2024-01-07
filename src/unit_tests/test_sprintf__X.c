#include "test_string.h"

// Тест-кейс 1: Обычное положительное целое число
START_TEST(s21_sprintf_X_1) {
  char result[50];
  unsigned int value = 42;
  int standard_result = sprintf(result, "%X", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%X", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 2: Ноль
START_TEST(s21_sprintf_X_2) {
  char result[50];
  unsigned int value = 0;
  int standard_result = sprintf(result, "%X", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%X", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 3: Максимальное значение для unsigned int
START_TEST(s21_sprintf_X_3) {
  char result[50];
  unsigned int value = UINT_MAX;
  int standard_result = sprintf(result, "%X", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%X", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 4: Случай, когда значение представляется буквами
START_TEST(s21_sprintf_X_4) {
  char result[50];
  unsigned int value = 12345;
  int standard_result = sprintf(result, "%X", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%X", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 5: Случай, когда значение представляется спецсимволами
START_TEST(s21_sprintf_X_5) {
  char result[50];
  unsigned int value = 42;
  int standard_result = sprintf(result, "%X", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%X", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_X_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_X");
  TCase *tc;
  tc = tcase_create("TC_sprintf_X");
  tcase_add_test(tc, s21_sprintf_X_1);
  tcase_add_test(tc, s21_sprintf_X_2);
  tcase_add_test(tc, s21_sprintf_X_3);
  tcase_add_test(tc, s21_sprintf_X_4);
  tcase_add_test(tc, s21_sprintf_X_5);
  suite_add_tcase(s, tc);
  return s;
}
