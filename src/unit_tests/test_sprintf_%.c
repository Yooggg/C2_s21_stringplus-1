#include "test_string.h"

START_TEST(s21_sprintf_percent_1) {
  char buffer[50];
  int standard_result = sprintf(buffer, "This is a %% character");

  char s21_buffer[50];
  int s21_result = s21_sprintf(s21_buffer, "This is a %% character");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_percent_2) {
  char buffer[50];
  int standard_result = sprintf(buffer, "123%%456");

  char s21_buffer[50];
  int s21_result = s21_sprintf(s21_buffer, "123%%456");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_percent_3) {
  char buffer[50];
  int standard_result = sprintf(buffer, "This is %% a test");

  char s21_buffer[50];
  int s21_result = s21_sprintf(s21_buffer, "This is %% a test");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_percent_4) {
  char buffer[50];
  int standard_result =
      sprintf(buffer, "Two percents: %% and %%. What a surprise!");

  char s21_buffer[50];
  int s21_result =
      s21_sprintf(s21_buffer, "Two percents: %% and %%. What a surprise!");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_percent_5) {
  char buffer[50];
  int standard_result = sprintf(buffer, "This is a percent: %%");

  char s21_buffer[50];
  int s21_result = s21_sprintf(s21_buffer, "This is a percent: %%");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

Suite *sprintf_percent_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_percent");
  TCase *tc;
  tc = tcase_create("TC_sprintf_percent");
  tcase_add_test(tc, s21_sprintf_percent_1);
  tcase_add_test(tc, s21_sprintf_percent_2);
  tcase_add_test(tc, s21_sprintf_percent_3);
  tcase_add_test(tc, s21_sprintf_percent_4);
  tcase_add_test(tc, s21_sprintf_percent_5);
  suite_add_tcase(s, tc);
  return s;
}
