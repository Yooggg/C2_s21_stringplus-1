#include "test_string.h"

START_TEST(s21_sprintf_d_1) {
  char result[50];
  int value = 42;
  int standard_result = sprintf(result, "%d", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%d", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_d_2) {
  char result[50];
  int value = -123;
  int standard_result = sprintf(result, "%d", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%d", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_d_3) {
  char result[50];
  int value = 0;
  int standard_result = sprintf(result, "%d", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%d", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_d_4) {
  char result[50];
  int value = INT_MAX;
  int standard_result = sprintf(result, "%d", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%d", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_d_5) {
  char result[50];
  int value = INT_MIN;
  int standard_result = sprintf(result, "%d", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%d", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_d_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_d");
  TCase *tc;
  tc = tcase_create("TC_sprintf_d");
  tcase_add_test(tc, s21_sprintf_d_1);
  tcase_add_test(tc, s21_sprintf_d_2);
  tcase_add_test(tc, s21_sprintf_d_3);
  tcase_add_test(tc, s21_sprintf_d_4);
  tcase_add_test(tc, s21_sprintf_d_5);
  suite_add_tcase(s, tc);
  return s;
}
