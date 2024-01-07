#include "test_string.h"

// Тест-кейс 1: Обычный символ
START_TEST(s21_sprintf_c_1) {
  char result[50];
  char value = 'A';
  int standard_result = sprintf(result, "%c", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%c", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 2: Спецсимвол
START_TEST(s21_sprintf_c_2) {
  char result[50];
  char value = '\t';
  int standard_result = sprintf(result, "%c", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%c", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 3: Новая строка
START_TEST(s21_sprintf_c_3) {
  char result[50];
  char value = '\n';
  int standard_result = sprintf(result, "%c", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%c", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 4: Символ с максимальным ASCII-кодом
START_TEST(s21_sprintf_c_4) {
  char result[50];
  char value = 127;
  int standard_result = sprintf(result, "%c", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%c", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 5: Символ с минимальным ASCII-кодом
START_TEST(s21_sprintf_c_5) {
  char result[50];
  char value = 0;
  int standard_result = sprintf(result, "%c", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%c", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_c_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_c");
  TCase *tc;
  tc = tcase_create("TC_sprintf_c");
  tcase_add_test(tc, s21_sprintf_c_1);
  tcase_add_test(tc, s21_sprintf_c_2);
  tcase_add_test(tc, s21_sprintf_c_3);
  tcase_add_test(tc, s21_sprintf_c_4);
  tcase_add_test(tc, s21_sprintf_c_5);
  suite_add_tcase(s, tc);
  return s;
}
