#include "test_string.h"

// Тест-кейс 1
START_TEST(s21_sprintf_width_1) {
  char buffer[100];
  int standard_result = sprintf(buffer, "%5d", 42);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "%5d", 42);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

// Тест-кейс 2
START_TEST(s21_sprintf_width_2) {
  char buffer[100];
  int standard_result = sprintf(buffer, "%-8d", 123);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "%-8d", 123);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

// Тест-кейс 3
START_TEST(s21_sprintf_width_3) {
  char buffer[100];
  int standard_result = sprintf(buffer, "%10s", "Hello");

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "%10s", "Hello");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

// Тест-кейс 4
START_TEST(s21_sprintf_width_4) {
  char buffer[100];
  int standard_result = sprintf(buffer, "%-15.2f", 3.14);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "%-15.2f", 3.14);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

// Тест-кейс 5
START_TEST(s21_sprintf_width_5) {
  char buffer[100];
  int standard_result = sprintf(buffer, "%*c", 8, 'A');

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "%*c", 8, 'A');

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

Suite *sprintf_width_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_width");
  TCase *tc;
  tc = tcase_create("TC_sprintf_width");
  tcase_add_test(tc, s21_sprintf_width_1);
  tcase_add_test(tc, s21_sprintf_width_2);
  tcase_add_test(tc, s21_sprintf_width_3);
  tcase_add_test(tc, s21_sprintf_width_4);
  tcase_add_test(tc, s21_sprintf_width_5);

  suite_add_tcase(s, tc);
  return s;
}
