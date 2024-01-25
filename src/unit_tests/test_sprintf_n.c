#include "test_string.h"

START_TEST(s21_sprintf_n_1) {
  char buffer[50];
  int standard_result;
  int value = 42;
  int standard_chars_written =
      sprintf(buffer, "The answer is %d%n", value, &standard_result);

  char s21_buffer[50];
  int s21_result;
  int s21_chars_written =
      s21_sprintf(s21_buffer, "The answer is %d%n", value, &s21_result);

  ck_assert_int_eq(s21_chars_written, standard_chars_written);
  ck_assert_int_eq(s21_result, standard_result);
}
END_TEST

START_TEST(s21_sprintf_n_2) {
  char buffer[50];
  int standard_result;
  int standard_chars_written = sprintf(buffer, "%n", &standard_result);
  standard_result = standard_chars_written;

  char s21_buffer[50];
  int s21_chars_written;
  int s21_result = 0;
  s21_chars_written = s21_sprintf(s21_buffer, "%n", &s21_result);

  ck_assert_int_eq(s21_chars_written, standard_chars_written);
  ck_assert_int_eq(s21_result, standard_result);
}
END_TEST

START_TEST(s21_sprintf_n_3) {
  char buffer[50];
  int standard_result;
  int standard_chars_written = sprintf(buffer, "Value: %n", &standard_result);
  standard_result = standard_chars_written;

  char s21_buffer[50];
  int s21_chars_written;
  int s21_result = 0;  // Не должно влиять на результат
  s21_chars_written = s21_sprintf(s21_buffer, "Value: %n", &s21_result);

  ck_assert_int_eq(s21_chars_written, standard_chars_written);
  ck_assert_int_eq(s21_result, standard_result);
}
END_TEST

START_TEST(s21_sprintf_n_5) {
  char buffer[50];
  int value = 987;
  int standard_result;
  int standard_chars_written = sprintf(buffer, "Value: %d", value);
  standard_result = standard_chars_written;

  char s21_buffer[50];
  int s21_chars_written;
  int s21_result = 0;
  s21_chars_written =
      s21_sprintf(s21_buffer, "Value: %d%n", value, &s21_result);

  ck_assert_int_eq(s21_chars_written, standard_chars_written);
  ck_assert_int_eq(s21_result, standard_result);
}
END_TEST

Suite *sprintf_n_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_n");
  TCase *tc;
  tc = tcase_create("TC_sprintf_n");
  tcase_add_test(tc, s21_sprintf_n_1);
  tcase_add_test(tc, s21_sprintf_n_2);
  tcase_add_test(tc, s21_sprintf_n_3);
  tcase_add_test(tc, s21_sprintf_n_5);
  suite_add_tcase(s, tc);
  return s;
}
